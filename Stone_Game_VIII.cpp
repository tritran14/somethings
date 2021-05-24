typedef long long ll;
class Solution {
public:
    int stoneGameVIII(vector<int>& a) {
        int n=(int)a.size();
        vector<ll> pref(n+1);
        for(int i=0;i<n;++i) pref[i+1]=pref[i]+a[i];
        vector<ll> dp(n+1);
        ll bestBefore=pref[n]-dp[n];
        for(int i=n-1;i>=1;--i){
            dp[i]=bestBefore;
            bestBefore=max(bestBefore,pref[i]-dp[i]);
        }
        return dp[1];
    }
};
