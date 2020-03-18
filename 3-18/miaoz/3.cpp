const int inf=1024;
class Solution {
public:
    int res=0,lx,ly;
    int mp[inf][inf];
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())return 0;
        lx=grid.size(),ly=grid[0].size();
        for(int i=0;i<lx;i++){
            for(int j=0;j<ly;j++){
                mp[i][j]=grid[i][j]-'0';
            }
        }
        for(int i=0;i<lx;i++){
            for(int j=0;j<ly;j++){
                if(mp[i][j]==1){
                    dfs(i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(int x,int y){
        if(x<0||x>=lx||y<0||y>=ly)return;
        if(mp[x][y]==1){
            mp[x][y]=-1;
            dfs(x+1,y);
            dfs(x,y+1);
            dfs(x-1,y);
            dfs(x,y-1);
            return;
        }
    }
};