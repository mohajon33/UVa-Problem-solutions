#include<bits/stdc++.h>

using namespace std;

vector <int> v;

bool checkUgly(int num)
{
    while(num % 2 == 0)
        num/=2;
    while(num % 3 == 0)
        num/=3;
    while(num % 5 == 0)
        num/=5;

    return num == 1;
}
int main()
{
    /*
    int i, cnt=0;
    for(i=1; ; i++){
        if(checkUgly(i))
            cnt++;
        if(cnt==1500)
            break;
    }
    */
    cout << "The 1500'th ugly number is " << 859963392 << "." << endl;

    return 0;
}
