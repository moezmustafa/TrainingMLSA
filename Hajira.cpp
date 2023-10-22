#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Coffee class to represent a coffee order
class Coffee {
public:
    string type;
    string size;
    vector<string> extras;
    double price;

    // Function to calculate the price of the coffee order
    void calculatePrice() {
        // Calculate the base price based on coffee type and size
        if (type == "Espresso") {
            price = 250;
        }
        else if (type == "Latte") {
            price = 300;
        }
        else if (type == "Cappuccino") {
            price = 350;
        }

        if (size == "Medium") {
            price *= 120;
        }
        else if (size == "Large") {
            price *= 150;
        }

        // Add extra charges for each extra
        for (const auto& extra : extras) {
            price += 0.5;
        }
    }

    // Function to display the details of the coffee order
    void displayOrder() {
        cout << "Coffee Order Details:\n";
        cout << "Type: " << type << endl;
        cout << "Size: " << size << endl;

        if (!extras.empty()) {
            cout << "Extras:";
            for (const auto& extra : extras) {
                cout << " " << extra;
            }
            cout << endl;
        }

        cout << fixed << setprecision(2);
        cout << "Total Price: Rs" << price << endl;
        cout << "Enjoy your coffee!\n";
    }
};

// User class to represent a user account
class User {
public:
    string username;
    string password;
    double wallet;
};

// Function to check if a username already exists
bool usernameExists(const vector<User>& users, const string& username) {
    for (const auto& user : users) {
        if (user.username == username) {
            return true; // Username already exists
        }
    }
    return false; // Username does not exist
}

// Function to handle the coffee ordering process
void orderCoffee(User& currentUser) {
    Coffee myCoffee;

    // Display menu
    cout << "Welcome to the Coffee Shop!\n";
    cout << "1. Espresso\n2. Latte\n3. Cappuccino\n";

    // Get user input for coffee type
    int choice;
    cout << "Enter the number corresponding to your desired coffee type: ";
    cin >> choice;

    // Validate user input
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice. Exiting program.\n";
        return;
    }

    // Create a Coffee object and set the type based on user choice
    switch (choice) {
    case 1:
        myCoffee.type = "Espresso";
        break;
    case 2:
        myCoffee.type = "Latte";
        break;
    case 3:
        myCoffee.type = "Cappuccino";
        break;
    }

    // Get user input for coffee size
    cout << "Select the size (Small, Medium, Large): ";
    cin >> myCoffee.size;

    // Get user input for extras
    cout << "Do you want any extras? (Y/N): ";
    char response;
    cin >> response;

    if (response == 'Y' || response == 'y') {
        cout << "Enter extras separated by spaces (e.g., Sugar Milk): ";
        string extra;
        while (cin >> extra) {
            myCoffee.extras.push_back(extra);

            // Check if the user entered more extras
            cout << "Add more extras? (Y/N): ";
            cin >> response;
            if (!(response == 'Y' || response == 'y')) {
                break;
            }
        }
    }

    // Calculate the price of the coffee order
    myCoffee.calculatePrice();

    // Display the coffee order details
    myCoffee.displayOrder();

    // Check if the user has enough money to make the payment
    if (currentUser.wallet < myCoffee.price) {
        cout << "Insufficient funds. Please add money to your wallet.\n";
    }
    else {
        // Deduct the price from the user's wallet
        currentUser.wallet -= myCoffee.price;
        cout << "Payment successful. $" << myCoffee.price << " deducted from your wallet.\n";
    }
}

int main() {
    vector<User> users; // Vector to store user accounts

    // Create a default user for testing
    User defaultUser;
    defaultUser.username = "testuser";
    defaultUser.password = "testpass";
    defaultUser.wallet = 10.0; // Initial wallet balance

    users.push_back(defaultUser);

    // Display login or create account options
    cout << "Welcome to the Coffee Shop!\n";
    cout << "1. Login\n2. Create Account\n";

    int choice;
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;

    User currentUser; // Variable to store the current user's information

    if (choice == 1) {
        // Login
        string enteredUsername, enteredPassword;
        cout << "Enter your username: ";
        cin >> enteredUsername;

        cout << "Enter your password: ";
        cin >> enteredPassword;

        // Check if the entered username and password match any user account
        bool loginSuccess = false;
        for (const auto& user : users) {
            if (user.username == enteredUsername && user.password == enteredPassword) {
                currentUser = user; // Set the current user
                loginSuccess = true;
                break;
            }
        }

        if (loginSuccess) {
            cout << "Login successful!\n";
        }
        else {
            cout << "Login failed. Exiting program.\n";
            return 1;
        }
    }
    else if (choice == 2) {
        // Create Account
        User newUser;
        cout << "Enter a new username: ";
        cin >> newUser.username;

        // Check if the username already exists
        if (usernameExists(users, newUser.username)) {
            cout << "Username already exists. Exiting program.\n";
            return 1;
        }

        cout << "Enter a password: ";
        cin >> newUser.password;

        // Add the new user to the vector of users
        users.push_back(newUser);
        currentUser = newUser; // Set the current user
        cout << "Account created successfully!\n";
    }
    else {
        cout << "Invalid choice. Exiting program.\n";
        return 1;
    }

    // Proceed to coffee ordering
    orderCoffee(currentUser);

    return 0;
}
