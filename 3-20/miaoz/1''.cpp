const int maxn=10005;
class Solution {
public:
    int heap[maxn];
    int size;
    void heapfy(int k,int len){
        int ls=k<<1,rs=k<<1|1;
        int index=k;
        if(ls<=len&&heap[index]<heap[ls])index=ls;
        if(rs<=len&&heap[index]<heap[rs])index=rs;
        if(index!=k){
            swap(heap[index],heap[k]);
            heapfy(index,len);
        }
    }
    void buildheap(){
        for(int i=size>>1;i>0;i--)heapfy(i,size);
    }
    void heapsort(){
        for(int i=size;i>0;i--){
            swap(heap[1],heap[i]);
            heapfy(1,i-1);
        }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        size=k;
        for(int i=0;i<k;i++)heap[i+1]=arr[i];
        buildheap();
        for(int i=k;i<arr.size();i++){
            if(arr[i]<heap[1]){
                heap[1]=arr[i];
                heapfy(1,k);
            }
        }
        vector<int> res(heap+1,heap+k+1);
        return res;
    }
};