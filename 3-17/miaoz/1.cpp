class Solution {
public:
    int ans,c[26],tmp[26];
    int countCharacters(vector<string>& words, string chars) {
        for(auto i:chars)c[i-'a']++;
        for(auto s:words){
            ans+=s.size();
            memcpy(tmp,c,26*sizeof(int));
            for(auto i:s){
                if(--tmp[i-'a']<0){
                    ans-=s.size();
                    break;
                }
            }
        }
        return ans;
    }
};