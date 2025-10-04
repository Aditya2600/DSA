class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<pair<int, string>> list = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
    for(auto &p : list){
        while(num >= p.first){
            ans += p.second;
            num -= p.first;
        }
    }
    return ans;
    }
};