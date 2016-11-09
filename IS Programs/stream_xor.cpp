//Vishal Gosain (16024)

#include<iostream>
#include<string.h>

using namespace std;
class stream{
  public:
    char msg[20];
    char key[20];
    char enkey[20];
    char dkey[20];
    void addmsg(){
      cout<<"\nEnter the message: \n";
      cin>>msg;
    }
    void addkey(){
      cout<<"\nEnter the key: \n";
      cin>>key;
    }
    void encrypt(){

      int len = strlen(msg);
      int keylen = strlen(key);
      cout<<"Encrypted Message is: ";
      for(int i=0;i<len;i++){

        enkey[i] = msg[i]^key[i%keylen];

        cout<<enkey[i];
      }
      cout<<endl;
    }
      void decryp(){

        int len = strlen(msg);
        int keylen = strlen(key);
        cout<<"Encrypted Message is: ";
        for(int i=0;i<len;i++){

          dkey[i] = enkey[i]^key[i%keylen];

          cout<<dkey[i];
        }
        cout<<endl;
    }
};
int main()
{
  stream a;
  char inp;
  a.addmsg();
  a.addkey();
  a.encrypt();
  cout<<"Decrypt ? (Y/n): ";
  cin>>inp;
  if(inp == 'Y' || inp == 'y'){
    a.decryp();
  }
  else if(inp =='N' || inp == 'n'){cout<<"Thank You";}



}
