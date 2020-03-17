typedef long long ll;
class Solution {
public:
    static const int maxn = 1e4 + 5;
    int countNumer(long long cur, int n){ //以cur开头到n的个数
        int res = 0;
        long long tar = cur + 1;      
        while(cur <= n){
            res += fmin((long long)n + 1, tar) - cur;  //确保在(1,n)范围以内
            cur *= 10;
            tar *= 10;
    }
    return res;
    }
    int findKthNumber(int n, int k){
        int res = 1;
        --k;
        while(k > 0){
        int num = countNumer((long long)res, n); 
        if(num > k){
            res *= 10;
            --k;
        }
        else{
            res++;
            k -= num;
        }
        }
        return res;
    }
};