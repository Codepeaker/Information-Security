//Vishal Gosain(16024)

#include<iostream>
#include<string.h>

using namespace std;
class hill{
  public:
    int msg[4][4];
    int c[4][4];
    int key[4][4]={{9,7,11,13},{4,7,5,6},{2,21,14,9},{3,23,21,8}};
    int inv[4][4]={{2,15,22,3},{15,0,19,3},{9,9,3,11},{17,0,4,7}};
    char a[20],p,q;
    int l,i,j,k,code;
    void addmsg(){
      l = 0;
      cout<<"\nEnter the message: \n";
      cin>>a;
      int len = strlen(a);
      for(i=0;i<4;i++)
      {
        for(j=0;j<4;j++)
        {
          code = a[l];

          if(l<len&&code>=97&&code<=122){msg[i][j]=code-97;}
          else if(l<len&&code>=65&&code<=90){msg[i][j]=code-65;}
          else if(l>=len){msg[i][j] = 25;}
          l++;

        }
        cout<<endl;
      }


      }

    void encrypt(){


      cout<<"Encrypted Message is: \n";

        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
            {
              c[i][j]=0;
              for(k=0;k<4;++k)
              {c[i][j]=c[i][j]+(msg[i][k]*key[k][j]);}

            }

        }

        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
            {
              c[i][j]=c[i][j]%26;
              p = c[i][j]+97;
              cout<<p;
            }

        }
        cout<<endl;
    }
    void decryp(){

            cout<<"Decrypted Message is: \n";

              for(i=0;i<4;++i)
              {
                  for(j=0;j<4;++j)
                  {
                    c[i][j]=0;
                    for(k=0;k<4;++k)
                    {c[i][j]=c[i][j]+(msg[i][k]*inv[k][j]);}

                  }

              }

              for(i=0;i<4;++i)
              {
                  for(j=0;j<4;++j)
                  {
                    c[i][j]=c[i][j]%26;
                    q = c[i][j]+97;
                    if(q!='z')
                    cout<<q;
                  }

              }
              cout<<endl;
    }
};
int main()
{
  hill h;
  char inp;
  h.addmsg();
  h.encrypt();
  cout<<"Decrypt ? (Y/n): ";
  cin>>inp;
  if(inp == 'Y' || inp == 'y'){
    h.addmsg();
    h.decryp();
  }
  else if(inp =='N' || inp == 'n'){cout<<"Thank You";}



}
