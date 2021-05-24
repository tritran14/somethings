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

const ll INF=1e18;
class Solution2 {
public:
    ll dp[100005][2];
    
    ll dfs(const vector<int>& a,int id,int turn,ll sum){
        if(dp[id][turn]>-INF) return dp[id][turn];
        ll& ans=dp[id][turn];
        ans=-INF;
        if(id==0){
            sum+=a[id];
            ++id;
        }
        if(id+1==(int)a.size()){
            return a[id]+sum;
        }
        sum+=a[id];
        ans=max(sum-dfs(a,id+1,turn^1,sum),dfs(a,id+1,turn,sum));
        return ans;
    }
    
    int stoneGameVIII(vector<int>& a) {
        int n=(int)a.size();
        for(int i=0;i<n;++i) dp[i][0]=dp[i][1]=-INF;
        return dfs(a,0,0,0);
    }
};
