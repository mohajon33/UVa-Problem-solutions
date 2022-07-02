#include<bits/stdc++.h>

using namespace std;

bool string_cmp(const char& l, const char& r)
{
    if (tolower(l) == tolower(r))
        return l < r;
    else
        return tolower(l) < tolower(r);
}

int main()
{
    int n;
    cin >> n;

    string str;

    while (n--)
    {
        cin >> str;

        // string_cmp function use for capital letter comparison

        sort(str.begin(), str.end(), string_cmp);

        do
        {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end(), string_cmp));
    }
    return 0;
}
