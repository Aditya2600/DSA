#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define endl '\n'

ll dp[105][105];
ll g(vector<int> &colors, int i, int j)
{
    ll result = 0;
    for (int m = i; m <= j; m++)
    {
        result = (result % 100 + colors[m] % 100) % 100;
    }
    return result;
}
ll f(vector<int> &colors, int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, f(colors, i, k) + f(colors, k + 1, j) + g(colors, i, k) * g(colors, k + 1, j));
    }
    return dp[i][j] = ans;
}
int main()
{
    fast_io;

    int t;
    while (cin >> t)
    {
        vector<int> colors;
        for (int i = 0; i < t; i++)
        {
            int x;
            cin >> x;
            colors.push_back(x);
        }
        vector<vector<int>> dp(105, vector<int> (105, 0));
        vector<vector<int>> sum(105, vector<int> (105, 0));

        for(int i=0; i<t; i++){
            sum[i][i] = colors[i] % 100;
            for(int j=i+1; j<t; j++){
                sum[i][j] = (sum[i][j-1] + colors[j])%100;
            }
        }
        for (int len = 2; len <= t; len++)
        {
            for (int i = 0; i + len - 1 < t; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i][k] * sum[k + 1][j]);
                }
            }
        }
        cout << dp[0][t - 1] << "\n";
        colors.clear();
    }

    return 0;
}