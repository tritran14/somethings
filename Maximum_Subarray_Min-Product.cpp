const int mod=1e9+7;
typedef long long ll;

class Solution {
public:
    int maxSumMinProduct(vector<int>& a) {
        int n=(int)a.size();
        vector<ll> pref(n);
        pref[0]=a[0];
        for(int i=1;i<n;++i) pref[i]=pref[i-1]+a[i];
        auto sum_in_range=[&](int l,int r){
            if(!l) return pref[r];
            return pref[r]-pref[l-1];
        };
        vector<int> b=a;
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        // cout<<"b : "<<endl;
        // for(int x:b) cout<<x<<" ";
        // cout<<endl;
        unordered_map<int,int> maps;
        int id=0;
        for(int x:b){
            maps[x]=id;
            ++id;
        }
        vector<vector<int>> pos((int)b.size());
        for(int i=0;i<n;++i){
            pos[maps[a[i]]].push_back(i);
        }
        for(int i=0;i<(int)b.size();++i){
            // cout<<"#trace "<<b[i]<<endl;
            // for(int x:pos[i]) cout<<x<<" ";
            // cout<<endl;
        }
        ll ans=0;
        set<int> bounds;
        bounds.insert(-1);
        bounds.insert(n);
        for(int i=0;i<(int)b.size();++i){
            int val=b[i];
            for(int x:pos[i]){
                // cout<<"x : "<<x<<endl;
                bounds.insert(x);
                auto it=bounds.lower_bound(x);
                --it;
                // cout<<"bounds"<<endl;
                // for(int xx:bounds) cout<<xx<<" ";
                // cout<<endl;
                int left=*it;
                ++it;
                ++it;
                int right=*it;
                // cout<<"left : "<<left<<"  right : "<<right<<endl;
                --it;
                bounds.erase(it);
                // return 1;
                ll interval=sum_in_range(left+1,right-1);
                ll cur=interval*val;
                ans=max(ans,cur);
            }
            for(int x:pos[i]){
                bounds.insert(x);
            }
        }
        return ans%mod;
        return 1;
    }
};
