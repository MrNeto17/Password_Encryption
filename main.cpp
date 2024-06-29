#include <iostream>
#include <string>
#include "headers.hpp" // Include the header file for encryption functions

// Function to choose and handle encryption method
void chooseEncryptionMethod(std::string& password) {
    std::string encryptionMethod;
    do {
        std::cout << "Choose encryption method (xor/cesar): ";
        std::cin >> encryptionMethod;
    } while (encryptionMethod != "xor" && encryptionMethod != "cesar");

    if (encryptionMethod== "cesar") {
        handleCaesarCipher(password);
    } else if (encryptionMethod =="xor") {
        handleXorEncryption(password);
    }
}

int main() {
    std::string password;

    // Input password
    std::cout<<"Enter a password to encrypt/decrypt: ";
    std::getline(std::cin, password);

    // Choose and handle encryption method
    chooseEncryptionMethod(password);
    return 0;
}
