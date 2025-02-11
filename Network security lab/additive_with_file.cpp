#include<bits/stdc++.h>
using namespace std;

// Encryption function
string en(string p, int k){
    string ci;
    for(int i = 0; i < p.size(); i++) {
        if(isalpha(p[i])) {
            char c = toupper(p[i]);
            ci += (c + k - 'A') % 26 + 'A';
        }
    }
    return ci;
}

// Decryption function
string de(string ci, int k){
    string pi;
    for(int i = 0; i < ci.size(); i++) {
        if(isalpha(ci[i])) {
            char c = tolower(ci[i]);
            pi += (c - k - 'a' + 26) % 26 + 'a';
        }
    }
    return pi;
}

int main() {
    string p, ci;
    int k;

    // Open the input file
    ifstream inputFile("in.txt");
    if (!inputFile) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    // Read the plaintext from file
    getline(inputFile, p);

    // Read the key from file
    inputFile >> k;

    // Close the input file after reading
    inputFile.close();

    // Encryption
    ci = en(p, k);
    cout << "Encrypted text: " << ci << endl;

    // Decryption
    string decryptedText = de(ci, k);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
