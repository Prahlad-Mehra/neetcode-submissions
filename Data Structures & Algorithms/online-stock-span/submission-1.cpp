class StockSpanner {
private:
    stack<pair<int,int>> st; // {idx, value}
    int count = 0;
public:
    StockSpanner() {
        // do nothing still win
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({count, price});
            count++;
            return 1;
        }
        while(!st.empty() && st.top().second <= price){
            st.pop();
        }
        int prevIdx = st.empty() ? -1 : st.top().first;
        st.push({count, price});
        count++;

        return count-prevIdx-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */