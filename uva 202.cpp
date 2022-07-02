#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        cout << m << "/" << n << " = " << m/n << ".";

        int k=0, temp, digit[5000];
        while(k<3010)
        {
            m %= n;
            if(m<n)
            {
                m *= 10;
                while(m<n && k<3010)
                {
                    m *= 10;
                    digit[k++] = 0;
                }
            }
            temp = m / n;
            digit[k++] = temp;
        }
        int i, j, cnt=0;
        for(i=0; i<3010; i++)
        {
            for(j=i+1; j<3010; j++)
            {
                if(digit[i]==digit[j])
                {
                    int a=i, b=j;
                    cnt=0;
                    while(cnt!=5)
                    {
                        if(digit[a++]!=digit[b++])
                            break;
                        cnt++;
                    }
                    if(cnt==5)
                        break;
                }
            }
            if(cnt==5)
                break;
        }
        for(int c=0; c<j; c++)
        {
            if(c==i)
                cout << "(";
            if(c==50)
            {
                cout << "...";
                break;
            }
            else
                cout << digit[c];
        }
        cout << ")" << endl;
        cout << "   " << j-i << " = number of digits in repeating cycle" << endl << endl;
    }
    return 0;
}
