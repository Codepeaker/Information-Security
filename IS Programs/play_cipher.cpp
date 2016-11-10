//input
//hidethegoldinthetreestump
//output
//BM OD ZB XD NA BE KU DM UI XM MO UV IF

#include <iostream>
using namespace std;

string encryption(string input);
string changeEncryptAccordTheKey(string input,int row,int col,int row1,int col1,int inputindex);

string decryption(string encryptedString);
string changeDecryptAccordTheKey(string decrypt, int r1,int c1,int r2,int c2,int decryptIndex);
char key[5][5] = {{'p','l','a','y','f'},{'i','r','e','x','m'},{'b','c','d','g','h'},{'k','n','o','q','s'},{'t','u','v','w','z'}};
int main(){

	string s;
	cout<<"Enter the String : ";
	getline(cin,s);

	for(int i=0;i<s.size();i++){
		if(i+1!=s.size()){
				if(s[i]==s[i+1]){
					s = s.substr(0,i+1)+"x"+s.substr(i+1,s.size()-+(i+1));
				}
		}
		else{
			break;
		}
	}

    string encryptedString = encryption(s);

	cout<<"\n\nEncrypted Playcipher Text : "<<encryptedString;

    //Decryption
    string decryptedString = decryption(encryptedString);

    cout<<"\n\nDecrypted PlayCipher Text : "<<decryptedString;



}
string encryption(string input){
    int r1,c1,r2,c2;
    int inputindex = 0;
    while(inputindex <= input.size()-1){
        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(key[i][j]==input[inputindex]){
                r1 = i;
                c1 = j;
                inputindex++;
                i=5;
                break;

            }
        }
        }

        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(key[i][j]==input[inputindex]){
                r2 = i;
                c2 = j;
                inputindex++;
                i=5;
                break;
            }

        }
        }

    input = changeEncryptAccordTheKey(input,r1,c1,r2,c2,inputindex);


    }
    return input;

}


string changeEncryptAccordTheKey(string input,int row,int col,int row1,int col1,int inputindex){

		if(row==row1){
				input[inputindex-2]= key[row][col+1];
				input[inputindex-1]= key[row1][col1+1];
		}
		else if(col == col1){

			input[inputindex-2] = key[row+1][col];
			input[inputindex-1] = key[row1+1][col];
		}
		else{
			input[inputindex-2]= key[row][col1];
			input[inputindex-1] =key[row1][col];
		}
		//cout<<"\noutput : "<<input<<endl;
	return input;
}

string decryption(string encryptedString){
    int r1,c1,r2,c2;
    int encryptindex =0;
    while(encryptindex  <= encryptedString.size()-1){
        for(int i =0 ; i<5 ; i++){
            for(int j=0; j<5;j++){
                if(encryptedString[encryptindex] == key[i][j]){
                    r1 = i;
                    c1 = j;
                    encryptindex++;
                    i=5;
                    break;
                }
            }
        }

        for(int i =0 ; i<5 ; i++){
            for(int j=0; j<5;j++){
                if(encryptedString[encryptindex] == key[i][j]){
                    r2 = i;
                    c2 = j;
                    encryptindex++;
                    i=5;
                    break;
                }
            }
        }

    encryptedString = changeDecryptAccordTheKey(encryptedString,r1,c1,r2,c2,encryptindex);
    }
    return encryptedString;
}

string changeDecryptAccordTheKey(string decrypt, int r1,int c1,int r2,int c2,int encryptIndex){

        if(r1 == r2){
				decrypt[encryptIndex-2]= key[r1][c1-1];
				decrypt[encryptIndex-1]= key[r2][c2-1];
		}
		else if(c1 == c2){

			decrypt[encryptIndex-2] = key[r1-1][c1];
			decrypt[encryptIndex-1] = key[r2-1][c2];
		}
		else{
			decrypt[encryptIndex-2]= key[r1][c2];
			decrypt[encryptIndex-1] =key[r2][c1];
		}
		//cout<<"\noutput : "<<decrypt<<endl;
	return decrypt;


}
