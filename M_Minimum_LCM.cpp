#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

int hcf(int a, int b){
    if(b == 0) return a;
    return hcf(b, a%b);
}
int lcm(int a, int b){
    return (a*b)/hcf(a,b);
}
int main() {
    fast_io;
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long ans_a = 1;
        long long ans_b = n-1;
        for(long long fact = 2; fact*fact<=n; fact++){
            if(n % fact == 0){
                ans_a = n/fact;
                ans_b = n - ans_a;
                break;
            }
        }
        cout<<ans_a<<" "<<ans_b<<endl;
        // int minLcm = lcm(1, n-1);
        // pair<long long, long long> pr = {1, n-1};

        //     for(long long i=2; i<=n/2; i++){
        //         long long LCM = lcm(i, n-i);
        //         if(LCM < minLcm){
        //             minLcm = LCM;
        //             pr = {i, n-i};
        //         }
                
        //     }
        // cout<<pr.first<<" "<<pr.second<<endl;
    }

    return 0;
}