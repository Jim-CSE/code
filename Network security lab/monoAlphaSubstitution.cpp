#include<bits/stdc++.h>
using namespace std;

int main()
{
    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'N','O','A','T','R','B','E','C','F','U','X','D','Q','G','Y','L','K','H','V','I','J','M','P','Z','S','W'};
    string plaintext, newPlaintext, ciphertext="", decryptedText="";

    cout<<"Enter the plaintext : ";
    getline(cin, plaintext);

    int len = plaintext.length();

    //remove space in the plaintext
    for(int i=0; i<len; i++){
        if(plaintext[i] != ' '){
            newPlaintext += plaintext[i];
        }
    }
    // length after removing space of plaintext
    int newLength = newPlaintext.length();


    //encryption

    for(int i=0; i<newLength; i++){

        //lowercase to uppercase conversion and create a block, block size is equal to keysize
        for (int j = 0; j < 26; ++j) {
            if (p[j] == newPlaintext[i]) {
                ciphertext += c[j];
            }
        }

    }

    cout<<"Encrypted text: "<<ciphertext<<endl;

    //decryption
    for(int i=0; i<ciphertext.length(); i++){

        //find the corresponding letter in the plain array
        for (int j = 0; j < 26; ++j) {
            if (c[j] == ciphertext[i]) {
                decryptedText += p[j];
            }
        }

    }

    cout<<"Decrypted text: "<<decryptedText<<endl;

    return 0;
}
