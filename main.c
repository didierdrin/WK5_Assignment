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
    char usernames[5][20] = {"kevin", "ruto", "charlie", "dave", "lizzo"};
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

// Display ATM menu
void display_menu() {
    printf("\n*** ALU ATM MENU ***\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Transaction History\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

// Get and validate user choice
int get_choice() {
    int choice;
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number (1-5): ");
        clear_input_buffer();
    }
    clear_input_buffer();
    return choice;
}

// Check balance
void check_balance(double balance) {
    printf("Your current balance is: RWF %.2f\n", balance);
}

// Deposit money
void deposit(double *balance, char transactions[][100], int *trans_count) {
    double amount;
    printf("Enter amount to deposit (RWF): ");
    while (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("INVALID: Deposit amount must be above 0. Try again: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    
    *balance += amount;
    log_transaction(transactions, trans_count, "Deposit", amount, *balance);
    printf("Successfully deposited RWF %.2f\nNew balance: RWF %.2f\n", amount, *balance);
}

// Withdraw money
void withdraw(double *balance, char transactions[][100], int *trans_count) {
    double amount;
    printf("Enter amount to withdraw (RWF): ");
    while (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("INVALID: Withdraw amount must be above 0. Try again: ");
        clear_input_buffer();
    }
    clear_input_buffer();
    
    if (amount > *balance) {
        printf("INSUFFICIENT FUNDS: Cannot withdraw more than RWF %.2f\n", *balance);
        return;
    }
    
    *balance -= amount;
    log_transaction(transactions, trans_count, "Withdrawal", amount, *balance);
    printf("Successfully withdrew RWF %.2f\nNew balance: RWF %.2f\n", amount, *balance);
}

// View transaction history
void view_transactions(char transactions[][100], int trans_count, char username[]) {
    if (trans_count == 0) {
        printf("No transactions recorded.\n");
        return;
    }
    
    printf("\nTransaction History for %s:\n", username);
    for (int i = 0; i < trans_count; i++) {
        printf("%s\n", transactions[i]);
    }
}

// Log a transaction
void log_transaction(char transactions[][100], int *trans_count, char *type, double amount, double balance) {
    if (*trans_count >= 10) {
        // Shift transactions to make room for new one
        for (int i = 0; i < 9; i++) {
            strcpy(transactions[i], transactions[i + 1]);
        }
        *trans_count = 9;
    }
    
    char trans[100];
    snprintf(trans, 100, "%s: RWF %.2f, New Balance: RWF %.2f", type, amount, balance);
    strcpy(transactions[*trans_count], trans);
    (*trans_count)++;
}

// Validate PIN (must be 4 digits)
int validate_pin(char *pin) {
    if (strlen(pin) != 4) return 0;
    for (int i = 0; i < 4; i++) {
        if (pin[i] < '0' || pin[i] > '9') return 0;
    }
    return 1;
}

// Clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
