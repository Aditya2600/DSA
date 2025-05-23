class Solution {
public:
    long long int m = 1337;
    long long int get_num(vector<int> &b){
        long long int sum = 0;
        int n = b.size();
        int ten = 1;
        
        for(int i=n-1; i>=0; i--){
            sum += (b[i] * ten) % 1140;
            ten = (ten*10)%1140;
        }
        return sum;
    }

    long long bin_exp(long long a, long long b, long long m){
        
        long long ans = 1;
        while(b > 0){
            if(b & 1){
                ans = (ans * a) % m;
            }
            a = (a*a)%m;
            b >>= 1;
        }
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        long long num = get_num(b);
        if(num == 0) return 1;
        if(num == 1) return a;
        return bin_exp(a, num, m);
    }
};