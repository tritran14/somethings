class Solution {
public:
    int n_cl;
    int n;
    string cl;
    vector<bool> checked;
    vector<bool> went;
    vector<vector<int>> v;
    vector<bool> used;
    bool flag_cycle=0;
    void dfs(int u,int par){
        if(checked[u]) return;
        went[u]=1;
        used[u]=1;
        for(int x:v[u]){
            if(x==par){
                flag_cycle=1;
                break;
            }
            if(used[x]){
                flag_cycle=1;
                break;
            }
            dfs(x,u);
        }
        if(flag_cycle) return;
        used[u]=0;
        checked[u]=1;
    }
    
    int largestPathValue(string cl, vector<vector<int>>& edges) {
        int n=(int)cl.size();
        this->n=n;
        this->cl=cl;
        set<char> S;
        for(int i=0;i<n;++i){
            S.insert(cl[i]);
        }
        this->n_cl=(int)S.size();
        v.resize(n);
        vector<int> indeg(n);
        for(vector<int> edge:edges){
            v[edge[0]].push_back(edge[1]);
            ++indeg[edge[1]];
        }
        // check cycle
        checked.resize(n);
        used.resize(n);
        went.resize(n);
        for(int i=0;i<n;++i){
            if(!went[i]) dfs(i,-1);
        }
        // dfs(0,-1);
        if(flag_cycle){
            return -1;
        }
        vector<vector<int>> dp(n,vector<int>(26));
        queue<int> Q;
        for(int i=0;i<n;++i){
            if(!indeg[i]){
                Q.push(i);
                dp[i][cl[i]-'a']=1;
            }
        }
        int ans=0;
        // if(Q.empty()) return -1;
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            int val=*max_element(dp[u].begin(),dp[u].end());
            ans=max(ans,val);
            for(int x:v[u]){
                for(int ch=0;ch<26;++ch){
                    int add=0;
                    if(cl[x]-'a'==ch) add=1;
                    dp[x][ch]=max(dp[x][ch],dp[u][ch]+add);
                }
                if(--indeg[x]==0){
                    Q.push(x);
                }
            }
        }
        return ans;
    }
};
