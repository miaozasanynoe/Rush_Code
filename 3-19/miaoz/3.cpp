class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int dp[2][2];
        dp[0][0]=0;
        dp[0][1]=0-prices[0];
        for(int i=1;i<prices.size();i++){
            dp[i%2][0]=max(dp[(i-1)%2][0],dp[(i-1)%2][1]+prices[i]);
            dp[i%2][1]=max(dp[(i-1)%2][1],-prices[i]);
        }
        return dp[(prices.size()-1)%2][0];
    }
};