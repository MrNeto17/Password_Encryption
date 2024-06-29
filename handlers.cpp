#include <iostream>
#include <string>
// Function to handle Caesar cipher encryption/decryption
void handleCaesarCipher(std::string& password) {
    int shift;
    std::cout << "Enter the shift value for Caesar cipher (integer): ";
    std::cin >> shift;

    // Encrypt with Caesar cipher
    caesarCipher(password, shift, true);
    std::cout << "Encrypted password (Caesar cipher): " << password << std::endl;

    // Decrypt with Caesar cipher
    caesarCipher(password, shift, false);
    std::cout << "Decrypted password (Caesar cipher): " << password << std::endl;
}

// Function to handle XOR encryption/decryption
void handleXorEncryption(std::string& password) {
    std::string key;
    std::cout << "Enter the key for XOR encryption: ";
    //Handle Spaces
    std::getline(std::cin, key);

    // Encrypt with XOR
    xorEncryption(password, key);
    std::cout << "Encrypted password (XOR): " << password << std::endl;

    // Decrypt with XOR
    xorEncryption(password, key);
    std::cout << "Decrypted password (XOR): " << password << std::endl;
}
