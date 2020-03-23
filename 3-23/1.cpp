#define ll long long 
class Solution {
public:
    bool isHappy(int n) {
        int a=next(n),b=next(a);
        if(a==1||b==1)return true;
        while(a!=b){
            a=next(a);
            b=next(next(b));
            if(a==1||b==1)return true;;
        }
        return false;
    }
    ll next(ll value){
        ll res=0;
        while(value){
            int m =value%10;
            value/=10;
            res+=m*m;
        } 
        return res;
    }
};