class Solution {
public:
    int inf=-0x7f7f7f;
    int maxProfit(int k, vector<int>& prices) {
        if(k>prices.size()/2){
            int res=0;
            for(int i=1;i<prices.size();i++){
                if(prices[i]>prices[i-1])res+=prices[i]-prices[i-1];
            }
            return res;
        }
        if(k==0||prices.empty())return 0;
        vector<vector<int> > dp(k,vector<int>(2,inf));
        dp[0]={0,-prices[0]};
        for(int i=1;i<prices.size();i++){
            for(int j=k-1;j>=0;j--){
                dp[j][0]=max(dp[j][0],dp[j][1]+prices[i]);
                dp[j][1]=max(dp[j][1],j>0?dp[j-1][0]-prices[i]:-prices[i]);
            }
        }
        int res=inf;
        for(int i=0;i<k;i++)res=max(res,dp[i][0]);
        return res;
    }
};