class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int low=0,high=1;
        if(num[low]+num[high] == target) return vector<int>{low+1,high+1};
        vector<int> ans;
        high = num.size()-1;
        while(high > low){
            int sum = num[low] + num[high];
            if(sum == target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                break;
            }
            else if(sum > target){
                high--;
            }
            else{
                low++;
            }
        }
        return ans;
    }
};