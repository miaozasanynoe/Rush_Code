class Solution {
public:
    int inf=-0x7f7f7f7f;
    int maxProfit(vector<int>& prices) {
        int dp[2][2]={0,prices.empty()?0:0-prices[0],inf,inf};
        for(int i=1;i<prices.size();i++){
            dp[1][0]=max(dp[1][0],dp[1][1]+prices[i]);
            dp[1][1]=max(dp[1][1],dp[0][0]-prices[i]);
            dp[0][0]=max(dp[0][0],dp[0][1]+prices[i]);
            dp[0][1]=max(dp[0][1],-prices[i]);
        }
        return max(dp[0][0],dp[1][0]);
    }
};