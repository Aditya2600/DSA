#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

int main()
{
    fast_io;

        int n, d;
        cin >> n >> d;
        vector<int> p(n);
        rep(i, 0, n) cin >> p[i];
        sort(p.begin(), p.end());
        int left = -1;
        int right = n - 1;
        int team_size = 1;
        int teams = 0;
        while (left < right)
        {
            if ((p[right] * team_size) <= d && left < right)
            {
                left++;
                team_size++;
            }
            else
            {   
                teams++;
                right--;
                team_size = 1;
            }
        }
        cout << teams << endl;
    

    return 0;
}