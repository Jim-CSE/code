#include <bits/stdc++.h>
using namespace std;

int main() {
    string pl, plain = "", cipher = "", decipher = "";

    // Input the plaintext
    cout << "Enter the plainText: ";
    getline(cin, pl);

    // Remove spaces from the plaintext

    for(int i=0;i<pl.size();i++)
    {
        if(isalpha(pl[i]))
        {
            plain += pl[i];
        }
    }

    // Encryption process: first add characters at even indices, then odd indices
    for (int i = 0; i < plain.size(); i += 2)
        cipher += toupper(plain[i]);
    for (int i = 1; i < plain.size(); i += 2)
        cipher += toupper(plain[i]);


    // Output the encrypted text
    cout << "The cipherText is: " << cipher << endl;

    // Decryption process: divide the cipher text into two halves and merge them back
    int n = cipher.size();
    for (int i = 0, j = (n + 1) / 2; i < (n + 1) / 2; i++, j++) {
        decipher += tolower(cipher[i]);  // First half (even indices in original)
        if (j < n)
            decipher += tolower(cipher[j]);  // Second half (odd indices in original)
    }



    // Output the decrypted text
    cout << "The decipherText is: " << decipher << endl;

    return 0;
}
