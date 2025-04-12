class Solution {
public:
    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    int f(int n) {
        if(isPrime(n)) return n;  // check if n is prime first

        int sum = 0;
        int num = n;
        for(int i = 2; i * i <= num; i++){
            while(num % i == 0){
                sum += i;
                num /= i;
            }
        }
        if(num > 1) sum += num; // if num is still greater than 1, it itself is a prime factor
        if(sum == n) return n;
        return f(sum);
    }

    int smallestValue(int n) {
        return f(n);
    }
};