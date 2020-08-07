class Solution {
public:
    double dist(const pair<double,double>& a,const pair<double,double>& b){
        return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
    }
    double sum(const vector<pair<double,double>> pos,const pair<double,double>& a){
        double ans=0.0;
        for(pair<double,double> b:pos){
            ans+=dist(a,b);
        }
        return ans;
    }
    double getMinDistSum(vector<vector<int>>& pos) {
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        int n=pos.size();
        vector<pair<double,double>> a(n);
        pair<double,double> cur;
        cur.first=cur.second=0;
        for(int i=0;i<n;++i){
            a[i].first=(double)pos[i][0];
            a[i].second=(double)pos[i][1];
            cur.first+=a[i].first;
            cur.second+=a[i].second;
        }
        cur.first/=n;
        cur.second/=n;
        for(double step=50;step>1e-6;){
            bool found=0;
            for(int dir=0;dir<4;++dir){
                pair<double,double> point;
                point.first=cur.first+dx[dir]*step;
                point.second=cur.second+dy[dir]*step;
                if(sum(a,point)<sum(a,cur)) cur=point,found=1;
            }
            if(!found) step/=2;
        }
        return sum(a,cur);
    }
};
