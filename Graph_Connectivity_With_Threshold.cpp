const int N=1e4+5;
int f[N];

int Find(int x){
    if(f[x]==x) return x;
    return f[x]=Find(f[x]);
}

class Solution {
public:
    void match(int x,int y){
        x=Find(x);
        y=Find(y);
        if(x==y) return;
        else f[y]=x;
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        for(int i=1;i<=n;++i) f[i]=i;
        vector<int> root(n+1,-1);
        for(int i=threshold+1;i<=n;++i){
            if(root[i]!=-1) continue;
            root[i]=i;
            for(int j=i+i;j<=n;j+=i){
                if(root[j]==-1){
                    root[j]=i;
                }
                else{
                    match(root[j],i);
                }
            }
        }
        // cout<<"root : ";
        // for(int i=1;i<=n;++i) cout<<root[i]<<" ";
        // cout<<endl;
        vector<bool> ans;
        for(vector<int> P:queries){
            int x=root[P[0]];
            int y=root[P[1]];
            if(x<0||y<0){
                ans.push_back(0);
                continue;
            }
            if(Find(x)==Find(y)) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};
