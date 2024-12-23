#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    int userId;
    char fullName[MAX_NAME_LENGTH];
    int userAge;
} User;

const char *dataFile = "users.txt";

// Function declarations
void ensureFileExists();
void createUser();
void listUsers();
void updateUser();
void deleteUser();

int main() {
    int option;
    char inputBuffer[50]; // Buffer for safe input handling

    ensureFileExists(); // Ensure the data file exists

    do {
        printf("\n=== User Management System ===\n");
        printf("1. Add a New User\n");
        printf("2. View All Users\n");
        printf("3. Update User Information\n");
        printf("4. Delete a User\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        // Read input and validate
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL || sscanf(inputBuffer, "%d", &option) != 1) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            continue;
        }

        switch (option) {
            case 1:
                createUser();
                break;
            case 2:
                listUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please enter a number between 1 and 5.\n");
        }
    } while (option != 5);

    return 0;
}

// Ensure the data file exists
void ensureFileExists() {
    FILE *file = fopen(dataFile, "a");
    if (file == NULL) {
        perror("Failed to create or access the data file");
        exit(1);
    }
    fclose(file);
}

// Add a new user to the file
void createUser() {
    FILE *file = fopen(dataFile, "a");
    if (file == NULL) {
        perror("Unable to open the data file for writing");
        return;
    }

    User newUser;
    char inputBuffer[50]; // Buffer for safe input handling

    printf("Enter User ID: ");
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL || sscanf(inputBuffer, "%d", &newUser.userId) != 1) {
        printf("Invalid input! User ID must be a number.\n");
        fclose(file);
        return;
    }

    printf("Enter Full Name: ");
    if (fgets(newUser.fullName, MAX_NAME_LENGTH, stdin) == NULL) {
        printf("Invalid input! Name must be a string.\n");
        fclose(file);
        return;
    }
    newUser.fullName[strcspn(newUser.fullName, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Age: ");
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL || sscanf(inputBuffer, "%d", &newUser.userAge) != 1) {
        printf("Invalid input! Age must be a number.\n");
        fclose(file);
        return;
    }

    fprintf(file, "%d,%s,%d\n", newUser.userId, newUser.fullName, newUser.userAge);
    fclose(file);

    printf("New user added successfully.\n");
}

// Display all users from the file
void listUsers() {
    FILE *file = fopen(dataFile, "r");
    if (file == NULL) {
        perror("Unable to open the data file for reading");
        return;
    }

    User user;
    printf("\n--- User List ---\n");
    printf("ID\tName\t\tAge\n");
    printf("-----------------------------\n");

    while (fscanf(file, "%d,%99[^,],%d\n", &user.userId, user.fullName, &user.userAge) == 3) {
        printf("%d\t%-15s\t%d\n", user.userId, user.fullName, user.userAge);
    }
    fclose(file);
}

// Update a user's information
void updateUser() {
    FILE *file = fopen(dataFile, "r");
    if (file == NULL) {
        perror("Unable to open the data file for reading");
        return;
    }

    int idToUpdate, found = 0;
    User user;
    char inputBuffer[50]; // Buffer for safe input handling

    printf("Enter the ID of the user to update: ");
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL || sscanf(inputBuffer, "%d", &idToUpdate) != 1) {
        printf("Invalid input! User ID must be a number.\n");
        fclose(file);
        return;
    }

    FILE *tempFile = fopen("temp_users.txt", "w");
    if (tempFile == NULL) {
        perror("Failed to create a temporary file");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d,%99[^,],%d\n", &user.userId, user.fullName, &user.userAge) == 3) {
        if (user.userId == idToUpdate) {
            found = 1;
            printf("Enter new name: ");
            if (fgets(user.fullName, MAX_NAME_LENGTH, stdin) == NULL) {
                printf("Invalid input! Name must be a string.\n");
                break;
            }
            user.fullName[strcspn(user.fullName, "\n")] = '\0';

            printf("Enter new age: ");
            if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL || sscanf(inputBuffer, "%d", &user.userAge) != 1) {
                printf("Invalid input! Age must be a number.\n");
                break;
            }
        }
        fprintf(tempFile, "%d,%s,%d\n", user.userId, user.fullName, user.userAge);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(dataFile);
        rename("temp_users.txt", dataFile);
        printf("User information updated successfully.\n");
    } else {
        remove("temp_users.txt");
        printf("User with ID %d not found.\n", idToUpdate);
    }
}

// Delete a user by their ID
void deleteUser() {
    FILE *file = fopen(dataFile, "r");
    if (file == NULL) {
        perror("Unable to open the data file for reading");
        return;
    }

    int idToDelete, isRemoved = 0;
    User user;
    char inputBuffer[50]; // Buffer for safe input handling

    printf("Enter the ID of the user to delete: ");
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL || sscanf(inputBuffer, "%d", &idToDelete) != 1) {
        printf("Invalid input! User ID must be a number.\n");
        fclose(file);
        return;
    }

    FILE *tempFile = fopen("temp_users.txt", "w");
    if (tempFile == NULL) {
        perror("Failed to create a temporary file");
        fclose(file);
        return;
    }

    while (fscanf(file, "%d,%99[^,],%d\n", &user.userId, user.fullName, &user.userAge) == 3) {
        if (user.userId != idToDelete) {
            fprintf(tempFile, "%d,%s,%d\n", user.userId, user.fullName, user.userAge);
        } else {
            isRemoved = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (isRemoved) {
        remove(dataFile);
        rename("temp_users.txt", dataFile);
        printf("User removed successfully.\n");
    } else {
        remove("temp_users.txt");
        printf("No user found with ID %d.\n", idToDelete);
    }
}
