const int inf=1000000;
class Solution {
public:
    int dir[4][2]={0,1,-1,0,1,0,0,-1};
    int bs;
    struct node{
        node(int a,int b,int c){this->x=a,this->y=b,this->vis=c;};
          bool operator <(const node& other) const{
              if(x<other.x){
                  return true;
              }
              else if(x==other.x){
                  return y<other.y;
              }
              return false;
          }
        node(){};
        int x,y,vis;
    };
    node nd[205];
    set<node> se,se2;
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        bs=blocked.size();
        for(int i=0;i<bs;i++)se.insert(node(blocked[i][0],blocked[i][1],1));
        node st=node(source[0],source[1],0);
        node ed=node(target[0],target[1],0);
        if(bfs(st,ed)&&bfs(ed,st))return true;
        return false;
    }
    bool bfs(node st,node ed){
        int tk=0;
        set<node> ser=se;
        queue<node> q;
        st.vis=1,ed.vis=0;
        q.push(st);
        ser.insert(st);
        while(!q.empty()){
            node tmp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                node t=node(tmp.x+dir[i][0],tmp.y+dir[i][1],1);
                if(t.x>=inf||t.y>=inf||t.x<0||t.y<0)continue;
                if(ser.find(t)!=ser.end())continue;
                if(tk++>bs*bs)return true;
                if(t.x==ed.x&&t.y==ed.y)return true;
                q.push(t);
                ser.insert(t);
            }
        }
        return false;
    }
};