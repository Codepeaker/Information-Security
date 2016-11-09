//Vishal Gosain (16024)

#include<iostream>
#include<string.h>

using namespace std;
class mono{
  public:
    char msg[100];

    char txt[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char key[26]={'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'};
    void addmsg(){
      cout<<"\nEnter the message: \n";
      cin>>msg;
    }

    void encrypt(){
      char enkey;
      int len = strlen(msg);
      cout<<"Encrypted Message is: ";
      for(int i=0;i<len;i++){
        for(int k=0;k<26;k++){
          if(msg[i]==txt[k])
          {
            enkey=key[k];
            cout<<enkey;
            break;
          }
        }
      }
      cout<<endl;
    }
      void decryp(){
        char dkey;
        int len = strlen(msg);
        cout<<"Decrypted Message is: ";
        for(int i=0;i<len;i++){
          for(int k=0;k<26;k++){
            if(msg[i]==key[k])
            {
              dkey=txt[k];
              cout<<dkey;
              break;
            }
          }
        }
        cout<<endl;
    }
};
int main()
{
  mono m;
  char inp;
  m.addmsg();
  m.encrypt();
  cout<<"Decrypt ? (Y/n): ";
  cin>>inp;
  if(inp == 'Y' || inp == 'y'){
    m.addmsg();
    m.decryp();
  }
  else if(inp =='N' || inp == 'n'){cout<<"Thank You";}



}
