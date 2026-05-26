class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        if(prices.size()==0) return ans;
        int buy_stock=-1,curr_best=-1;
        for(int i=0;i<prices.size();i++){
            if(buy_stock==-1){
                buy_stock=prices[i];
                curr_best=prices[i];
            }
            else if(prices[i]<=curr_best){
                ans+= curr_best - buy_stock;
                buy_stock = prices[i];
                curr_best=prices[i];
            }
            else curr_best= prices[i];
        }
        ans+= curr_best - buy_stock;
        return ans;
    }
};