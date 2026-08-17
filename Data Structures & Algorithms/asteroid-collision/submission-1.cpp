class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int& stone : asteroids){
            if(stone > 0) st.push(stone);
            else {
                bool insert = true;
                while(!st.empty()){
                    if(st.top() < 0) break;
                    if(st.top() < abs(stone)) st.pop();
                    else if(st.top() == abs(stone)){
                        st.pop();
                        insert = false;
                        break;
                    }
                    else{
                        insert = false;
                        break;
                    }
                }
                if(insert) st.push(stone);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};