#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l1,r1;
        cin>>l1>>r1;
        int l2,r2;
        cin>>l2>>r2;
        int L = max(l1,l2), R = min(r1,r2);
        if(R<L){
            cout<<1<<endl;
            continue;
        }
        int ans = R-L;
        if(l1 < L || l2 < L){
            ans++;
        }
        if(r1 > R || r2 > R){
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}