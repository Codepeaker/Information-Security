//Vishal Gosain (16024)

#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class rabin{
  public:
    int msg;
    int enkey;
    int p,q;
    int n;
    int p1,p2,p3,p4;
    double a1,a2,b1,b2;

    rabin(){
      p =23;
      q = 7;
      n =p*q;
    }
    void addmsg(){
      cout<<"\nEnter the message(Integer): \n";
      cin>>msg;
    }
    int inverse(int k,int l){
      int r1,r2,r,q,t1,t2,t;
      r1=l;r2=k;
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
        t1+=l;
        return t1;
      }


    }

    void encrypt(){


      cout<<"Encrypted Message is: ";
      enkey = (msg*msg)%n;
      cout<<enkey;
      cout<<endl;
    }

    void decryp(){

        cout<<"Decrypted Message is(choose from the following options): \n";

        a1 = pow(enkey,(p+1)/4);
        a1 = fmod(a1,p);

        a2 = -pow(enkey,(p+1)/4);
        a2 = fmod(a2,p);
        a2+=p;

        b1 = pow(enkey,(q+1)/4);
        b1 = fmod(b1,q);

        b2 = -pow(enkey,(q+1)/4);
        b2 = fmod(b2,q);
        b2+=q;

        p1 = ch_rem(a1,b1,p,q);
        p2 = ch_rem(a1,b2,p,q);
        p3 = ch_rem(a2,b1,p,q);
        p4 = ch_rem(a2,b2,p,q);
        cout<<p1<<","<<p2<<","<<p3<<","<<p4<<endl;

    }
    int ch_rem(int x1,int x2,int m1,int m2)
    {
      int f;
      int M,M1,M2;
      M = m1*m2;
      M1 = M/m1;
      M2 = M/m2;
      int m1i = inverse(M1,m1);

      int m2i = inverse(M2,m2);

      f = ((x1*M1*m1i)+(x2*M2*m2i))%M;

      return f;
    }
};
int main()
{
  rabin ra;
  char inp;
  ra.addmsg();

  ra.encrypt();
  cout<<"Decrypt ? (Y/n): ";
  cin>>inp;
  if(inp == 'Y' || inp == 'y'){

    ra.decryp();
  }
  else if(inp =='N' || inp == 'n'){cout<<"Thank You";}



}
