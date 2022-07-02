#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, flag = 0;;

    while(cin >> n)
    {
        if(flag)
            cout << endl;

        int t = n;
        string man[15];
        map <string, int> mp;

        // initialize all person have zero amount of gifts
        for(int i=0; i<n; i++)
        {
            cin >> man[i];
            mp[man[i]]=0;
        }
        while(t--)
        {
            int gift, taka, person;
            string name;

            cin >> name >> taka >> person;

            if(person==0)
                continue;

            gift = taka / person;
            //decrease total amount of gift from who give gift
            mp[name] += -(gift * person);

            // distributed gift among given person
            for(int i=0; i<person; i++)
            {
                cin >> name;
                mp[name] += gift;
            }
        }
        for(int i=0; i<n; i++)
            cout << man[i] << " " << mp[man[i]] << endl;

        flag = 1;
    }
    return 0;
}
