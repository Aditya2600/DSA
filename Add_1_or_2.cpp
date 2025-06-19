#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

bool check(const vector<ll>& a, const vector<ll>& b, ll mid, int n) {
    if (*max_element(a.begin(), a.end()) > mid) return false;

    ll c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + b[i] > mid) {
            c2 += (b[i] - (mid - a[i]));
        } else {
            c1 += (mid - a[i] - b[i]) / 2;
        }
    }
    return c2 <= c1;
}
int main() {
    fast_io;
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        ll low = 0, hi = 2e9;
        while(low < hi){
            ll mid = (low + hi)/2;
            if(check(a, b, mid, n)){
                hi = mid;
            }
            else {
                low = mid+1;
            }
        }
        cout<<low<<endl;
        // your logic here
    }

    return 0;
}