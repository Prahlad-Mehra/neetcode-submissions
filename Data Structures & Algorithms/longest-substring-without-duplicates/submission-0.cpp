class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,bool> mp;
        int ans = 0;
        int i=0, j=0;
        while(i < n){
            if(mp[s[i]] == false){
                mp[s[i]] = true;
                ans = max(ans, i-j+1);
                i++;
                continue;
            }
            
            while(j<=i && s[j]!=s[i]){
                mp[s[j]] = false;
                j++;
            }
            mp[s[j]] = false;
            j++;
        }

        return ans;
    }
};
