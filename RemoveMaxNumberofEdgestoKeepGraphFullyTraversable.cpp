const int N=1e5+5;
int f[N],f1[N],f2[N];
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

int find1(int x){
    if(f1[x]==x) return x;
    return f1[x]=find1(f1[x]);
}

int find2(int x){
    if(f2[x]==x) return x;
    return f2[x]=find2(f2[x]);
}

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> A,B,both;
        for(vector x:edges){
            if(x[0]==1) A.push_back({x[1],x[2]});
            if(x[0]==2) B.push_back({x[1],x[2]});
            if(x[0]==3) both.push_back({x[1],x[2]});
        }
        for(int i=0;i<n;++i) f[i]=i,f1[i]=i,f2[i]=i;
        int num_del=0;
        int base=0;
        for(pair<int,int> v:both){
            int x=v.first-1,y=v.second-1;
            int xx=find(x),yy=find(y);
            if(xx==yy){
                ++num_del;
            }
            else{
                f[yy]=xx;
                f1[yy]=xx;
                f2[yy]=xx;
                ++base;
            }
        }
        // cout<<"base : "<<base<<endl;
        int num_del1=0;
        int base1=0;
        for(pair<int,int> v:A){
            int x=v.first-1,y=v.second-1;
            int xx=find1(x),yy=find1(y);
            if(xx==yy){
                ++num_del1;
            }
            else{
                f1[yy]=xx;
                ++base1;
            }
        }
        // cout<<"base 1 : "<<base1<<endl;
        if(base+base1!=n-1) return -1;
        int num_del2=0;
        int base2=0;
        for(pair<int,int> v:B){
            int x=v.first-1,y=v.second-1;
            int xx=find2(x),yy=find2(y);
            if(xx==yy){
                ++num_del2;
            }
            else{
                f2[yy]=xx;
                ++base2;
            }
        }
        if(base+base2!=n-1) return -1;
        return num_del+num_del1+num_del2;
    }
};
