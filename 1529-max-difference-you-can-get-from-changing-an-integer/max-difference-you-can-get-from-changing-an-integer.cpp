class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // === MAXIMIZE ===
        string s_max = s;
        char max_digit_to_replace = 0;
        for (char c : s_max) {
            if (c != '9') {
                max_digit_to_replace = c;
                break;
            }
        }
        if (max_digit_to_replace) {
            for (char &c : s_max) {
                if (c == max_digit_to_replace) c = '9';
            }
        }

        // === MINIMIZE ===
        string s_min = s;
        char min_digit_to_replace = 0;

        if (s_min[0] != '1') {
            min_digit_to_replace = s_min[0];
            for (char &c : s_min) {
                if (c == min_digit_to_replace) c = '1';
            }
        } else {
            for (int i = 1; i < s_min.size(); ++i) {
                if (s_min[i] != '0' && s_min[i] != '1') {
                    min_digit_to_replace = s_min[i];
                    break;
                }
            }
            if (min_digit_to_replace) {
                for (int i = 1; i < s_min.size(); ++i) {
                    if (s_min[i] == min_digit_to_replace) s_min[i] = '0';
                }
            }
        }

        int maxi = stoi(s_max);
        int mini = stoi(s_min);
        return maxi - mini;
    }
};