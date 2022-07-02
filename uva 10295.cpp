#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, value;
    string word;
    map <string, int> mp;

    cin >> m >> n;

    // creating a index with word and dollar value by map
    while(m--){
        cin >> word >> value;
        mp[word] = value;
    }

    while(n--){
        int sum=0;
        word = "";
        while(word!="."){
            cin >> word;
            // calculating sum of value according to index string
            sum += mp[word];
        }
        cout << sum << endl;
    }
    return 0;
}
