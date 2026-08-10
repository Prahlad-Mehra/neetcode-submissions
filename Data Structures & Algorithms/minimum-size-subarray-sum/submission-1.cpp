class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int l=0, r=0;
        int currSum = 0;
        while(r < nums.size()){
            currSum += nums[r];
            r++;
            while(l<r && currSum >= target){
                currSum -= nums[l];
                ans = min(ans, r-l);
                l++;
            }
        }

        return (ans==INT_MAX)? 0:ans;
    }
};