#include<bits/stdc++.h>

using namespace std;

int main()
{
    double n;
    cin >> n;
    while(n--){
        double l, w, r, rec, cir;
        cin >> l;
        w = (l*6)/10;
        rec = l * w;
        cir = (12.57*rec)/60;
        cout << fixed << setprecision(2)<< cir << " " << rec - cir<< endl;
    }
    return 0;
}
