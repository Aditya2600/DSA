#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp; // Initialize the compressed string
        int n = word.size(); // Get the length of the input string

        int i = 0; // Index for traversing the input string
        while (i < n) {
            char c = word[i]; // Get the current character
            int count = 0; // Initialize the count of the current character
            
            // Count how many times the character c appears consecutively
            while (i < n && word[i] == c && count < 9) {
                count++;
                i++;
            }
            
            // Append the count and character to the compressed string
            comp += to_string(count) + c;
        }
        
        return comp; // Return the compressed string
    }
};

// Example usage:
// Solution sol;
// string compressed = sol.compressedString("aaabbbccccddddddddd");
// cout << compressed; // Output: "3a3b4c9d"
