class Solution {
public:
    int minMaxDifference(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);
        int value1, value2;
        int k1 = 1;
        int k2 = 1;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != '9' && k1>0){
                value1 = s1[i];
                s1[i] = '9';
                k1--;
            }
            if(s1[i] == value1){
                s1[i] = '9';
            }
        }
        for(int i=0; i<s2.size(); i++){
            if(s2[i] != '0' && k2>0){
                value2 = s2[i];
                s2[i] = '0';
                k2--;
            }
            if(s2[i] == value2){
                s2[i] = '0';
            }
        }
        return stoi(s1) - stoi(s2);;
    }
};