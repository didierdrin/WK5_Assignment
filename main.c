#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int login(char usernames[][20], char pins[][5], double balances[], int *current_user);
void display_menu();
int get_choice();
void check_balance(double balance);
void deposit(double *balance, char transactions[][100], int *trans_count);
void withdraw(double *balance, char transactions[][100], int *trans_count);
void view_transactions(char transactions[][100], int trans_count, char username[]);
void log_transaction(char transactions[][100], int *trans_count, char *type, double amount, double balance);
int validate_pin(char *pin);
void clear_input_buffer();

int main() {
    // Initialize user data arrays
    char usernames[5][20] = {"alice", "bob", "charlie", "dave", "eve"};
    char pins[5][5] = {"1234", "5678", "9012", "3456", "7890"};
    double balances[5] = {1000.00, 500.00, 2000.00, 1500.00, 3000.00};
    char transactions[5][10][100]; // 5 users, 10 transactions each
    int trans_counts[5] = {0, 0, 0, 0, 0};
    
    int current_user = -1;
    
    printf("Welcome to ALU ATM System\n");
    
    // Login loop
    while (current_user == -1) {
        if (!login(usernames, pins, balances, &current_user)) {
            printf("Login failed. Please try again.\n");
        }
    }
    
    // Main menu loop
    while (1) {
        display_menu();
        int choice = get_choice();
        
        switch (choice) {
            case 1:
                check_balance(balances[current_user]);
                break;
            case 2:
                deposit(&balances[current_user], transactions[current_user], &trans_counts[current_user]);
                break;
            case 3:
                withdraw(&balances[current_user], transactions[current_user], &trans_counts[current_user]);
                break;
            case 4:
                view_transactions(transactions[current_user], trans_counts[current_user], usernames[current_user]);
                break;
            case 5:
                printf("Thank you for using ALU ATM. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select (1-5).\n");
        }
    }
    
    return 0;
}

// Login function
int login(char usernames[][20], char pins[][5], double balances[], int *current_user) {
    char username[20];
    char pin[5];
    
    printf("\nEnter username: ");
    scanf("%s", username);
    clear_input_buffer();
    
    printf("Enter 4-digit PIN: ");
    scanf("%s", pin);
    clear_input_buffer();
    
    if (!validate_pin(pin)) {
        printf("Invalid PIN format. Must be 4 digits.\n");
        return 0;
    }
    
    for (int i = 0; i < 5; i++) {
        if (strcmp(usernames[i], username) == 0 && strcmp(pins[i], pin) == 0) {
            *current_user = i;
            printf("Login successful! Welcome, %s.\n", username);
            return 1;
        }
    }
    
    return 0;
}
