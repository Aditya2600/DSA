class Solution {
public:
bool isPossible(vector<int>& stones,int k){
    //max jump you can take is  k
    if(stones.size()==2)return (stones[1]-stones[0]<=k);
    int maxi=INT_MIN;
    int n=stones.size();
    for(int i=2;i<n;i+=2){
        maxi=max(maxi,abs(stones[i]-stones[i-2]));
    }
    for(int i=3;i<n;i+=2){
        maxi=max(maxi,abs(stones[i]-stones[i-2]));
    }
    return maxi<=k;
}
    int maxJump(vector<int>& stones) {
        //Minimise the Maximum pattern of Binary Search
        int n=stones.size();
        int l=1;
        int h=(stones[n-1]-stones[0]);//max cost possible
        while(l<h){
            int mid=l+(h-l)/2;
            if(isPossible(stones,mid)){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return h;
    }
};