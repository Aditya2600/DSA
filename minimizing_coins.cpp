#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'

int f(vector<int>& coins, int amount, vector<int>& dp){
    if(amount == 0) return 0;
    if(dp[amount] != -2) return dp[amount];

    int result = INT_MAX;
    for(int coin : coins){
        if(amount - coin >= 0){
            int sub = f(coins, amount - coin, dp);
            if(sub != INT_MAX) result = min(result, 1 + sub);
        }
    }

    return dp[amount] = result;
}

int main() {
    fast_io;

    int n, amount;
    cin >> n >> amount;  // Number of coin types and the target amount

    vector<int> coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    vector<int> dp(amount + 1, -2);  // Only need dp till amount
    int ans = f(coins, amount, dp);

    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}