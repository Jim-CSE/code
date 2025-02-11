#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to generate the key in a cyclic manner until it matches the length of the text
string generateKey(string text, string key) {
    int textLen = text.length();
    int keyLen = key.length();

    // Repeat the key to match the length of the text
    for (int i = 0; key.length() < textLen; i++) {
        key += key[i % keyLen];
    }

    return key;
}

// Function to encrypt the text using Vigenère cipher
string encrypt(string text, string key) {
    string cipherText = "";

    for (int i = 0; i < text.length(); i++) {
        // Convert characters to uppercase to make it case-insensitive
        char x = (toupper(text[i]) + toupper(key[i]) - 2 * 'A') % 26 + 'A';
        cipherText += x;
    }

    return cipherText;
}

// Function to decrypt the text using Vigenère cipher
string decrypt(string cipherText, string key) {
    string originalText = "";

    for (int i = 0; i < cipherText.length(); i++) {
        char x = (tolower(cipherText[i]) - tolower(key[i]) + 26) % 26 + 'a';
        originalText += x;
    }

    return originalText;
}

int main() {
    string txt,text="", key;

    // Input the plaintext and key
    cout << "Enter the plaintext: ";
    getline(cin, txt);
    for(int i=0;i<txt.length();i++)
    { if(txt[i]!= ' '){
        text+=txt[i]; //remove space
    }
    }

    cout << "Enter the key: ";
    getline(cin, key);

    // Generate the key matching the length of the text
    string generatedKey = generateKey(text, key);

    // Encrypt the plaintext
    string cipherText = encrypt(text, generatedKey);
    cout << "Encrypted Text: " << cipherText << endl;

    // Decrypt the ciphertext
    string decryptedText = decrypt(cipherText, generatedKey);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
