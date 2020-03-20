class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int,vector<int> ,less<int> > q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
            while(q.size()>k)q.pop();
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};