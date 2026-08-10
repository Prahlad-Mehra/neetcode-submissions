class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int bound = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int n= arr.size();
        cout<<bound;

        vector<int> ans;
        int l= bound-1, r=bound;
        while(ans.size() < k){
            if(r<n && l>=0){
                if(abs(arr[l]-x)<=abs(arr[r]-x)){
                    ans.push_back(arr[l]);
                    l--;
                }
                else{
                    ans.push_back(arr[r]);
                    r++;
                }
            }
            else if(r<n){
                ans.push_back(arr[r]);
                r++;
            }
            else if(l>=0){
                ans.push_back(arr[l]);
                l--;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};