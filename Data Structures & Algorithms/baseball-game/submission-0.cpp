class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string& s : operations){
            if(s == "+"){
                int first = st.top(); st.pop();
                int sec = st.top();
                st.push(first);
                st.push(first + sec);
            }
            else if(s == "C"){
                st.pop();
            }
            else if(s == "D"){
                int top = st.top();
                st.push(2*top);
            }
            else{
                int num = stoi(s);
                st.push(num);
            }
        }

        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};