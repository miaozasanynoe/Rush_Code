class Solution {
public:
    int findNthDigit(int n) {
        if(n<10)return n;
        int sum=9;
        for(int i=100,j=2;;i*=10,j++){
            long long tmp=sum+(long long)(i-i/10)*j;
            if(tmp>=n){
                int t=(n-sum+j-1)/j+i/10-1;
                int r=(n-sum-1)%j;
                stack<int> st;
                while(t){
                    st.push(t%10);
                    t/=10;
                }
                while(r--)st.pop();
                return st.top();
                break;
            }
            sum=tmp;
        }
        return 0;
    }
};