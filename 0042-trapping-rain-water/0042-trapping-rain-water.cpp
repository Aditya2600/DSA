// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int leftMax = 0;
//         vector<int> rightMax(n);

//         rightMax[n-1] = height[n-1];
//         int ans = 0;

//         for(int i=n-2; i>=0; i--){
//             rightMax[i] = max(height[i], rightMax[i+1]);
//         }
//         for(int i=0; i<n; i++){
//             leftMax = max(leftMax, height[i]);
//             ans += (min(leftMax, rightMax[i]) - height[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int a = 0;
        int b = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int total = 0;
        while (a < b) {
            leftMax = max(leftMax, height[a]);
            rightMax = max(rightMax, height[b]);
            if(leftMax < rightMax){
                total += (leftMax - height[a]);
                a++;
            }
            else{
                total += (rightMax - height[b]);
                b--;
            }
        }
        return total;
    }
};