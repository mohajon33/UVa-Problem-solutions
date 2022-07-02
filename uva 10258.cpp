#include<bits/stdc++.h>

using namespace std;

struct data
{
    int id, s, t;
};

bool cmp(data a, data b)
{
    if(a.s == b.s){
        if(a.t == b.t)
            return a.id < b.id;
        else
            return a.t < b.t;
    }
    return a.s > b.s;
}

int main()
{
    int n;

    cin >> n;

    getchar();getchar();

    while(n--){
        int solved[150]={0}, time[150][15]={0}, penalty[150]={0};
        bool correct[150][15] = {{false}}, present[150]={false};

        //contestant number, problem number, time, result
        int c_n, p_n, tm;
        char rst;
        string s;
        while(getline(cin, s)){
            if(s == "")
                break;

            stringstream ss(s);
            ss >> c_n >> p_n >> tm >> rst;

            // if problem is unsolved then find out penalty time and
            //the number of solved problem for each contestant
            if(!correct[c_n][p_n]){
                if(rst=='I'){
                    time[c_n][p_n] += 20;
                }
                else if(rst == 'C'){
                    time[c_n][p_n] += tm;
                    penalty[c_n] += time[c_n][p_n];
                    solved[c_n]++;
                    correct[c_n][p_n] = true;
                }
                present[c_n] = true;
            }
        }
        vector <data> v;
        for(int i=1; i<=100; i++){
            if(present[i]){
                v.push_back({i, solved[i], penalty[i]});
            }
        }
        // sorting vector by cmp function
        sort(v.begin(), v.end(), cmp);

        for(data x : v)
            cout << x.id << " " << x.s << " " << x.t << endl;

        if(n!=0)
            cout << endl;
    }
    return 0;
}
