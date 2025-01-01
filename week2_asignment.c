#include <stdio.h>

unsigned long long exponentiation_by_squaring(unsigned long long int base, unsigned long long int exp, unsigned long long mod) {
    unsigned long long result = 1;

    base = base % mod; // Reduce the large number to a small number

    while (exp != 0) {
        if (exp % 2 != 0) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    unsigned long long base, exponent, modulus, result;

    
    printf("Enter Base (positive integer): ");
    scanf("%llu", &base);
    
    printf("Enter Exponent (non-negative integer): ");
    scanf("%llu", &exponent);
    
    printf("Enter Modulus (integer >= 2): ");
    scanf("%llu", &modulus);

    // Validate inputs
    if (base < 1) {
        printf("Invalid input for base. It should be a positive integer.\n");
        return 1;
    }
    
    if (exponent < 0) {
        printf("Invalid input for exponent. It should be a non-negative integer.\n");
        return 1;
    }

    if (modulus < 2) {
        printf("Invalid input for modulus. It should be >= 2.\n");
        return 1;
    }


    result = exponentiation_by_squaring(base, exponent, modulus);

    printf("Result: %llu\n", result);

    return 0;
}
