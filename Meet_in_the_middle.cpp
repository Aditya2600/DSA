#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void findSum(vector<int> &v, int l, int r, unordered_map<int,int>& m, int sum_so_far, int x){
    if(sum_so_far > x) return;
    if(l > r || sum_so_far == x){
        m[sum_so_far]++;
        return;
    }
    findSum(v, l+1, r, m, sum_so_far, x);
    if(sum_so_far <= x - v[l]){
        findSum(v, l+1, r, m, sum_so_far + v[l], x);
    }
}
long long findResult(vector<int> &v, int x){
    unordered_map<int,int> freq1;
    freq1.reserve(1<<20);
    findSum(v, 0, v.size()/2 - 1, freq1, 0, x);

    unordered_map<int,int> freq2;
    freq2.reserve(1<<20);
    findSum(v, v.size()/2, v.size()-1, freq2, 0, x);

    long long ans = 0;
    for(auto it:freq1){
        int f2 = x - it.first;
        if(freq2.find(f2) != freq2.end()){
            ans += 1ll * it.second * freq2[f2];
        }
    }
    return ans;
}
int main(){
    int n,x;
    scanf("%d %d", &n, &x);
    vector<int> v;
    for(int i=0; i<n; i++){
        int y;
        scanf("%d", &y);
        v.push_back(y);
    }
    printf("%lld\n", findResult(v,x));
    return 0;
}