class Solution {
public:
    void getVals(stack<int>& st, int& first, int& sec){
        if(!st.empty()){
            first = st.top(); st.pop();
        }
        if(!st.empty()){
            sec = st.top(); st.pop();
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(string& s : tokens){
            int first = 0, sec = 0;
            if(s =="+" || s=="-" || s=="*" || s=="/"){
                getVals(st, first, sec);
                if(s == "+") st.push(first + sec);
                else if(s == "-") st.push(sec - first);
                else if(s == "*") st.push(first * sec);
                else st.push(sec/first);
            }
            else
                st.push(stoi(s));
        }
        return st.top();
    }
};
