
#include <bits/stdc++.h>
using namespace std;

int main() {
    string pl, plain="", cipher = "", decipher = "";
    int k1;

    // Input the plaintext
    cout << "Enter the plaintext: ";
    getline(cin, pl);  // Allow spaces in the plaintext

    // Remove spaces from the plaintext and ensure all characters are lowercase

for(int i=0;i<pl.size();i++)
{
    if(isalpha(pl[i])){
        plain +=pl[i];
    }
}

    // Input the key
    cout << "Enter the key (0-25): ";
    cin >> k1;

    // Encryption using Autokey Cipher
    vector<int> k(plain.size());  // Use vector to store the key values
    k[0] = k1;  // Set the first key value

    // Generate subsequent key values based on the plaintext
    for (int i = 1; i < plain.size(); i++) {
        k[i] = (plain[i - 1] - 'a');  // Set key based on previous plaintext character
    }

    // Encrypt the plaintext
    for (int i = 0; i < plain.size(); i++) {
        cipher += ((plain[i] - 'a' + k[i]) % 26) + 'A';  // Encrypt and convert to uppercase
    }

    // Output the encrypted text
    cout << "The cipherText is: " << cipher << "\n";

    // Decryption using Autokey Cipher
    k[0] = k1;  // Set the first key value for decryption

    for (int i = 0; i < cipher.size(); i++) {
        // Decrypt the character and convert to lowercase
        char decryptedChar = ((cipher[i] - 'A' - k[i] + 26) % 26) + 'a';
        decipher += decryptedChar;

        // Update the key for the next character based on the decrypted text
        if (i + 1 < cipher.size()) {
            k[i + 1] = (decryptedChar - 'a');
        }
    }

    // Output the decrypted text
    cout << "The decipheredText is: " << decipher << "\n";

    return 0;
}
