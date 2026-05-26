class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool present1=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) present1=true;
            if(nums[i]<=0 || nums[i]>nums.size()) nums[i]=1;
        }
        if(!present1) return 1;
        for(int i=0;i<nums.size();i++){
            int idx= abs(nums[i])-1;
            nums[idx]=abs(nums[idx])*(-1);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return i+1;
        }
        return (nums.size() + 1);
    }
};