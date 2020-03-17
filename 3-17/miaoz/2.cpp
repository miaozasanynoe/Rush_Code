class Solution {
public:
    int findNthDigit(int n) {
        for(int i=0,j=0;i<=n;j++){
            stack<int> st;
            int tmp=j;
            while(tmp){
                st.push(tmp%10);
                tmp/=10;
            }
            while(!st.empty()){
                if(++i==n)return st.top();
                st.pop(); 
            }
        }
        return 0;
    }
};