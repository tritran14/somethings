typedef long long ll;
class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        int n=a.size();
        if(!n) return 0;
        ll ans=a[0];
        for(int i=1;i<n;++i){
            ans+=max(0,a[i]-a[i-1]);
        }
        return ans;
    }
};
