class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs=nums[0],sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=sum<=0?nums[i]:sum+nums[i];
            maxs=sum>maxs?sum:maxs;
        }
        return maxs;
    }
};