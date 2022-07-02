#include<bits/stdc++.h>

using namespace std;

int m, n, numbr[11][110], cost[11][110], path[11][110];

int directory(int i, int j)
{
    if (j >= n)
        return 0;
    if (cost[i][j] != INT_MAX)
        return cost[i][j];

    int tri[3] = {i-1, i, i+1};
    if(i==0)
        tri[0]=m-1;
    if(i==m-1)
        tri[2]=0;

    for(int k=0; k<3; k++)
    {
        int temp = numbr[i][j] + directory(tri[k], j+1);
        if (cost[i][j] > temp || (cost[i][j] == temp && path[i][j] > tri[k]))
        {
            cost[i][j] = temp;
            // Store direction when cost matrix is updated.
            path[i][j] = tri[k];
        }
    }
    return cost[i][j];
}

int main()
{
    while(cin >> m >> n)
    {
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                cin >> numbr[i][j];
                cost[i][j] = INT_MAX;
            }


        int row=0, minn = INT_MAX;
        for(int i=0; i<m; i++)
        {
            directory(i, 0);
            if(minn > cost[i][0])
            {
                minn = cost[i][0];
                row = i;
            }
        }


        for(int i=0; i<n; i++)
        {
            if(i==0)
                cout << row+1;
            else
                cout << " " <<row+1;
            row =  path[row][i];
        }

        cout << endl;
        cout << minn << endl;

    }
    return 0;
}
