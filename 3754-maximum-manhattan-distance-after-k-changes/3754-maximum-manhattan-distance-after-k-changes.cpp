class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        for(char hor : {'E', 'W'}){
            for(char ver : {'N', 'S'}){
                int remainingK = k, netX = 0, netY = 0;
                for(char ch : s){
                    if(ch == hor && remainingK){
                        ch = ch == 'E' ? 'W' : 'E';
                        remainingK--;
                    }
                    else if(ch == ver && remainingK){
                        ch = ch == 'N' ? 'S' : 'N';
                        remainingK--;
                    }
                    netX += (ch == 'E');
                    netX -= (ch == 'W');
                    netY += (ch == 'N');
                    netY -= (ch == 'S');
                    ans = max(ans, abs(netX) + abs(netY));
                }
            }
        }
        return ans;
    }
};