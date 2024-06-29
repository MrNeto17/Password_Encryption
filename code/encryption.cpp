#include <iostream>

#include <iostream>
#include <string>

// Caesar cipher encryption/decryption
void caesarCipher(std::string& password, int shift, bool encryptMode) {
    // Ensure shift is within the range 0-25
    shift %= 26;
    if (shift < 0) {
        shift += 26; // Adjust negative shift to positive equivalent
    }

    // Iterate through each character in the password
    for (char& ch : password) {
        // Check if the character is alphabetic
        if (std::isalpha(ch)) {
            // Determine base character ('a' for lowercase, 'A' for uppercase)
            char base = std::islower(ch) ? 'a' : 'A';

            // Apply encryption or decryption based on mode
            if (encryptMode) {
                // Encrypt: shift character forward
                ch = base + (ch - base + shift) % 26;
            } else {
                // Decrypt: shift character backward
                ch = base + (ch - base - shift + 26) % 26;
            }
        }
    }
}

// XOR encryption/decryption
void xorEncryption(std::string& password, const std::string& key) {
    size_t keyLength = key.length();
    size_t passwordLength = password.length();

    // Iterate through each character in the password
    for (size_t i = 0; i < passwordLength; ++i) {
        // XOR each character of the password with the corresponding key character
        password[i] ^= key[i % keyLength];
    }
}

