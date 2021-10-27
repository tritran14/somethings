const int mod=1e9+7;

void add_self(int& a,int b){
    a+=b;
    if(a>=mod) a-=mod;
}

int add(int a,int b){
    a+=b;
    if(a>=mod) a-=mod;
    return a;
}

class Solution {
public:
    int countSpecialSubsequences(vector<int>& a) {
        ios::sync_with_stdio(0); cin.tie(0);
        int n=(int)a.size();
        vector<int> dp(3);
        vector<int> dp_pos(n);
        for(int i=0;i<n;++i){
            if(a[i]==0){
                dp_pos[i]=1;
                // dp_pos[i]+=dp[0];
                add_self(dp_pos[i],dp[0]);
            }
            else{
                // dp_pos[i]=dp[a[i]]+dp[a[i]-1];
                add_self(dp_pos[i],add(dp[a[i]],dp[a[i]-1]));
            }
            // dp[a[i]]+=dp_pos[i];
            add_self(dp[a[i]],dp_pos[i]);
        }
        return dp[2];
    }
};
