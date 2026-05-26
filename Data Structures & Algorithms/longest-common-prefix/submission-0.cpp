class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            if(i==0) ans=str;
            else{
                if(ans=="") break;
                int curr=0;
                int mini=min(ans.size(),str.size());
                while(curr<mini && ans[curr]==str[curr]) curr++;
                ans=ans.substr(0,curr);
                if(ans=="") break;
            }
        }
        return ans;
    }
};