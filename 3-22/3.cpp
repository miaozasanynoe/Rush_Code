const int inf=80005;
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int mp[inf]={0},mx=0,res=0;
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
            mx=max(A[i],mx);
        }
        for(int i=0;i<inf-1;i++){
            if(mp[i]>1){
                res+=mp[i]-1;
                mp[i+1]+=mp[i]-1;
            }
            if(i>mx&&mp[i]==0) return res;
        }
        return res;
    }
};