class Solution {
public:
    void buildTree(vector<int>& nums,vector<int>& segTree, int l, int r, int id){
        if(l == r){
            segTree[id] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildTree(nums, segTree, l, mid, 2*id +1);
        buildTree(nums, segTree, mid+1, r, 2*id +2);

        segTree[id] = max(segTree[2*id +1], segTree[2*id +2]);
    }
    int query(vector<int>& segTree, int l, int r, int ql, int qr, int id){
        if(l>qr || r<ql) return INT_MIN;
        if(l>=ql && r<=qr) return segTree[id];
        int mid = l + (r-l)/2;

        int lft = query(segTree, l, mid, ql, qr, 2*id +1);
        int right = query(segTree, mid+1, r, ql, qr, 2*id +2);

        return max(lft, right);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> segTree(4*n +1, INT_MIN);
        buildTree(nums,segTree,0, n-1, 0);

        vector<int> ans;
        for(int i=k-1; i<n; i++){
            int curr = query(segTree, 0, n-1, i-k+1, i, 0);
            ans.push_back(curr);
        }

        return ans;
    }
};
