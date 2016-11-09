//Vishal Gosain(16024)

#include<iostream>
#include<string.h>

using namespace std;
class trans{
  public:
    char msg[4][4];
    char c[4][4];
    int key[4],inv[4];
    char a[20],p,q;
    int l,i,j,k,code,index;
    void addmsg(){
      l = 0;
      cout<<"\nEnter the message(max 16 letters): \n";
      cin>>a;
      int len = strlen(a);

      for(i=0;i<4;i++)
      {
        for(j=0;j<4;j++)
        {


          if(l<len){msg[i][j]=a[l];l++;}
          else if(l>=len){msg[i][j] = 'z';}

        }

      }


      }
      void addmsg2(){
        l=0;
        cout<<"\nEnter the message(max 16 letters): \n";
        cin>>a;


        for(i=0;i<4;i++)
        {
          for(j=0;j<4;j++)
          {
              c[j][i] = a[l];
              l++;

          }

        }


        }
    void addkey(){
        cout<<"\nEnter the key(1-4): \n";
        for(j=0;j<4;++j)
        {
          cin>>key[j];
          key[j]=key[j]-1;
        }
    }
    void encrypt(){


      cout<<"Encrypted Message is: \n";

        for(i=0;i<4;++i)
        {
          code = key[i];
            for(j=0;j<4;++j)
            {
                c[j][i] = msg[j][code];

            }

        }

        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
            {
              cout<<c[j][i];

            }

        }
        cout<<endl;
    }
    void dkey(){
        index=0;
        while(index<4){
          inv[key[index]]=index+1;
          index+=1;
        }
    }
    void decryp(){


            cout<<"Decrypted Message is: \n";
            dkey();

              for(i=0;i<4;++i)
              {
                code = inv[i];
                  for(j=0;j<4;++j)
                  {
                      msg[j][i] = c[j][code-1];

                  }

              }

              for(i=0;i<4;++i)
              {
                  for(j=0;j<4;++j)
                  {
                    if(msg[i][j]!='z')
                    cout<<msg[i][j];

                  }

              }
              cout<<endl;
    }
};
int main()
{
  trans t;
  char inp;
  t.addmsg();
  t.addkey();
  t.encrypt();
  cout<<"Decrypt ? (Y/n): ";
  cin>>inp;
  if(inp == 'Y' || inp == 'y'){
    t.addmsg2();
    t.addkey();
    t.decryp();
  }
  else if(inp =='N' || inp == 'n'){cout<<"Thank You";}



}
