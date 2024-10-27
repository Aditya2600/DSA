//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> AllPrimeFactors(int N) {
        set<int> list; // Use set to maintain increasing order
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                if (isPrime(i)) list.insert(i);
                if (i != N / i && isPrime(N / i)) list.insert(N / i);
            }
        }
        if (isPrime(N)) list.insert(N); // Include N if it's prime
        return vector<int>(list.begin(), list.end());
    }

private:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends