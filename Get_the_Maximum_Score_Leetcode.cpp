typedef long long ll;
const int mod=1e9+7;
class Solution {
public:
    int maxSum(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        vector<ll> dp_a(n+5),dp_b(m+5);
        if(n) dp_a[0]=0;
        if(m) dp_b[0]=0;
        int id_a=0,id_b=0;
        while(id_a<n||id_b<m){
            if(id_a<n&&id_b<m){
                if(a[id_a]==b[id_b]){
                    dp_a[id_a+1]=dp_b[id_b+1]=max(dp_a[id_a],dp_b[id_b])+a[id_a];
                    ++id_a;
                    ++id_b;
                }
                else if(a[id_a]<b[id_b]){
                    dp_a[id_a+1]=dp_a[id_a]+a[id_a];
                    ++id_a;
                }
                else{
                    dp_b[id_b+1]=dp_b[id_b]+b[id_b];
                    ++id_b;
                }
            }
            else if(id_a<n){
                dp_a[id_a+1]=dp_a[id_a]+a[id_a];
                ++id_a;
            }
            else{
                dp_b[id_b+1]=dp_b[id_b]+b[id_b];
                ++id_b;
            }
        }
        // for(int i=1;i<=n;++i) cout<<dp_a[i]<<" ";cout<<endl;
        // for(int i=1;i<=m;++i) cout<<dp_b[i]<<" ";cout<<endl;
        return max(dp_a[n],dp_b[m])%mod;
    }
};
