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
        char c;
        cin>>c;
        string s;
        cin>>s;
        string temp = s + s;
        vector<int> pos_c, pos_g;
        for(int i=0; i<2*n; i++){
            if(temp[i] == c){
                pos_c.push_back(i);
            }
            if(temp[i] == 'g'){
                pos_g.push_back(i);
            }
        }
        int ans = 0;
        for(int it : pos_c){
            auto green = lower_bound(pos_g.begin(), pos_g.end(), it);
            if(green != pos_g.end()){
                ans = max(ans, *green - it);
            }           
        }
        cout<<ans<<endl;
    }

    return 0;
}