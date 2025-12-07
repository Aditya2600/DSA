class Solution {
public:
    int digitCount(int num){
        int cnt = 0;
        if(num == 0) return 1;
        while(num > 0){
            num /= 10;
            cnt++;
        }
        return cnt;
    }
    bool isPrime(int num){
        if(num < 2) return false;
        for(int i=2; i*i <= num; i++){
            if(num % i == 0){
                return false;
            }
        }       
        return true;
    }
    bool completePrime(int num) {
        if(!isPrime(num)) return false;
        int digits = digitCount(num);
        int pow10 = 1;
        for(int i = 1; i < digits; i++){
            pow10 *= 10;
        }
        int pre;
        int tmpPow = pow10;
        while(tmpPow > 0){      
            pre = num / tmpPow;
            if(!isPrime(pre)){
                return false;
            }
            tmpPow /= 10;
        }
        int sufPow = 10;
        while(sufPow <= pow10 * 10){           
            int suf = num % sufPow;
            if(suf > 0 && !isPrime(suf)) return false;
            sufPow *= 10;
        }
        return true;
    }
};