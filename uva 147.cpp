#include<bits/stdc++.h>

using namespace std;

unsigned long long int possible[30010];
int main()
{
    int coin[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

    possible[0] = 1;

    for(int i=10; i>=0; i--){
        for(int j=coin[i]; j<30001; j++){
            possible[j] += possible[j-coin[i]];
        }
    }

    double n;
    while(cin >> n){
        if(n==0)
            break;
        int m = (n + 0.001) * 100.00;
        cout << fixed << setprecision(2) << setw(6) << n << setw(17) << possible[m] << endl;
    }

    return 0;
}
