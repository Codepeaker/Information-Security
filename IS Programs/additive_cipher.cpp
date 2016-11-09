//Vishal Gosain (16024)


#include<iostream>
#include<string.h>

using namespace std;
class additive{
  public:
    char msg[100];
    int key;
    void addmsg(){
      cout<<"\nEnter the message: \n";
      cin>>msg;
    }
    void addkey(){
      cout<<"\nEnter the key: \n";
      cin>>key;
    }
    void encrypt(){
      char enkey;
      int len = strlen(msg);
      cout<<"Encrypted Message is: ";
      for(int i=0;i<len;i++){

        int code = msg[i];
        if(code>=97 && code<=122){code = ((code-97)+key)%26;enkey = code+97;}
        else if(code>=65 && code<=90){code = ((code-65)+key)%26;enkey = code+65;}

        cout<<enkey;
      }
      cout<<endl;
    }
      void decryp(){
        char dkey;
        int len = strlen(msg);
        cout<<"Decrypted Message is: ";
        for(int i=0;i<len;i++){

          int code = msg[i];
          if(code>=97 && code<=122){code = ((code-97)-key)%26;if(code<0){code+=26;}dkey = code+97;}
          else if(code>=65 && code<=90){code = ((code-65)-key)%26;if(code<0){code+=26;}dkey = code+65;}

          cout<<dkey;
        }
        cout<<endl;
    }
};
int main()
{
  additive a;
  char inp;
  a.addmsg();
  a.addkey();
  a.encrypt();
  cout<<"Decrypt ? (Y/n): ";
  cin>>inp;
  if(inp == 'Y' || inp == 'y'){
    a.addmsg();
    a.decryp();
  }
  else if(inp =='N' || inp == 'n'){cout<<"Thank You";}



}
