class Solution {
public:
    string resultingString(string s) {
        stack<char> st;

    for (char c : s) {
        if (!st.empty()) {
            char top = st.top();
            int diff = abs(top - c);
            // Check if consecutive (including circular)
            if (diff == 1 || diff == 25) {
                st.pop(); // remove the pair
                continue;
            }
        }
        st.push(c);
    }

    // Build final result from stack
    string result(st.size(), ' ');
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }

    return result;

        // bool changed = true;

        // while (changed) {
        //     changed = false;
        //     for (int i = 0; i < s.size() - 1; ++i) {
        //         int j = i + 1;
        //         char a = s[i];
        //         char b = s[j];
        //         if (abs(a - b) == 1 || (a == 'a' && b == 'z') || (a == 'z' && b == 'a')) {
        //             s.erase(i, 2);
        //             changed = true;
        //             break;
        //         }
        //     }
        // }

        // return s;
    }
};