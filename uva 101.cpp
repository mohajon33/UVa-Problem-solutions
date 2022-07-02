#include<bits/stdc++.h>

using namespace std;

int a, b, n, x, y;
string first, second;
array <list <int>, 30> block;
list <int>::iterator itx, ity;

bool illegal()
{
    if(a==b)
        return true;

    for(int i=0; i<n; i++)
    {
        auto ita = find(block[i].begin(), block[i].end(), a);
        auto itb = find(block[i].begin(), block[i].end(), b);

        if(ita!=block[i].end() && itb!=block[i].end())
            return true;
    }
    return false;
}

void find_stack()
{
    list <int>:: iterator ita, itb;

    for(int i=0; i<n; i++)
    {
        ita = find(block[i].begin(), block[i].end(), a);
        itb = find(block[i].begin(), block[i].end(), b);

        if(ita!=block[i].end())
        {
            x = i;
            itx = ita;
        }
        if(itb!=block[i].end())
        {
            y = i;
            ity = itb;
        }
    }
}

void back_initial_posi(list <int>::iterator itm, int m)
{
    //transfer element to their initial position
    auto it = itm++;
    for(it = itm; it!=block[m].end(); it++)
        block[*it].push_back(*it);

    it = block[m].end();
    block[m].erase(itm, it);
}

int main()
{
    cin >> n;

    for(int i=0; i<n; i++)
        block[i].push_back(i);

    while(cin >> first)
    {
        if(first=="quit")
            break;

        cin >> a >> second >> b;

        if(illegal())
            continue;

        find_stack();// for a and b

        if(first=="move" && second=="onto")
        {
            back_initial_posi(ity, y);
            block[y].push_back(a);
            back_initial_posi(itx, x);
            block[x].erase(itx);
        }
        else if(first=="move" && second=="over")
        {
            block[y].push_back(a);
            back_initial_posi(itx, x);
            block[x].erase(itx);
        }
        else if(first=="pile" && second=="onto")
        {
            back_initial_posi(ity, y);

            for(list <int>::iterator it = itx; it!=block[x].end(); it++)
                block[y].push_back(*it);

            auto it = block[x].end();
            block[x].erase(itx, it);
        }
        else
        {
            for(list <int>::iterator it = itx; it!=block[x].end(); it++)
                block[y].push_back(*it);

            auto it = block[x].end();
            block[x].erase(itx, it);
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << i << ":";
        for(auto x : block[i])
            cout << " " << x ;
        cout << endl;
    }

    return 0;
}
