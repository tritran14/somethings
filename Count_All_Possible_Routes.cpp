const int mod=1e9+7;

void add_self(int& a,int b){
    a+=b;
    if(a>=mod) a-=mod;
}

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>> dp(fuel+1,vector<int>(n));
        dp[fuel][start]=1;
        for(int f=fuel;f>=1;--f){
            for(int from=0;from<n;++from){
                for(int to=0;to<n;++to){
                    int dist=abs(locations[from]-locations[to]);
                    if(from!=to&&f>=dist){
                        add_self(dp[f-dist][to],dp[f][from]);
                    }
                }
            }
        }
        int ans=0;
        for(int f=0;f<=fuel;++f){
            add_self(ans,dp[f][finish]);
        }
        return ans;
    }
};
