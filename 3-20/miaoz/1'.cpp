class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_select(arr,0,arr.size()-1,k);
        arr.resize(k);
        return arr;
    }
    void quick_select(vector<int>&arr,int l,int r,int k){
        if(l>=r)return;
        int tmp=arr[l];
        int i=l,j=r;
        while(i<j){
            while(i<j&&arr[j]>=tmp)j--;
            while(i<j&&arr[i]<=tmp)i++;
            if(i<j)swap(arr[i],arr[j]);
        }
        swap(arr[i],arr[l]);
        if(i<k)quick_select(arr,i+1,r,k);
        if(i>k)quick_select(arr,l,i-1,k);
        if(i==k)arr.resize(k);
    }
};