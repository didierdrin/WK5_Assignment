ATM Simulator in C programming language

Problem Statement

This project implements an ATM system in C that allows multiple predefined users to log in using a username and 4-digit PIN and perform banking operations such as checking balance, depositing, withdrawing, and viewing transaction history. The system uses arrays and strings to manage user data and transactions, with modular functions for each operation, avoiding complex structures and preprocessor directives for simplicity.

Assumptions





The system supports 5 predefined users with fixed usernames and PINs.



Each user can store up to 10 transactions in a text-based log.



Usernames are unique, case-sensitive, and up to 20 characters.



PINs are exactly 4 digits.



All monetary amounts are in RWF (Rwandan Franc) and stored as doubles.



No file I/O is used; all data is stored in memory during program execution.

How to Compile and Run





Ensure you have a C compiler (e.g., gcc) installed.



Clone the repository: git clone <repository-url>



Navigate to the project directory: cd <project-directory>



Compile the program: gcc main.c -o main



Run the program: ./main



Follow the prompts to log in and use the ATM features.

Sample Input/Output

Welcome to ALU ATM System

Enter username: alice
Enter 4-digit PIN: 1234
Login successful! Welcome, alice.

****** ALU ATM MENU ******
1. Check Balance
2. Deposit
3. Withdraw
4. View Transaction History
5. Exit
Choose an option (1-5): 1
Your current balance is: RWF 1000.00

Choose an option (1-5): 2
Enter amount to deposit (RWF): 500
Successfully deposited RWF 500.00
New balance: RWF 1500.00

Choose an option (1-5): 4
Transaction History for alice:
Deposit: RWF 500.00, New Balance: RWF 1500.00

Choose an option (1-5): 5
Thank you for using ALU ATM. Goodbye!

Key Functions and Design Choices





Modular Design: Functions are separated for login, menu display, input validation, and each ATM operation (check_balance, deposit, withdraw, view_transactions).



User Management: Uses separate arrays for usernames, PINs, balances, and transaction counts. A 3D array stores transaction logs for each user.



Transaction Logging: Each user has a string array to store up to 10 transactions. When the limit is reached, the oldest transaction is removed.



Input Validation: Robust validation for PIN (4 digits), menu choices, and monetary amounts. Input buffer is cleared to prevent errors.



Control Flow: Uses loops for continuous operation and switch statements for menu handling.



Arrays and Strings: 2D arrays for usernames and PINs, 3D array for transaction logs. Strings are used for usernames, PINs, and transaction descriptions.



Simplicity: Avoids typedef struct and #define directives, using hardcoded values (5 users, 10 transactions, 20-char usernames, 4-digit PINs, 100-char transactions) for clarity.

Team Contributions





Member 1: Implemented login system, input validation, and array-based user data management.



Member 2: Developed deposit, withdraw, and transaction logging functions.



Member 3: Created menu system, transaction history display, and README documentation.

GitHub Repository

The project is hosted in a public GitHub repository with a clear commit history showing incremental development and contributions from each team member.