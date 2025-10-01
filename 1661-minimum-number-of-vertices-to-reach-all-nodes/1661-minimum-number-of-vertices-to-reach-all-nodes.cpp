class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        vector<int>ans;

       for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
       }

       queue<int>q;
        vector<int>visited(n,0);

       for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
            visited[i] = 1;
            ans.push_back(i);
        }
       }
       

       while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto it : adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
     

       }

       for(int i = 0; i < n ; i++){
        if(!visited[i]){
            ans.push_back(i);
        }
       }

    

       return ans ;

    }
};