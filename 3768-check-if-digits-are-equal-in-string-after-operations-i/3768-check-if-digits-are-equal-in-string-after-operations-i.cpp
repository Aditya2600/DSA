class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string newString;
            for(int i=0; i<s.size()-1; i++){
                int firstDigit = s[i] - '0';
                int secondDigit = s[i+1] - '0';
                int newDigit = (firstDigit + secondDigit)%10;
                newString.push_back(newDigit);
            }
            s = newString;
        }
        return s[0] == s[1];
    }
};