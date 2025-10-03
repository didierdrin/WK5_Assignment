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

