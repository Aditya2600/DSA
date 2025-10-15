class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        int day = events[0][0];
        int i = 0;
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(!pq.empty() || i < n){
            while(i < n && day == events[i][0]){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
            day++;
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }
        return cnt;
    }
};