#include<bits/stdc++.h>
//#include<vector>

using namespace std;

string sortOfString(string str)
{
    for(int i=0; i<str.size(); i++)
        str[i]=tolower(str[i]);

    sort(str.begin(), str.end());

    return str;
}
int main()
{
    int maxx=-1;
    string str;
    vector <string> v1;
    set <string> s;


    cin >> str;

    while(str[0]!='#'){
        v1.push_back(str);
        int len = str.size();
        maxx = max(maxx, len);
        cin >> str;
    }

    vector <string> v2 = v1;
    for(int i=0; i<v2.size(); i++){
        v2[i] = sortOfString(v2[i]);
    }

    while(maxx){
        map <string, int> mp;
        for(string st : v1){
            if(st.size()==maxx){
                string s = sortOfString(st);
                mp[s]++;
            }
        }
        for (auto it = mp.begin(); it!= mp.end(); it++) {
             if(it->second == 1){
                for(int i=0; i<v2.size(); i++){
                    if(it->first == v2[i])
                        s.insert(v1[i]);
                }
             }
        }
        maxx--;
    }
    for(string x : s)
        cout << x << endl;

    return 0;
}
