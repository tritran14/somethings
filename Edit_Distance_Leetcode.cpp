class Solution {
public:
    inline void min_self(int& a,int b){
        if(b<a) a=b;
    }
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<n;++i){
            dp[i+1][0]=i+1;
        }
        for(int i=0;i<m;++i){
            dp[0][i+1]=i+1;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(s[i]==t[j]){
                    dp[i+1][j+1]=dp[i][j];
                }
                else{
                    // insert
                    dp[i+1][j+1]=dp[i+1][j]+1;
                    // replace
                    min_self(dp[i+1][j+1],dp[i][j]+1);
                    // delete
                    min_self(dp[i+1][j+1],dp[i][j+1]+1);
                }
            }
        }
        return dp[n][m];
    }
};
