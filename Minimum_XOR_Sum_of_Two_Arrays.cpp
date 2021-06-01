class Solution {
public:
    const int INF=1e9+7;
    int n;
    int calc(vector<int>& dp,int id,int mask,vector<int>& a,vector<int>& b){
        if(id>=n) return 0;
        int& ret=dp[mask];
        if(ret>=0) return ret;
        ret=INF;
        for(int j=0;j<n;++j){
            if(!((mask>>j)&1)){
                int newMask=mask^(1<<j);
                ret=min(ret,(a[id]^b[j])+calc(dp,id+1,newMask,a,b));
            }
        }
        return ret;
    }
    
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n=(int)a.size();
        this->n=n;
        vector<int> dp(1<<n,-1);
        return calc(dp,0,0,a,b);
    }
};
