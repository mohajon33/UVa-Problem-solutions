#include<bits/stdc++.h>
#include<map>

using namespace std;

int main()
{
    string str;
    map <string, string> m;

    getline(cin, str);

    while(str!=""){
        int i, l;
        string str1, str2;

        // first word stored by a string str1
        for(i=0; str[i]!=' '; i++)
            str1 += str[i];

        // second word stored by an another string
        for(int j=i+1; str[j]!='\0'; j++)
            str2 += str[j];

        // use of map where key is second word
        m[str2] = str1;

        getline(cin, str);

    }

    while(cin >> str){
        if(m[str].empty())
            cout << "eh" << endl;
        else
            cout << m[str] << endl;
    }

    return 0;
}
