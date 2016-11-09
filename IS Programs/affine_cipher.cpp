//Vishal Gosain (16024)

#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
class affine{
  public:
    char msg[100];
    int key1,key2;
    

    void addmsg(){
      cout<<"\nEnter the message: \n";
      cin>>msg;
    }
    void addkey(){
      cout<<"For Better results choose the first key from the following set: ";
      cout<<"{1,3,5,7,9,11,15,17,19,21,23,25}";
      cout<<"\nEnter the First key: \n";
      cin>>key1;
      cout<<"\nEnter the second key: \n";
      cin>>key2;

    }
    void encrypt(){
      char enkey;
      int len = strlen(msg);
      cout<<"Encrypted Message is: ";
      for(int i=0;i<len;i++){

        int code = msg[i];
        if(code>=97 && code<=122){code = ((code-97)*key1+key2)%26;enkey = code+97;}
        if(code>=65 && code<=90){code = ((code-65)*key1+key2)%26;enkey = code+65;}

        cout<<enkey;

      }
      cout<<endl;
    }
    int inverse(int key1){
      int r1,r2,r,q,t1,t2,t;
      r1=26;r2=key1;
      t1=0;t2=1;
      while(r2>0)
      {
        q=r1/r2;
        r=r1-q*r2;
        r1=r2;r2=r;
        t=t1-q*t2;
        t1=t2;t2=t;
      }
      if(r1==1)
      {
        if(t1<0)
        t1+=26;
        return t1;
      }


    }

      void decryp(){
        char dkey;
        int len = strlen(msg);
        int inv = inverse(key1);
        cout<<"Decrypted Message is: ";
        for(int i=0;i<len;i++){

          int code = msg[i];
          if(code>=97 && code<=122){code = (((code-97)-key2)*inv)%26;if(code<0){code+=26;}dkey = code+97;}
          else if(code>=65 && code<=90){code = (((code-65)-key2)*inv)%26;if(code<0){code+=26;}dkey = code+65;}

          cout<<dkey;
        }
        cout<<endl;
    }
};
int main()
{
  affine a;
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
