#include<iostream>
#include<vector>
#include<climits>
#include<cstring>

using namespace std;

long long int dp[105][105];
long long int g(vector<int> &colors, int i, int j){
    long long int result = 0;
    for(int m=i; m <= j; m++){
        result = (result%100 + colors[m]%100) % 100;
    } 
    return result;
}
long long int f(vector<int> &colors, int i, int j){
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    long long int result = INT_MAX;
    for(int k=i; k<=j-1; k++){
        result = min(result, f(colors,i,k) + f(colors,k+1,j) + g(colors, i, k) * g(colors,k+1,j));
    }
    return dp[i][j] = result;
}

int main(){
    int n;
    while(cin>>n){
        vector<int> colors;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            colors.push_back(x);
        }
        memset(dp,-1,sizeof dp);
        cout<<f(colors, 0, colors.size()-1)<<"\n";
            colors.clear();
            
    }
    return 0;
}