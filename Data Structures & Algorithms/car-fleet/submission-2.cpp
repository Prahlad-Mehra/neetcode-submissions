class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> info(speed.size());
        for(int i=0; i<speed.size(); i++)
            info[i] = {position[i], speed[i]};
        
        sort(info.begin(), info.end(), [](pair<int,int>& a, pair<int,int>& b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        stack<float> st;
        for(int i=0; i<position.size(); i++){
            float time = float(target-info[i].first)/info[i].second;

            while(!st.empty() && time >= st.top())
                st.pop();
            
            st.push(time);
        }
        
        return st.size();
    }
};
