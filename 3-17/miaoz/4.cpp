class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=nums2.size()+nums1.size();
        if(nums1.size()<nums2.size())swap(nums1,nums2);
        if(nums2.size()==0)return (nums1[l/2]+nums1[(l+1)/2-1])*0.5;
        int k1=getk(nums1,-1,nums2,-1,l/2+1);
        if(l%2==0)return (k1+getk(nums1,-1,nums2,-1,(l+1)/2))*0.5;
        else return k1;
    }
    int getk(vector<int> a,int la,vector<int> b,int lb,int k){
        if(k==1){
            if(lb>=(int)b.size()-1)return a[la+1];
            return min(a[la+1],b[lb+1]);
        }
        int mid=k/2;
        int ma=a[la+mid],mb=b[b.size()-1];
        if(lb+mid<b.size())mb=b[lb+mid];
        if(ma<mb){
            la+=mid;
            if(a.size()-la<b.size()-lb){
                return getk(b,lb,a,la,k-mid);
            }
            return getk(a,la,b,lb,k-mid);
        }
        else{
            lb+=mid;
            if(lb>=b.size()-1)return a[la+k-mid+lb-b.size()+1];
            return getk(a,la,b,lb,k-mid);
        }
        
    }
};