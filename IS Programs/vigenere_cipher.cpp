//Vishal Gosain (16024)

#include<iostream>
#include<string.h>

using namespace std;
class vignere{
  public:
    char msg[100];
    char key[100];
    void addmsg(){
      cout<<"\nEnter the message: \n";
      cin>>msg;
      cout<<"\nEnter the Key: \n";
      cin>>key;
    }

    void encrypt(){
      char enkey;
      int k=0,code1,code2;
      int lenmsg = strlen(msg);
      int lenkey = strlen(key);
      cout<<"Encrypted Message is: ";
      for(int i=0;i<lenmsg;i++){
          code1 = msg[i];
          if(code1>=97 && code1<=122){code1 = (code1-97);}
          else if(code1>=65 && code1<=90){code1 = (code1-65);}
          code2 = key[k];
          if(code2>=97 && code2<=122){code2 = (code2-97);}
          else if(code2>=65 && code2<=90){code2 = (code2-65);}
          enkey = ((code1+code2)%26)+97;

          cout<<enkey;
          k++;
          if(k==(lenkey))
          {
            k=0;
          }
        }

      cout<<endl;
    }
      void decryp(){
        char dkey;
        int k=0,code1,code2;
        int lenmsg = strlen(msg);
        int lenkey = strlen(key);
        cout<<"Decrypted Message is: ";
        for(int i=0;i<lenmsg;i++){
            code1 = msg[i];
            if(code1>=97 && code1<=122){code1 = (code1-97);}
            else if(code1>=65 && code1<=90){code1 = (code1-65);}
            code2 = key[k];
            if(code2>=97 && code2<=122){code2 = (code2-97);}
            else if(code2>=65 && code2<=90){code2 = (code2-65);}
            dkey = code1-code2;
            if(dkey<0)
            {
              dkey+=26;
            }
            dkey+=97;

            cout<<dkey;
            k++;
            if(k==(lenkey))
            {
              k=0;
            }
          }

        cout<<endl;
    }
};
int main()
{
  vignere v;
  char inp;
  v.addmsg();
  v.encrypt();
  cout<<"Decrypt ? (Y/n): ";
  cin>>inp;
  if(inp == 'Y' || inp == 'y'){
    v.addmsg();
    v.decryp();
  }
  else if(inp =='N' || inp == 'n'){cout<<"Thank You";}



}
