#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string txt, text = "", key, cipherText = "", originalText = "";

    // Input the plaintext and remove spaces
    cout << "Enter the plaintext: ";
    getline(cin, txt);
    for (int i = 0; i < txt.length(); i++) {
        if (txt[i] != ' ') {
            text += txt[i];  // Append non-space characters to text
        }
    }

    // Input the key
    cout << "Enter the key: ";
    getline(cin, key);

    // Generate the key to match the length of the text
    int textLen = text.length();
    int keyLen = key.length();
    for (int i = 0; key.length() < textLen; i++) {
        key += key[i % keyLen];  // Repeat the key until it matches text length
    }

    // Encryption process (Vigenère cipher)
    for (int i = 0; i < text.length(); i++) {
        // Convert to uppercase and apply the encryption formula
        char x = (toupper(text[i]) + toupper(key[i]) - 2 * 'A') % 26 + 'A';
        cipherText += x;
    }

    // Output the encrypted text
    cout << "Encrypted Text: " << cipherText << endl;

    // Decryption process (Vigenère cipher)
    for (int i = 0; i < cipherText.length(); i++) {
        // Convert to lowercase and apply the decryption formula
        char x = (tolower(cipherText[i]) - tolower(key[i]) + 26) % 26 + 'a';
        originalText += x;
    }

    // Output the decrypted text
    cout << "Decrypted Text: " << originalText << endl;

    return 0;
}
