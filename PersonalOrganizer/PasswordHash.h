#pragma once

#include <iostream>
#include <string>
#include <array>
//#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Security::Cryptography;
using namespace System::Text;

public ref class PasswordHash {
private:
    static String^ key = "PersonalOrganiserEncryptSoftware";
public:
    static array<Byte>^ Encrypt(String^ plainText) {
        Aes^ aes = Aes::Create();
        aes->Key = Encoding::UTF8->GetBytes(key);
        aes->GenerateIV();

        System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
        ms->Write(aes->IV, 0, aes->IV->Length); 

        CryptoStream^ cs = gcnew CryptoStream(ms, aes->CreateEncryptor(), CryptoStreamMode::Write);

        array<Byte>^ plainBytes = Encoding::UTF8->GetBytes(plainText);
        cs->Write(plainBytes, 0, plainBytes->Length);
        cs->FlushFinalBlock();
        cs->Close();

        return ms->ToArray();
    }

    static String^ Decrypt(String^ base64CipherText) {
        array<Byte>^ cipherText = Convert::FromBase64String(base64CipherText);

        Aes^ aes = Aes::Create();
        aes->Key = Encoding::UTF8->GetBytes(key);

        if (aes->Key->Length != 16 && aes->Key->Length != 24 && aes->Key->Length != 32) {
            throw gcnew ArgumentException("Invalid key size. Key must be 128, 192, or 256 bits.");
        }

        array<Byte>^ iv = gcnew array<Byte>(aes->BlockSize / 8);
        Array::Copy(cipherText, 0, iv, 0, iv->Length);
        aes->IV = iv;

        System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(cipherText, iv->Length, cipherText->Length - iv->Length);

        CryptoStream^ cs = gcnew CryptoStream(ms, aes->CreateDecryptor(), CryptoStreamMode::Read);
        array<Byte>^ decryptedBytes = gcnew array<Byte>(cipherText->Length);

        int bytesRead = cs->Read(decryptedBytes, 0, decryptedBytes->Length);
        cs->Close();

        return Encoding::UTF8->GetString(decryptedBytes, 0, bytesRead);
    }
};
