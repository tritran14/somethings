class Solution {
public:  
    int calc(vector<vector<int>>& a){
        int ans=0;
        int n=(int)a.size();
        for(int i=0;i<n-1;++i){
            int h1=a[i][1],h2=a[i+1][1];
            int h=h1+abs(a[i+1][0]-a[i][0]);
            if(h>h2){
                h=h2+(h-h2)/2;
            }
            ans=max(ans,h);
            a[i+1][1]=min(h,h2);
        }
        return ans;
    }
    
    int maxBuilding(int maxx, vector<vector<int>>& a) {
        int n=(int)a.size();
        a.push_back({1,0});
        a.push_back({maxx,maxx-1});
        sort(a.begin(),a.end());
        calc(a);
        reverse(a.begin(),a.end());
        return calc(a);
    }
};
