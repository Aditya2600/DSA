class Solution {
public:
    string makeFancyString(string s) {
        string result; // To store the final result without consecutive duplicates
        int count = 1; // Initialize count of consecutive characters

        for (int i = 0; i < s.size(); ++i) {
            // If it's the start or current character is different from previous, reset count
            if (i == 0 || s[i] != s[i - 1]) {
                count = 1;
            } else {
                count++; // Increment count if consecutive character is the same
            }
            
            // Only add the character if count is less than 3
            if (count < 3) {
                result += s[i];
            }
        }

        return result;
    }
};
