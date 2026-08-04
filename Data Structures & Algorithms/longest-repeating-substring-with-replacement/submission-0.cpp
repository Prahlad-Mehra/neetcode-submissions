class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =  s.size();
        array<int, 26> mp{};
        int l=0, r=0;
        int mx = 0;
        int ans = 0;

        while(r < n){
            mp[s[r] - 'A']++;
            mx = max(mx, mp[s[r] - 'A']);
            
            if((r-l+1)-mx > k){
                mp[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
