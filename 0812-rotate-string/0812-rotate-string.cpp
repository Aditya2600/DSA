class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the sizes match
        if (s.size() != goal.size()) return false;

        // Concatenate s with itself and check if goal is a substring
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};
