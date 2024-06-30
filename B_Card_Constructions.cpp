#include <iostream>
#include <vector>
#include <algorithm> // For upper_bound

using namespace std;

int berlin(vector<int>& arr) {
    int n;
    cin >> n;
    int c = 0;
    while (n > 0) {
        auto it = upper_bound(arr.begin(), arr.end(), n);
        if (it == arr.begin()) {
            break; 
        }
        --it; 
        c++;
        n -= *it;
    }
    return c;
}

int main() {
    int t; 
    cin >> t;

    vector<int> arr;
    int i = 2;
    int ans = 2;
    while (ans <= 1e9) {
        arr.push_back(ans);
        ans += ((3 * i) - 1);
        i++;
    }

    while (t--) {
        cout << berlin(arr) << endl;
    }
    
    return 0;
}