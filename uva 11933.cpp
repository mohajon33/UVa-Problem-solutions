#include<bits/stdc++.h>

using namespace std;

int arr[100];

string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

string splitting(int start, int len)
{
    string str="";
    int j=start;

    //creating binary for odd or even indices
    for(int i=0; i<len; i++){
        if(arr[i]==j){
            str += "1";
            j += 2;
        }
        else
            str += "0";
    }
    return str;
}

int toDecimal(string n)
{
    string num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

int countingOne(string str)
{
    int cnt=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='1')
            cnt++;
    }
    return cnt;
}

int main()
{
    int n;
    while(cin >> n){
        if(n==0)
           break;

        string bin = toBinary(n);
        int len = bin.size();
        int j=0;

        //creating a array based on index of only "1"
        for(int i=0; i<len; i++){
            if(bin[i]=='1')
                arr[i]=j++;
            else
                arr[i]=-1;
        }

        string a = splitting(1, len);
        string b = splitting(0, len);

        if(countingOne(a) < countingOne(b))
            cout << toDecimal(b) << " " << toDecimal(a) << endl;
        else
            cout << toDecimal(a) << " " << toDecimal(b) << endl;
    }
    return 0;
}
