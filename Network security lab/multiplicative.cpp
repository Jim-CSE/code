
#include<bits/stdc++.h>
using namespace std;

int ik(int k)
{
    for(int i=1;i<=26;i++)
    {
        if((i*k)%26==1)
            return i;
    }
    cout<<"it is invalid multiplicaaltive key"<<endl;
return -1;
}
string en(string p,int k){
    string ci;

     for(int i=0;i<p.size();i++)
     {
         if(isalpha(p[i]))
         {
             char c= toupper(p[i]);

             ci += ((c- 'A')*k )%26 + 'A';
         }
     }
     return ci;

}


string de(string ci, int inerse_key)
{
    string pi;
    for(int i=0;i<ci.size();i++)
     {
         if(isalpha(ci[i]))
         {
             char c= tolower(ci[i]);

             pi += ((c- 'a')*inerse_key  +26)%26 + 'a';
         }
     }
     return pi;
}
int main()
{
    string p,ci,pi;
    cout<<"enter plaintext: ";
    getline(cin,p);
     int k;
    z: cout<<"enter key: ";
     cin>>k;
     int inerse_key = ik(k);
     if(inerse_key != -1){
            string enc=en(p,k);
         cout<<"CipherText: "<<enc<<endl;
     string dec=de(enc,inerse_key);
     cout<<"Decrypted Text: "<<dec<<endl;
     }
 else{
    goto z;
 }


 }



 //without funtion
 /*#include<bits/stdc++.h>
using namespace std;

int ik(int k)
{
    for(int i=1;i<=26;i++)
    {
        if((i*k)%26==1)
            return i;
    }
    cout<<"it is invalid multiplicaaltive key"<<endl;
return -1;
}
int main()
{
    string p,ci,p1;
    cout<<"enter plaintext: ";
    getline(cin,p);
     int k;
    z: cout<<"enter key: ";
     cin>>k;
 int inerse_key = ik(k);
 if(inerse_key != -1){
     for(int i=0;i<p.size();i++)
     {
         if(isalpha(p[i]))
         {
             char c= toupper(p[i]);

             ci += ((c- 'A')*k )%26 + 'A';
         }
     }

     for(int i=0;i<ci.size();i++)
     {
         if(isalpha(ci[i]))
         {
             char c= tolower(ci[i]);

             p1 += ((c- 'a')*inerse_key  +26)%26 + 'a';
         }
     }

     cout<<ci<<endl;
     cout<<p1;
 }
 else{
    goto z;
 }
}
*/



