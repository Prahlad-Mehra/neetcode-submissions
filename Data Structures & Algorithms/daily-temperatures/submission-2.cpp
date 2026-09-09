struct Node{
    int val;
    int idx;
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<Node> st;
        vector<int> result(n, 0);

        for(int i=n-1; i>=0; i--){
            int curr_temp = temperatures[i];
            while(!st.empty() && st.top().val<=curr_temp)
                st.pop();

            if(!st.empty()) 
                result[i] = st.top().idx-i;
            st.push({curr_temp,i});
        }

        return result;
    }
};
