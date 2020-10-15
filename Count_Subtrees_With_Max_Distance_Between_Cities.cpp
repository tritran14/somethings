const int INF=1000000007;
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n-1);
        // cout<<"test case : "<<endl;
        // floyd
        vector<vector<int>> mat(n,vector<int>(n,INF));
        for(int i=0;i<n-1;++i){
            int x=edges[i][0];
            int y=edges[i][1];
            --x,--y;
            mat[x][y]=mat[y][x]=1;
        }
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(mat[i][j]>mat[i][k]+mat[k][j]){
                        mat[i][j]=mat[i][k]+mat[k][j];
                    }
                }
            }
        }
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<n;++j){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // bitmask
        for(int mask=0;mask<(1<<n);++mask){
            int vers=__builtin_popcount(mask);
            int cnt=0;
            int maxx=0;
            for(int i=0;i<n;++i){
                for(int j=i+1;j<n;++j){
                    if((mask&(1<<i))&&(mask&(1<<j))){
                        if(mat[i][j]==1) ++cnt;
                        maxx=max(maxx,mat[i][j]); 
                    }
                }
            }
            if(cnt==vers-1&&maxx){
                --maxx;
                ++ans[maxx];
            }
            
        }
        return ans;
    }
};
