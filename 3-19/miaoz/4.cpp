class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int l1=nums1.size(),l2=nums2.size();
        vector<int> res;
        for(int i=0;i<=k;i++){
            if(k-i<=l2&&i<=l1)res=max(merge(getMaxk(nums1,i),getMaxk(nums2,k-i)),res);
        }
        return res;
    }
    vector<int> getMaxk(vector<int> a,int k){
        int less=a.size()-k;
        vector<int> res;
        for(int i=0;i<a.size();i++){
            while(less&&!res.empty()&&a[i]>res.back()){
                less--;
                res.pop_back();
            }
            res.push_back(a[i]);
        }
        res.resize(k);
        return res;
    }
    vector<int> merge(vector<int> a,vector<int> b){
        vector<int> res;
        int l1=a.size(),l2=b.size();
        while (!a.empty()||!b.empty()) {
            vector<int> &tmp =a>b?a:b;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
};