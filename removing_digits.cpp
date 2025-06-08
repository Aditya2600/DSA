#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'

vector<int> get_digit(int n){
    vector<int> res;
    while(n > 0){
        if(n%10 != 0){
            res.pb(n%10);
        }
        n /= 10;
    }
    return res;
}
vector<int> dp;
int f(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;
    if(dp[n] != -1) return dp[n];
    int result = INT_MAX;
    vector<int> d = get_digit(n);
    for(int i = 0; i<d.size(); i++){
        result = min(result, f(n - d[i]));
    }
    return dp[n] = 1 + result;
}
int fbu(int num){
    dp[0] = 0;
    for(int i=1; i<10; i++){
        dp[i] = 1;
    }
    for(int n=10; n<num; n++){
        dp[n] = INT_MAX;
        vector<int> d = get_digit(n);
        for(int i = 0; i<d.size(); i++){
            dp[n] = min(dp[n], dp[n - d[i]]);
        }
        dp[n] = 1 + dp[n];
    }
    return dp[num];
}
int main() {
    fast_io;
    
    int n;
    cin >> n;
    dp.resize(1000005, -1);
    cout<<f(n)<<endl;
    return 0;
}