#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string xorEncryptDecrypt(const string& text, char key){
    string result = text;
    for (size_t i = 0; i < text.size(); ++i){
        result[i] = text[i] ^ key;
    }
    return result;
}

void saveNote(const string& filename, const string& note, char key){
    ofstream file(filename);
    if (file.is_open()){
        string encrypted = xorEncryptDecrypt(note, key);
        file << encrypted;
        file.close();
        cout << "Note saved successfully.\n";
    } else {
        cout << "Failed to open file.\n";
    }
}

void loadNote(const string& filename, char key){
    ifstream file(filename);
    if (file.is_open()){
        string encrypted, decrypted;
        getline(file, encrypted);
        decrypted = xorEncryptDecrypt(encrypted, key);
        file.close();
        cout << "Decrypted Note:\n" << decrypted << "\n";
    } else {
        cout << "Failed to open file.\n";
    }
}

int main(){
    char key = 'K';
    string filename = "note.txt";
    int choice;
    string note;

    do {
        cout << "\n1. Write note\n2. Read note\n3. Exit\n Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout << "Enter your note:\n";
                getline(cin, note);
                saveNote(filename, note, key);
                break;
            case 2:
                loadNote(filename, key);
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}