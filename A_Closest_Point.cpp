#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i];      
        }
        if (n == 2 && points[1] - points[0] >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
 
    return 0;
}