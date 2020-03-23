class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())return 0;
        int *dp=new int[nums.size()];
        dp[0]=1;
        int res=1;
        for(int i=1;i<nums.size();i++){
            int mi=0;
            for(int j=0;j<i;j++){
                if(dp[j]>mi&&nums[i]>nums[j])mi=dp[j];
            }
            dp[i]=mi+1;
            res=max(res,dp[i]);
        }
        return res;
    }
};