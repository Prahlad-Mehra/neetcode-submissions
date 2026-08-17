class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(string& s : tokens){
            if(s == "+"){
                int first = 0, sec = 0;
                if(!st.empty()){
                    first = st.top();
                    st.pop();
                }
                if(!st.empty()){
                    sec = st.top();
                    st.pop();
                }
                st.push(first + sec);
            }
            else if(s == "-"){
                int first = 0, sec = 0;
                if(!st.empty()){
                    first = st.top();
                    st.pop();
                }
                if(!st.empty()){
                    sec = st.top();
                    st.pop();
                }
                st.push(sec - first);
            }
            else if(s == "*"){
                int first = 0, sec = 0;
                if(!st.empty()){
                    first = st.top();
                    st.pop();
                }
                if(!st.empty()){
                    sec = st.top();
                    st.pop();
                }
                st.push(first * sec);
            }
            else if(s == "/"){
                int first = 0, sec = 0;
                if(!st.empty()){
                    first = st.top();
                    st.pop();
                }
                if(!st.empty()){
                    sec = st.top();
                    st.pop();
                }
                st.push(sec/first);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
