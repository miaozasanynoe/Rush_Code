class Solution {
public:
    /*
    int maxProfit(vector<int>& prices, int fee) {
        int dp[2][2]={0,0-prices[0]-fee};
        for(int i=1;i<prices.size();i++){
            dp[i%2][0]=max(dp[(i-1)%2][0],dp[(i-1)%2][1]+prices[i]);
            dp[i%2][1]=max(dp[(i-1)%2][1],dp[(i-1)%2][0]-prices[i]-fee);
        }
        return dp[(prices.size()-1)%2][0];
    }
    */
    int maxProfit(vector<int>& prices, int fee) {
        int dp[2]={0,0-prices[0]-fee};
        for(int i=1;i<prices.size();i++){
            dp[0]=max(dp[0],dp[1]+prices[i]);
            dp[1]=max(dp[1],dp[0]-prices[i]-fee);
        }
        return dp[0];
    }
};