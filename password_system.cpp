#include <iostream>
#include <string>

std::string savedUsername;
std::string savedPassword;

void registerUser(){
    std::cout << "=== Register ===\n";
    std::cout << "Enter username: ";
    std::cin >> savedUsername;
    std::cout << "Enter password: ";
    std::cin >> savedPassword;
    std::cout << "Registration successful!\n";
}

void loginUser(){
    std::string inputUsername, inputPassword;
    std::cout << "=== Login ===\n";
    std::cout << "Username: ";
    std::cin >> inputUsername;
    std::cout << "Password: ";
    std::cin >> inputPassword;

    if (inputUsername == savedUsername && inputPassword == savedPassword){
        std::cout << "Login successful!\n";
    } else{
        std::cout << "Login failed. Incorrect username or password.\n";
    }
}

int main(){
    int choice;
    
    do{
        std::cout << "\n1. Register\n2. Login\n3. Exit\nChoose: ";
        std::cin >> choice;

        if (choice == 1){
            registerUser();
        } else if (choice == 2){
            loginUser();
        }
    } while (choice != 3);
    
    return 0;
}