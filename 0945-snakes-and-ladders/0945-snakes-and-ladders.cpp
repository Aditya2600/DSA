class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        // Helper function to convert 1D label to 2D coordinates
        auto pos = [&](int x) -> pair<int, int>{
            int r = (x - 1) / n;
            int c = (x - 1) % n;
            if(r & 1){
                c = (n-1)-c;
            }
            r = (n-1)-r;
            return {r, c};
        };

        
        vector<int> dist(n * n + 1, -1); // Distance from cell 1 to i
        queue<int> q;
        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int move = 1; move <= 6; ++move) {
                int next = x + move;
                if (next > n * n) continue;

                auto [r, c] = pos(next);
                if (board[r][c] != -1) {
                    next = board[r][c]; // Snake or ladder
                }

                if (dist[next] == -1) {
                    dist[next] = dist[x] + 1;
                    q.push(next);
                }
            }
        }

        return dist[n * n];
    }
};
// class Solution {
// public:
//     int snakesAndLadders(vector<vector<int>>& board) {
//         int n = board.size(), label = 1;
//         vector<pair<int, int>> cells(n*n+1);
//         vector<int> columns(n);
//         for(int i=0; i<n; i++) columns[i] = i;
//         for(int row = n-1; row >= 0; row--){
//             for(int col : columns){
//                 cells[label++] = {row, col};
//             }
//             reverse(columns.begin(), columns.end());
//         }
//         vector<int> dist(n*n+1, -1);
//         dist[1] = 0;
//         queue<int> q;
//         q.push(1);
//         while(!q.empty()){
//             int curr = q.front();
//             q.pop();
//             for(int next = curr + 1; next <= min(curr + 6, n*n); next++){
//                 auto [row, col] = cells[next];
//                 int destination = board[row][col] != -1 ? board[row][col] : next;
//                 if(dist[destination] == -1){
//                     dist[destination] = 1 + dist[curr];
//                     q.push(destination);
//                 }
//             }
//         }
//         return dist[n*n];
//     }
// };