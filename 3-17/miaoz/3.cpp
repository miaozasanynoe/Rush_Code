class Solution {
public:
    int strToInt(string str) {
        int t=0;
        long long res=0;
        for(auto i:str){
            if(t==0){
                if(i==' ')continue;
                else if(i<='9'&&i>='0'){
                    res+=i-'0';
                    t=1;
                }
                else if(i!='+'&&i!='-'){
                    return 0;
                }
                else{
                    t=i=='+'?1:-1;
                }
            }
            else{
                if(i<='9'&&i>='0'){
                    res*=10;
                    res+=i-'0';
                    if(t==1&&res>2147483647||t==-1&&res>2147483648)return t==-1?-2147483648:2147483647;
                }
                else{
                    return res*t;
                }
            }
        }
        return res*t;
    }
};