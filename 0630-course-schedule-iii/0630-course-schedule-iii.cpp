class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [] (vector<int> &a, vector<int> &b){
            if(a[1] == b[1])return a[0] < b[0];
            return (a[1] < b[1]);
        });
        priority_queue<int> maxHeap;
        int totalDuration = 0;
        int n = courses.size();
        for(int i = 0; i<n; i++){
            int dur = courses[i][0];
            int last = courses[i][1];
            totalDuration += dur;
            if(last >= totalDuration){
                maxHeap.push(dur);
            }
            else if(!maxHeap.empty() && maxHeap.top() > dur){
                totalDuration -= maxHeap.top();
                maxHeap.pop();
                maxHeap.push(dur);
            }
            else{
                totalDuration -= dur;
            }          
        }
        return maxHeap.size();
    }
};