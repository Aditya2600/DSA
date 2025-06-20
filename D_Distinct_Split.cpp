#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

int main() {
    fast_io;
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin>>s;
        unordered_set<char> st;
        vector<long long> pre(n+1, 0);
        vector<long long> suff(n+1, 0);
        for(int i=1; i<=n; i++){
            st.insert(s[i-1]);
            pre[i] = st.size();
        }
        st.clear();
        for(int j=n; j>=1; j--){
            st.insert(s[j-1]);
            suff[j] = st.size();
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, pre[i] + suff[i+1]);
        }
        cout<<ans<<endl;
    }

    return 0;
}