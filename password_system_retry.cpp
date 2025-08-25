#include <iostream>
#include <string>
#include <cctype>

std::string savedUsername;
std::string savedPassword;
std::string rawPassword;
std::string confirmPassword;

bool hasUpper(const std::string& savedPassword){
    for (char ch: savedPassword){
        if (std::isupper(ch)) return true;
    }
    return false;
}

bool hasLower(const std::string& savedPassword){
    for (char ch: savedPassword){
        if (std::islower(ch)) return true;
    }
    return false;
}

bool hasDigit(const std::string& savedPassword){
    for (char ch: savedPassword){
        if(std::isdigit(ch)) return true;
    }
    return false;
}

bool hasSpecial (const std::string& savedPassword){
    std::string specials ="!@#$%^&*()-_=+[]{}|;:',.<>?/";
    for (char ch: savedPassword){
        if (specials.find(ch) != std::string::npos) return true;
    }
    return false;
}

void registerUser(){
    std::cout << "Welcome to the site! Please register first before using our services!\n";
    std::cout << "Enter username: "; 
    std::cin >> savedUsername;
    std::cout << "Enter password: ";
    std::cin >> savedPassword;
    
    bool lengthOK = savedPassword.length() >= 8;
    bool upperOK = hasUpper(savedPassword);
    bool lowerOK = hasLower(savedPassword);
    bool digitOK = hasDigit(savedPassword);
    bool specialOK = hasSpecial(savedPassword);

    int score = lengthOK + upperOK + lowerOK + digitOK + specialOK;

    if (score == 5){
        std::cout << "Password strength: STRONG\n";
    } else if (score >= 3){
        std::cout << "Password strength: MODERATE\n";
    } else {
        std::cout << "Password strength: WEAK\n";
    }

    std::cout << "Registration successful!\n";
}

void loginUser(){
    const std::string correctUsername = savedUsername;
    const std::string correctPassword = savedPassword;
    std::string inputUsername, inputPassword;
    int attempts = 0;
    const int maxAttempts = 3;

    while (attempts < maxAttempts){
        std::cout << "You may login into your account\n";
        std::cout << "Username: ";
        std::cin >> inputUsername;
        std::cout << "Password: ";
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
        std::cout << 'Too many failed attempts. Access denied.\n';
    }
}

int main(){
    int choice;

    do{
        std::cout << "\n === Security System Menu ===\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1){
            registerUser();
        } else if (choice == 2){
            loginUser();
        } else if (choice != 3){
            std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 3);

    std::cout << "Goodbye!\n";
    return 0;
}