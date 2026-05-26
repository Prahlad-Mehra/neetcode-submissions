class Solution {
public:
    vector<int> tmp;
    void merge(vector<int>& nums,int start,int mid,int end){
        int i=start, j=mid+1, k=start;

        while(i<=mid && j<=end){
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while(i<=mid) tmp[k++] = nums[i++];
        while(j<=end) tmp[k++] = nums[j++];

        for(int x=start; x<=end; x++)
            nums[x] = tmp[x];
    }
    void mergeSort(vector<int>& nums,int start,int end){
        if(start>=end) return;
        int mid=start + (end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        if(nums.empty()) return nums;   // avoid UB
        tmp.resize(nums.size());
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};