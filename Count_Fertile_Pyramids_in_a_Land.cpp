class Solution {
public:
    int countPyramids(vector<vector<int>>& a) {
        int n=(int)a.size();
        int m=(int)a[0].size();
        int ans=0;
        // cout<<"testcase : "<<endl;
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<m;++j){
                dp[i][j]=a[i][j];
                if(j>0&&j<m-1&&i<n-1&&a[i][j]==1){
                    dp[i][j]+=min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
                    // cout<<i<<","<<j<<" = "<<dp[i][j]<<endl;
                    if(dp[i][j]>1){
                        ans+=dp[i][j]-1;
                    }
                }
            }
        }
        reverse(a.begin(),a.end());
        dp.resize(n,vector<int>(m));
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<m;++j){
                dp[i][j]=a[i][j];
                if(j>0&&j<m-1&&i<n-1&&a[i][j]==1){
                    dp[i][j]+=min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
                    // cout<<i<<","<<j<<" = "<<dp[i][j]<<endl;
                    if(dp[i][j]>1){
                        ans+=dp[i][j]-1;
                    }
                }
            }
        }
        return ans;
    }
};
