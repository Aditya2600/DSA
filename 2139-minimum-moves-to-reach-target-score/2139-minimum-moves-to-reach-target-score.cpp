class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;

        while (target > 1 && maxDoubles > 0) {
            if (target % 2 == 1) {
                target--;      // odd → ek normal move
                moves++;
            } else {
                target /= 2;   // even → double ka reverse
                maxDoubles--;
                moves++;
            }
        }

        // ab doubles nahi bache, sirf -1 moves
        if (target > 1) {
            moves += target - 1;
        }

        return moves;
    }
};