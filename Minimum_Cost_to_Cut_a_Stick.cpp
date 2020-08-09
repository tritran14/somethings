class Solution {
public:
    int minCost(int m, vector<int>& a) {
        sort(a.begin(),a.end());
        vector<int> solve;
        int pre=0;
        for(int i=0;i<a.size();++i){
            solve.push_back(a[i]-pre);
            pre=a[i];
        }
        solve.push_back(m-a.back());
        int n=solve.size();
        vector<vector<int>> dp(n+5,vector<int>(n+5));
        vector<int> pref(n+5);
        // cout<<n<<endl;
        // for(int x:solve) cout<<x<<" ";cout<<endl;
        for(int i=0;i<n;++i) pref[i+1]=pref[i]+solve[i];
        // cout<<"pref : ";
        // for(int i=0;i<n;++i) cout<<pref[i]<<" ";cout<<endl;
        for(int i=n-1;i>=0;--i){
            for(int j=i;j<n;++j){
                if(i==j){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=2e9;
                for(int k=i;k<j;++k){
                    dp[i][j]=min(dp[i][j],pref[j+1]-pref[i]+dp[i][k]+dp[k+1][j]);
                    // cout<<"pair : "<<i<<" "<<j<<endl;
                    // cout<<"pref - pref : "<<pref[j+1]-pref[i]<<endl;
                }
            }
        }
        return dp[0][n-1];
    }
};
