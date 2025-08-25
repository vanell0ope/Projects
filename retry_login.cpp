#include <iostream>
#include <string>

int main(){
    const std::string correctUsername = "Rinwest";
    const std::string correctPassword = "rwst6712";
    std::string inputUsername, inputPassword;
    int attempts = 0;
    const int maxAttempts = 3;
    std::cout << "=== Login ===\n";

    while (attempts < maxAttempts){
        
        std::cout << "Enter username: ";
        std::cin >> inputUsername;
        std::cout << "Enter password: ";
        std::cin >> inputPassword;

        if (inputUsername == correctUsername && inputPassword == correctPassword){
            std::cout << "Login successful!\n";
            break;
        } else{
            attempts++;
            std::cout << "Incorrect credentials. Attempts left: " << (maxAttempts - attempts) << "\n";
        }
    }

    if (attempts == maxAttempts){
        std::cout << "Too many failed attempts. Access denied.\n";
    }

    return 0;
}