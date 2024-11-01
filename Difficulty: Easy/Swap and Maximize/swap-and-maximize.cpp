//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
       int n = arr.size();
    if (n == 1) return 0; // Edge case: if only one element, no consecutive difference

    // Sort the array
    std::sort(arr.begin(), arr.end());

    // Rearrange the array by alternating smallest and largest elements
    std::vector<int> rearranged;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (left == right) {
            rearranged.push_back(arr[left]);
        } else {
            rearranged.push_back(arr[left]);
            rearranged.push_back(arr[right]);
        }
        left++;
        right--;
    }

    // Calculate the maximum sum of absolute differences in the circular arrangement
    long long max_sum = 0;
    for (int i = 0; i < n; ++i) {
        max_sum += std::abs(rearranged[i] - rearranged[(i + 1) % n]);
    }

    return max_sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends