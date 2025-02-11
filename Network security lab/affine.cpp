#include<bits/stdc++.h>
using namespace std;

// Function to find the multiplicative inverse of a key in mod 26
int MI(int key) {
    for (int i = 1; i <= 26; i++) {
        if ((key * i) % 26 == 1)
            return i;
    }
    cout << "Invalid multiplicative key" << endl;
    return -1;
}

// Function to encrypt the plaintext using the keys
string encrypt(string plain, int keyAdd, int keyMul) {
    string cipher = "";
    for (int i = 0; i < plain.size(); i++) {
        if (isalpha(plain[i])) {
            char c = toupper(plain[i]); // Convert to uppercase for uniformity
            cipher += ((c - 'A') * keyMul + keyAdd) % 26 + 'A'; // Affine cipher formula
        }
    }
    return cipher;
}

// Function to decrypt the ciphertext using the keys
string decrypt(string cipher, int keyAdd, int keyMul) {
    string plain = "";
    int invKeyMul = MI(keyMul); // Find multiplicative inverse
    if (invKeyMul == -1) {
        return ""; // Return an empty string if inverse is not valid
    }

    for (int i = 0; i < cipher.size(); i++) {
        if (isalpha(cipher[i])) {
            char c = cipher[i];
            plain += tolower(((c - 'A' - keyAdd + 26) * invKeyMul) % 26 + 'A'); // Decryption formula
        }
    }
    return plain;
}

int main() {
    string plain, cipher, decryptedText;
    int keyAdd, keyMul;

    cout << "Enter Plaintext: ";
    getline(cin, plain);

    cout << "Enter Key (additive): ";
    cin >> keyAdd;

    while (true) {
        cout << "Enter Key (multiplicative): ";
        cin >> keyMul;

        int invKeyMul = MI(keyMul);
        if (invKeyMul != -1) {
            // Encryption
            cipher = encrypt(plain, keyAdd, keyMul);
            cout << "Cipher text: " << cipher << endl;

            // Decryption
            decryptedText = decrypt(cipher, keyAdd, keyMul);
            cout << "Decrypted text: " << decryptedText << endl;

            break;
        } else {
            cout << "Invalid multiplicative key, please enter again." << endl;
        }
    }

    return 0;
}

/*
withoutfunction
#include<bits/stdc++.h>
using namespace std;

int ik(int k1)
{
    for(int i=1;i<=26; i++)
    {
        if((i*k1)%26 == 1)
            return i;
    }
    cout<<"invalid multicative key: "<<endl;
    return -1;
}
int main()
{
   string p,pi="",ci= "";
    cout<<"enter text: ";
    getline(cin,p);

    int k1,k2;

    cout << "aadi key: "<<endl;
    cin>>k2;

    z: cout<<"multi key:"<<endl;
    cin>>k1;
    int iik= ik(k1);
    if(iik != -1){
    for(int i=0;i< p.size();i++)
    {
        if(isalpha(p[i]))
        {
            char c= toupper(p[i]);
            ci+= ((c - 'A')*k1 + k2)%26 + 'A';
        }
    }



    for(int i=0;i< ci.size();i++)
    {
        if(isalpha(ci[i]))
        {
            char c= tolower(ci[i]);
            pi += ((c  -'a' - k2 +26)* iik)%26 + 'a';
        }
    }
    cout<<ci<<endl;
    cout<<pi;
    }
    else{
        goto z;
    }
}
*/
