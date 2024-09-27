//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string& str1, string& str2) {
        string minWin = "";
        int j = 0, minLen = str1.length() + 1;
        int start = -1;
        for(int i = 0; i<str1.length(); i++){
            if(str1[i] == str2[j]){
                j++;
            }
            if(j == str2.length()){
                int end = i + 1;
                j--;
                while(j >= 0){
                    if(str2[j] == str1[i]){
                        j--;
                    }
                    i--;
                }
                i++;
                j++;
                if(end - i < minLen){
                    minLen = end - i;
                    start = i;
                }
            }
        }
        return (start == -1) ? "" : str1.substr(start, minLen); 
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends