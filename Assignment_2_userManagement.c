#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    int userID;
    char fullName[MAX_NAME_LENGTH];
    int userAge;
} User;

const char *DATA_FILE = "users.txt";

// Function declarations
void ensureFileExists();
void createUser();
void listUsers();
void updateUser();
void deleteUser();

int main() {
    int option;

    ensureFileExists(); // Check if the file exists or create it

    while (1) {
        printf("\n=== User Management System ===\n");
        printf("1. Add a New User\n");
        printf("2. View All Users\n");
        printf("3. Update User Information\n");
        printf("4. Delete a User\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: createUser(); break;
            case 2: listUsers(); break;
            case 3: updateUser(); break;
            case 4: deleteUser(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

// Ensure the data file exists
void ensureFileExists() {
    FILE *file = fopen(DATA_FILE, "a");
    if (file == NULL) {
        perror("Failed to create or access the data file");
        exit(1);
    }
    fclose(file);
}

// Add a new user to the file
void createUser() {
    FILE *file = fopen(DATA_FILE, "a");
    if (file == NULL) {
        perror("Unable to open the data file for writing");
        return;
    }

    User newUser;
    printf("Enter User ID: ");
    scanf("%d", &newUser.userID);
    printf("Enter Full Name: ");
    getchar(); // Clear newline character
    fgets(newUser.fullName, MAX_NAME_LENGTH, stdin);
    newUser.fullName[strcspn(newUser.fullName, "\n")] = '\0'; // Remove trailing newline
    printf("Enter Age: ");
    scanf("%d", &newUser.userAge);

    fprintf(file, "%d,%s,%d\n", newUser.userID, newUser.fullName, newUser.userAge);
    fclose(file);

    printf("New user added successfully.\n");
}

// Display all users from the file
void listUsers() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        perror("Unable to open the data file for reading");
        return;
    }

    User user;
    printf("\n--- User List ---\n");
    printf("ID\tName\t\tAge\n");
    printf("-----------------------------\n");

    while (fscanf(file, "%d,%99[^,],%d\n", &user.userID, user.fullName, &user.userAge) == 3) {
        printf("%d\t%-15s\t%d\n", user.userID, user.fullName, user.userAge);
    }
    fclose(file);
}

// Update a user's information
void updateUser() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        perror("Unable to open the data file for reading");
        return;
    }

    int idToUpdate, found = 0;
    User user;

    printf("Enter the ID of the user to update: ");
    scanf("%d", &idToUpdate);

    FILE *tempFile = fopen("temp_users.txt", "w");
    if (tempFile == NULL) {
        perror("Failed to create a temporary file");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d,%99[^,],%d\n", &user.userID, user.fullName, &user.userAge) == 3) {
        if (user.userID == idToUpdate) {
            found = 1;
            printf("Enter new name: ");
            getchar(); // Clear newline
            fgets(user.fullName, MAX_NAME_LENGTH, stdin);
            user.fullName[strcspn(user.fullName, "\n")] = '\0';
            printf("Enter new age: ");
            scanf("%d", &user.userAge);
        }
        fprintf(tempFile, "%d,%s,%d\n", user.userID, user.fullName, user.userAge);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(DATA_FILE);
        rename("temp_users.txt", DATA_FILE);
        printf("User information updated successfully.\n");
    } else {
        remove("temp_users.txt");
        printf("User with ID %d not found.\n", idToUpdate);
    }
}

// Delete a user by their ID
void deleteUser() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        perror("Unable to open the data file for reading");
        return;
    }

    int idToDelete, isRemoved = 0;
    User user;

    printf("Enter the ID of the user to delete: ");
    scanf("%d", &idToDelete);

    FILE *tempFile = fopen("temp_users.txt", "w");
    if (tempFile == NULL) {
        perror("Failed to create a temporary file");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d,%99[^,],%d\n", &user.userID, user.fullName, &user.userAge) == 3) {
        if (user.userID != idToDelete) {
            fprintf(tempFile, "%d,%s,%d\n", user.userID, user.fullName, user.userAge);
        } else {
            isRemoved = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (isRemoved) {
        remove(DATA_FILE);
        rename("temp_users.txt", DATA_FILE);
        printf("User removed successfully.\n");
    } else {
        remove("temp_users.txt");
        printf("No user found with ID %d.\n", idToDelete);
    }
}

