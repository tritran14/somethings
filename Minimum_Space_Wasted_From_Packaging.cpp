#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int mod=1e9+7;
const ll oo=1e18+7;

class Solution {
public:
    int minWastedSpace(vector<int>& pac, vector<vector<int>>& boxes) {
        int n=(int)pac.size();
        int m=(int)boxes.size();
        sort(all(pac));
        for(int i=0;i<m;++i){
            sort(all(boxes[i]));
        }
        ll ans=oo;
        ll sum=0;
        for(int& x:pac) sum+=x;
        for(int i=0;i<m;++i){
            if(boxes[i].back()<pac.back()) continue;
            ll cur=0;
            int prev=0;
            for(int x:boxes[i]){
                int pos=upper_bound(all(pac),x)-pac.begin();
                cur+=1ll*x*(pos-prev);
                prev=pos;
            }
            // cout<<"cur : "<<cur<<endl;
            ans=min(ans,cur);
        }
        if(ans<oo){
            ans=(ans-sum)%mod;
        }
        else ans=-1;
        return ans;
    }
};
