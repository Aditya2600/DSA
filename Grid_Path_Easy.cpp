#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define endl '\n'

int main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        string s[2];
        for (int i = 0; i < 2; i++)
        {
            cin >> s[i];
        }

        vector<ll> pre(n, -1), post(n, -1);
        vector<ll> pos[2];

        // collect positions of '1'
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i][j] == '1')
                {
                    pos[i].push_back(j);
                }
            }
        }

        // If either string has no '1', answer is -1
        if (pos[0].empty() || pos[1].empty())
        {
            cout << -1 << endl;
            continue;
        }

        // Build pre[]
        for (int i = 0; i < pos[0].size(); i++)
        {
            if (i == 0)
                pre[pos[0][i]] = pos[0][i];
            else
                pre[pos[0][i]] = pre[pos[0][i - 1]] + pos[0][i] - i;
        }

        // Build post[]
        for (int i = pos[1].size() - 1; i >= 0; i--)
        {
            if (i == pos[1].size() - 1)
                post[pos[1][i]] = n - 1 - pos[1][i];
            else
                post[pos[1][i]] = post[pos[1][i + 1]] + pos[1][i + 1] - pos[1][i] - 1;
        }

        // Find minimum pre[i] + post[i]
        ll ans = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            if (pre[i] != -1 && post[i] != -1)
            {
                ans = min(ans, pre[i] + post[i]);
            }
        }

        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    }

    return 0;
}