class Solution {
public:
    struct node{
        int st,ed,p;
        node(){};
        node(int x,int y,int z){this->st=x;this->ed=y;this->p=z;};
        bool operator < (const node& b) const {
            return ed<b.ed;
        };
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       int l=startTime.size();
       int *dp=new int[l+1];
       vector<node> ns;
       for(int i=0;i<l;i++)ns.push_back(node(startTime[i],endTime[i],profit[i]));
       sort(ns.begin(),ns.end());
       dp[0]=0,dp[1]=ns[0].p;
       for(int i=1;i<l;i++){
           int j=i;
           while(j>=0&&ns[j].ed>ns[i].st)j--;
           dp[i+1]=max(dp[j+1]+ns[i].p,dp[i]);
       }
       return dp[l];
    }
};