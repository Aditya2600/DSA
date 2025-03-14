class StockSpanner {
    stack<pair<int,int>> st;
    int ind;
public:
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind++;
        int ans = 1;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
            ans = st.empty() ? (ind + 1) : (ind - st.top().second);
            st.push({price, ind});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */