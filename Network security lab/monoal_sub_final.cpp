#include<bits/stdc++.h>
using namespace std;
int main()
{
    char p[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[]={'N','O','A','T','R','B','E','C','F','U','X','D','Q','G','Y','L','K','H','V','I','J','M','P','Z','S','W'};

    string pl,ci="",pi="", np="";
    cout<<"enter the plaintext: ";
    getline(cin,pl);

    for(int i=0; i<pl.size(); i++)
    {
       if(isalpha(pl[i]))
       {
           np += pl[i];
       }
    }

    for(int i=0;i<np.size();i++)
    {
       for(int j=0; j<26; j++)
       {
           if(p[j] == np[i])
            ci += c[j];
                  }
    }
    for(int i=0;i<ci.size();i++)
    {
       for(int j=0; j<26; j++)
       {
           if(c[j] == ci[i])
            pi += p[j];
                  }
    }
    cout<<"ciphertext: "<<ci<<endl;
    cout<<"decryptedtext : "<<pi;
}
