#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;

    cout << "\n--- User Registration ---\n";
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Check if username already exists
    ifstream readFile(username + ".txt");

    if (readFile.is_open()) {
        cout << "Username already exists!\n";
        readFile.close();
        return;
    }

    // Create new user file
    ofstream writeFile(username + ".txt");
    writeFile << username << endl;
    writeFile << password << endl;
    writeFile.close();

    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "\n--- User Login ---\n";
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream readFile(username + ".txt");

    if (!readFile.is_open()) {
        cout << "User not found!\n";
        return;
    }

    getline(readFile, storedUsername);
    getline(readFile, storedPassword);
    readFile.close();

    if (username == storedUsername && password == storedPassword) {
        cout << "Login Successful!\n";
    } else {
        cout << "Invalid Password!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}