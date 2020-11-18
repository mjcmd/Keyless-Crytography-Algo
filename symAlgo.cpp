#include<bits/stdc++.h>
using namespace std;


string cipherText(string str)
{
	string cipher_text;
    int prev_char=0;
    int i=0;
	do{

		int ci = (str[i] - prev_char) + 32 ;

        if(ci<32)
        {
            ci=ci+94;

        }
        else if(ci>=126)
        {
            ci=ci-94;

        }

        cipher_text.push_back(ci);

        i++;
        prev_char= str[i-1];

	}while(i<str.size());
	return cipher_text;
}

string originalText(string cipher_text)
{
	string orig_text;
    int prev_char=0;
    int i=0;
	do{

		int pi = (cipher_text[i] - 32) + prev_char ;

        if(pi<32)
        {
            pi=pi+94;
        }
        else if(pi>=126)
        {
            pi=pi-94;
        }
        orig_text.push_back(pi);

        i++;
        prev_char=pi;

	}while(i<cipher_text.size());
	return orig_text;
}


int main()
{

	string str = "Happy";
    cout<<str<<endl;
	string cipher_text = cipherText(str);

	cout << "Ciphertext : "
		<< cipher_text << "\n";

	cout << "Original/Decrypted Text :"
		<< originalText(cipher_text);

	return 0;
}
