class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        array<int, 26> mp{};
        for(char& ch : s1)
            mp[ch - 'a']++;
        
        array<int, 26> curr{};
        int sum = 0;
        int l=0, r=0;

        while(r < s2.size()){
            curr[s2[r] - 'a']++;
            sum++;
            while(l<=r && curr[s2[r] - 'a'] > mp[s2[r]-'a']){
                curr[s2[l]-'a']--;
                l++;
                sum--;
            }
            if(sum == n) return true;
            r++;
        }

        return false;
    }
};
