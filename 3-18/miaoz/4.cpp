class Solution {
public:
    bool res=false;
    int vis[20];
    int nbs[20][2];
    int size=4；
    bool judgePoint24(vector<int>& nums) {
        for(int i=0;i<4;i++){
            nbs[i][0]=nums[i];
            nbs[i][1]=1;
        }
        dfs(4);
        return res;
    }
    void dfs(int n){
        if(n==1){
            if(nbs[size-1][0]==nbs[size-1][1]*24&&nbs[size-1][1]!=0)res=true;
            return;
        }
        for(int i=0;i<size;i++){
            if(vis[i])continue;
            vis[i]=1;
            for(int j=0;j<size;j++){
                if(vis[j])continue;
                vis[j]=1;
                for(int k=0;k<4;k++){
                    if(k==0){
                        nbs[size][0]=nbs[i][0]*nbs[j][0];
                        nbs[size++][1]=nbs[i][1]*nbs[j][1];
                    }
                    if(k==1){
                        nbs[size][0]=nbs[i][0]*nbs[j][1];
                        nbs[size++][1]=nbs[i][1]*nbs[j][0];
                    }
                    if(k==2){
                        nbs[size][1]=nbs[i][1]*nbs[j][1];
                        nbs[size++][0]=nbs[i][0]*nbs[j][1]+nbs[j][0]*nbs[i][1];
                    }
                    if(k==3){
                        nbs[size][1]=nbs[i][1]*nbs[j][1];
                        nbs[size++][0]=nbs[i][0]*nbs[j][1]-nbs[j][0]*nbs[i][1];
                    }
                    if(nbs[size-1][1]!=0)dfs(n-1);
                    size--;
                }
                 vis[j]=0;
            }
            vis[i]=0;
        }
    }
};