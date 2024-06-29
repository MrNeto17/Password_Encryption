#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <string>
#include"encryption.cpp"
#include"handlers.cpp"

void caesarCipher(std::string& password, int shift, bool encryptMode);
void xorEncryption(std::string& password, const std::string& key);


void handleCaesarCipher(std::string& password);
void handleXorEncryption(std::string& password);


void chooseEncryptionMethod(std::string& password);

#endif
