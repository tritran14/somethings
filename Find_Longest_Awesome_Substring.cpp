class Solution {
public:
    int longestAwesome(string s) {
        vector<int> dp(1024,s.size());
        dp[0]=-1;
        int ans=0,mask=0;
        // mask : odd =1 even =0 is set of mask
        for(int i=0;i<s.size();++i){
            mask^=1<<(s[i]-'0');
            ans=max(ans,i-dp[mask]);
            for(int j=0;j<10;++j){
                ans=max(ans,i-dp[mask^(1<<j)]);
            }
            dp[mask]=min(dp[mask],i);
        }
        return ans;
    }
};
