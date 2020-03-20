class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        set<int> st;
        for(int i=0;i<nums.size();i++)st.insert(nums[i]);
        for(auto i:st){
            if(st.find(i-1)!=st.end())continue;
            int t=i+1,len=1;
            while(st.find(t)!=st.end())t++,len++;
            res=max(res,len);
        }
        return res;
    }
};