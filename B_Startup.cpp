#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> sum(k+1,0);
    for(int i=0;i<k; i++){
        int b,c;
        cin>>b>>c;
        sum[b] += c;
        }
        sort(sum.rbegin(), sum.rend());
        int ans = 0;
        for(int i=0; i<min(n,k); i++){
            ans += sum[i];
        }
        cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}