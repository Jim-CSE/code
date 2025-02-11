#include<bits/stdc++.h>
using namespace std;
string en(string p,int k){
    string ci;
    for(int i=0;i<p.size();i++)
    {
        if(isalpha(p[i]))
        {
            char c=toupper(p[i]);
            ci += (c+ k -'A')%26 + 'A';
        }
    }
    return ci;
}
string de(string ci,int k){
    string pi;
    for(int i=0;i<ci.size();i++)
    {
        if(isalpha(ci[i]))
        {
            char c=tolower(ci[i]);
            pi += (c- k -'a' +26)%26 + 'a';
        }
    }
    return pi;
}
int main(){
string p,ci;
cout<<"Enter the plaintext:";
getline(cin,p);
int k;
cout<<"Enter the value of key:";
cin>>k;
// Encryption
    ci = en(p, k);
    cout << "Encrypted text: " << ci << endl;

    // Decryption
    string decryptedText = de(ci, k);
    cout << "Decrypted text: " << decryptedText << endl;
}



//without funtion
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    string p,ci="",p1="";
    cout<<"enter plsaintext: ";
    getline(cin,p);

    int k;
    cout<<"enter a key: ";
    cin>>k;

    for(int i=0;i<p.size();i++)
    {
        if(isalpha(p[i]))
        {
            char c=toupper(p[i]);
            ci += (c+ k -'A')%26 + 'A';
        }
    }

    for(int i=0;i<ci.size();i++)
    {
        if(isalpha(ci[i]))
        {
            char c=tolower(ci[i]);
            p1 += (c- k -'a' +26)%26 + 'a';
        }
    }
    cout<<ci<<endl;
    cout<<p1;
}
*/
