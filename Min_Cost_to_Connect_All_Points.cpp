vector<int> f;
int Find(int x){
    if(f[x]==x) return x;
    return f[x]=Find(f[x]);
}

struct edge{
    int val,x,y;
    edge(int val,int x,int y):val(val),x(x),y(y){}
};

bool cmp(const edge& a,const edge& b){
    return a.val>b.val;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=(int)points.size();
        f.resize(n);
        vector<edge> Q;
        for(int i=0;i<n;++i) f[i]=i;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int dx=abs(points[i][0]-points[j][0]);
                int dy=abs(points[i][1]-points[j][1]);
                Q.emplace_back(dx+dy,i,j);
            }
        }
        sort(Q.begin(),Q.end(),cmp);
        int ans=0;
        while((int)Q.size()){
            edge u=Q.back();
            Q.pop_back();
            int xx=Find(u.x);
            int yy=Find(u.y);
            if(xx==yy) continue;
            ans+=u.val;
            f[yy]=xx;
        }
        return ans;
    }
};
