#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;

    while(cin >> n)
    {
        queue <int> q;
        stack <int> s;
        priority_queue <int> pq;
        bool bq = true, bs = true, bpq = true;

        while(n--)
        {
            cin >> a >> b;

            if(a==1)
            {
                q.push(b);
                s.push(b);
                pq.push(b);
            }
            else
            {
                if(bq)
                {
                    if(q.empty() || q.front() != b)
                        bq = false;
                    else
                        q.pop();
                }
                if(bs)
                {
                    if(s.empty() || s.top() != b)
                        bs = false;
                    else
                        s.pop();
                }
                if(bpq)
                {
                    if(pq.empty() || pq.top() != b)
                        bpq = false;
                    else
                        pq.pop();
                }
            }
        }
        if(!bq && !bs && !bpq)
            cout << "impossible" << endl;
        else if(bq && !bs && !bpq)
            cout << "queue" << endl;
        else if(!bq && bs && !bpq)
            cout << "stack" << endl;
        else if(!bq && !bs && bpq)
            cout << "priority queue" << endl;
        else
            cout << "not sure" << endl;
    }
    return 0;
}
