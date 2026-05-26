class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int count0=0,idx0=-1,product=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
                idx0=i;
                continue;
            }
            product = product * nums[i];
        }
        if(count0>1) return ans;
        if(count0==1){
            ans[idx0]=product;
            return ans;
        }
        for(int i=0;i<ans.size();i++) ans[i] = product/nums[i];
        return ans;
    }
};