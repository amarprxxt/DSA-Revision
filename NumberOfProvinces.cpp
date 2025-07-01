class Solution {
public:

//normal dfs
   void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) 
        {
            if (isConnected[node][i] && !visit[i]) 
            {
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) 
        {
            if (!visit[i]) 
            {
                count++;
                dfs(i, isConnected, visit);
            }
        }
        return count;
    }
};

    /*
            for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < columnSize; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
            */