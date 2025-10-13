class Solution {
public:
    long long digits(int x) {
        long long cnt = 1;
        while (x > 0) {
            cnt *= 10;
            x /= 10;
        }
        return cnt / 10;
    }
    long long reverse(int x) {
        long long ans = 0;
        long long cnt = digits(x);
        while (x > 0) {
            long long temp = x;
            temp = temp % 10;
            ans += temp * cnt;
            cnt /= 10;
            x /= 10;
        }
        return ans;
    }
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long reversedNumber = reverse(x);
        if(reversedNumber == x){
            return true;
        }
        return false;
    }
};