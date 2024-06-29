#include <iostream>
#include <string>

// Function to perform Caesar cipher encryption or decryption on a string
void caesarCipher(std::string& password, int shift, bool encryptMode) {
    // Adjust shift to ensure it's within the range 0-25
    shift %= 26;
    if (shift < 0) shift += 26;

    for (char& ch : password) {
        if (std::isalpha(ch)) {
            char base = std::islower(ch) ? 'a' : 'A';
            if (encryptMode) {
                ch = static_cast<char>((ch - base + shift) % 26 + base);
            } else {
                ch = static_cast<char>((ch - base - shift + 26) % 26 + base);
            }
        }
    }
}

// Function to perform XOR encryption or decryption on a string
void xorEncryption(std::string& password, const std::string& key) {
    size_t keyLength = key.length();
    size_t passwordLength = password.length();

    for (size_t i = 0; i < passwordLength; ++i) {
        password[i] ^= key[i % keyLength];
    }
}

int main() {
    std::string password;
    int shift;
    std::string xorKey;

    // Input password
    std::cout << "Enter a password to encrypt/decrypt: ";
    std::getline(std::cin, password);

    // Input shift value
    std::cout << "Enter the shift value for Caesar cipher (integer): ";
    std::cin >> shift;

    std::cin.ignore(); // Ignore newline left in the input buffer

    // Encrypt with Caesar cipher
    caesarCipher(password, shift, true);
    std::cout << "Encrypted password (Caesar cipher): " << password << std::endl;

    // Decrypt with Caesar cipher
    caesarCipher(password, shift, false);
    std::cout << "Decrypted password (Caesar cipher): " << password << std::endl;

    // Input XOR encryption key
    std::cout << "Enter the key for XOR encryption: ";
    std::getline(std::cin, xorKey);

    // Encrypt with XOR
    xorEncryption(password, xorKey);
    std::cout << "Encrypted password (XOR): " << password << std::endl;

    // Decrypt with XOR (reversing XOR with the same key decrypts it)
    xorEncryption(password, xorKey);
    std::cout << "Decrypted password (XOR): " << password << std::endl;

    return 0;
}
