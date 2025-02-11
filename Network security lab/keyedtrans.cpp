#include <bits/stdc++.h>
using namespace std;

// Function to encrypt the plaintext
string en(string plaintext, int keySize, int keyValues[], int &bogus) {
    int count = 0;
    string newPlaintext = "", finalplaintext = "", ciphertext = "", tmpCipher = "";

    // Remove spaces in the plaintext
    for (int i = 0; i < plaintext.length(); i++) {
        if (plaintext[i] != ' ') {
            newPlaintext += plaintext[i];
        }
    }

    // Length after removing spaces of plaintext
    int newLength = newPlaintext.length();

    // Add bogus characters to make the length divisible by key size
    finalplaintext += newPlaintext;
    bogus = keySize - (newLength % keySize);
    if (bogus == keySize) bogus = 0; // No need to add bogus characters if it's a multiple of key size
    for (int i = 0; i < bogus; i++) {
        finalplaintext += 'z'; // Add bogus 'z' characters
    }

    // Length of plaintext after adding bogus characters
    int finalLength = finalplaintext.length();

    // Encryption
    for (int i = 0; i < finalLength; i++) {
        count++;
        tmpCipher += toupper(finalplaintext[i]);  // Convert to uppercase

        // Block by block encryption
        if (count == keySize) {
            for (int k = 0; k < keySize; k++) {
                ciphertext += tmpCipher[keyValues[k] - 1];  // Encrypt by rearranging based on keyValues
            }
            tmpCipher = "";
            count = 0;
        }
    }

    return ciphertext;
}

// Function to decrypt the ciphertext
string de(string ciphertext, int keySize, int keyValues[], int bogus) {
    int count = 0;
    string decryptedtext = "", tmpCipher = "", tmpDecrypted = "";

    // Decryption
    for (int i = 0; i < ciphertext.length(); i++) {
        count++;
        tmpCipher += ciphertext[i];  // Create a block for decryption

        if (count == keySize) {
            // Reverse the block using the key values
            tmpDecrypted.resize(keySize);
            for (int k = 0; k < keySize; k++) {
                tmpDecrypted[keyValues[k] - 1] = tmpCipher[k];
            }

            // Convert the block back to lowercase
            for (int j = 0; j < keySize; j++) {
                decryptedtext += tolower(tmpDecrypted[j]);
            }

            tmpCipher = "";
            count = 0;
        }
    }

    // Remove the bogus characters from the decrypted text
    if (bogus > 0) {
        decryptedtext.erase(decryptedtext.end() - bogus, decryptedtext.end());
    }

    return decryptedtext;
}

int main() {
    int keySize, bogus;
    string plaintext, ciphertext, decryptedtext;

    // Input plaintext
    cout << "Give a plaintext: ";
    getline(cin, plaintext);

    // Input key size
    cout << "Key size: ";
    cin >> keySize;

    int keyValues[keySize];
    // Input key values
    cout << "Enter the key values: ";
    for (int i = 0; i < keySize; i++) {
        cin >> keyValues[i];
    }

    // Encrypt the plaintext
    ciphertext = en(plaintext, keySize, keyValues, bogus);

    // Print the ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt the ciphertext
    decryptedtext = de(ciphertext, keySize, keyValues, bogus);

    // Print the decrypted text
    cout << "Decrypted Text: " << decryptedtext << endl;

    return 0;
}





//without function
/*#include<bits/stdc++.h>
using namespace std;

int main() {

    int keySize, count = 0;
    string plaintext, newPlaintext = "", finalplaintext = "", ciphertext = "", tmpCipher = "";
    string decryptedtext = "", tmpDecrypted = "";

    // Input plaintext
    cout << "Give a plaintext : ";
    getline(cin, plaintext);

    // Length of the plaintext
    int len = plaintext.length();

    // Input key size
    cout << "Key size : ";
    cin >> keySize;

    int keyValues[keySize];
    // Input key values
    cout << "Enter the key values : ";
    for (int i = 0; i < keySize; i++) {
        cin >> keyValues[i];
    }

    // Remove spaces in the plaintext
    for (int i = 0; i < len; i++) {
        if (plaintext[i] != ' ') {
            newPlaintext += plaintext[i];
        }
    }

    // Length after removing spaces of plaintext
    int newLength = newPlaintext.length();

    // Add bogus characters to make the length divisible by key size
    finalplaintext += newPlaintext;
    int bogus = keySize - (newLength % keySize);
    for (int i = 0; i < bogus; i++) {
        finalplaintext += 'z';
    }

    // Length of plaintext after adding bogus characters
    int finalLength = finalplaintext.length();

    // Encryption
    for (int i = 0; i < finalLength; i++) {
        count++;
        // Lowercase to uppercase conversion using ASCII values
        tmpCipher += toupper(finalplaintext[i]);

        // Block by block encryption
        if (count == keySize) {
            for (int k = 0; k < keySize; k++) {
                ciphertext += tmpCipher[keyValues[k] - 1];
            }
            tmpCipher = "";
            count = 0;
        }
    }

    // Print the ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

    // Decryption
    count = 0; // Reset count for decryption

    for (int i = 0; i < ciphertext.length(); i++) {
        count++;
        // Create a block for decryption
        tmpCipher += ciphertext[i];

        if (count == keySize) {
            // Reverse the block using the key values
            tmpDecrypted.resize(keySize);
            for (int k = 0; k < keySize; k++) {
                tmpDecrypted[keyValues[k] - 1] = tmpCipher[k];
            }

            // Convert the block back to lowercase using ASCII values
            for (int j = 0; j < keySize; j++) {
                decryptedtext += tolower(tmpDecrypted[j]);
            }
            tmpCipher = "";
            tmpDecrypted = "";
            count = 0;
        }
    }

    // Remove the bogus characters from the decrypted text
    decryptedtext.erase(decryptedtext.end() - bogus, decryptedtext.end());

    // Print the decrypted text
    cout << "Decrypted Text: " << decryptedtext << endl;

    return 0;
}

*/
