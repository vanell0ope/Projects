#include <iostream>
#include <string>
#include <cctype>

bool hasUpper(const std::string& password){
    for (char ch: password){
        if (std::isupper(ch)) return true;
    }
    return false;
}

bool hasLower(const std::string& password){
    for (char ch: password){
        if (std::islower(ch)) return true;
    }
    return false;
}

bool hasDigit(const std::string& password){
    for (char ch: password){
        if (std::isdigit(ch)) return true;
    }
    return false;
}

bool hasSpecial(const std::string& password){
    std::string specials = "!@#$%^&*()-_=+[]{}|;:',.<>?/";
    for (char ch: password){
        if (specials.find(ch) != std::string::npos) return true;
    }
    return false;
}

int main(){
    std::string password ;
    std::cout << "Enter password: ";
    std::cin >> password;

    bool lengthOK = password.length() >= 8;
    bool upperOK = hasUpper(password);
    bool lowerOK = hasLower(password);
    bool digitOK = hasDigit(password);
    bool specialOK = hasSpecial(password);

    int score = lengthOK + upperOK + lowerOK + digitOK + specialOK;

    if (score == 5){
        std::cout << "Password strength: STRONG\n";
    } else if (score >= 3){
        std::cout << "Password strength: MODERATE\n";
    } else {
        std::cout << "Password strength: WEAK\n";
    }

    return 0;
}