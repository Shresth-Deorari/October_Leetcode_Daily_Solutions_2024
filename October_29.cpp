class Solution {
    vector<pair<int,int>>directions = {{-1,1},{0,1},{1,1}};
    int f(vector<vector<int>>&grid, int i,int j,int m,int n, vector<vector<int>>&dp){
        if(j==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int count = 0;
        for(auto dir : directions){
            int newi = i + dir.first;
            int newj = j + dir.second;
            if(newi>=0 && newi<m && newj>=0 && newj<n && grid[i][j]<grid[newi][newj]){
                count = max(count, 1 + f(grid, newi, newj, m, n, dp));
            }
        }
        return dp[i][j] = count;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int  maxi = 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = 0;i<m;i++){
            maxi = max(maxi, f(grid, i, 0, m, n, dp));
        }
        return maxi;
    }
};