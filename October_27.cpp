class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            dp[i][0] = matrix[i][0];
        }
        for(int j =0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                int mini = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                if(matrix[i][j])dp[i][j] = mini + 1;
                else dp[i][j] = 0;
            }
        }
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                cout<<dp[i][j]<<" ";
                ans += dp[i][j];
            }
            cout<<endl;
        }
        return ans;
    }
};