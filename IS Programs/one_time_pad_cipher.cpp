//Vishal Gosain (16024)

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class one{
  public:
    char msg[100];
    int k,key[100];
    void addmsg(){
      cout<<"\nEnter the message: \n";
      cin>>msg;
      int len = strlen(msg);
      for(int i=0;i<len;i++)
      {
        key[k] = rand()%27;
        k++;
      }


    }

    void encrypt(){
      char enkey;
      k = 0;
      int len = strlen(msg);
      cout<<"Encrypted Message is: ";
      for(int i=0;i<len;i++){

        int code = msg[i];
        if(code>=97 && code<=122){code = ((code-97)+key[k])%26;k++;enkey = code+97;}
        else if(code>=65 && code<=90){code = ((code-65)+key[k])%26;k++;enkey = code+65;}

        cout<<enkey;
      }
      cout<<endl;
    }
      void decryp(){
        char dkey;
        k = 0;
        int len = strlen(msg);
        cout<<"Decrypted Message is: ";
        for(int i=0;i<len;i++){

          int code = msg[i];
          if(code>=97 && code<=122){code = ((code-97)-key[k])%26;k++;if(code<0){code+=26;}dkey = code+97;}
          else if(code>=65 && code<=90){code = ((code-65)-key[k])%26;k++;if(code<0){code+=26;}dkey = code+65;}

          cout<<dkey;
        }
        cout<<endl;
    }
};
int main()
{
  one a;
  char inp;
  a.addmsg();

  a.encrypt();
  cout<<"Decrypt ? (Y/n): ";
  cin>>inp;
  if(inp == 'Y' || inp == 'y'){
    a.addmsg();
    a.decryp();
  }
  else if(inp =='N' || inp == 'n'){cout<<"Thank You";}



}
