#include<bits/stdc++.h>

using namespace std;

typedef pair <int, int> pairs;

int main()
{
    int n, m, t, pr;
    deque <pairs> dq1;
    deque <int> dq2;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> pr;
            dq1.push_back({i, pr});
            dq2.push_back(pr);
        }

        int cnt=0, flag=0;
        for(int i=9; i>0; i--){
            while(find(dq2.begin(), dq2.end(), i)!=dq2.end()){
                for(pairs &it : dq1){
                    if(it.second == i){
                        dq1.pop_front();
                        dq2.pop_front();
                        cnt++;
                        if(it.first==m)
                            flag=1;
                        break;
                    }
                    else{
                        dq1.push_back(it);
                        dq1.pop_front();
                        dq2.push_back(it.second);
                        dq2.pop_front();
                    }
                }
                if(flag==1)
                   break;
            }
            if(flag==1)
                break;
        }

        cout << cnt << endl;
        dq1.clear();
        dq2.clear();
    }
    return 0;
}
