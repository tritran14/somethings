typedef long long ll;
class Solution {
public:
    ll poww(int a,int b){
        ll r=1;
        ll aa=a;
        while(b){
            if(b&1) r*=aa;
            aa*=aa;
            b>>=1;
        }
        return r;
    }
    int minimumOneBitOperations(int n) {
        int coef=1;
        int bitcnt=0;
        ll base=1;
        while(base<=n){
            base*=2;
            ++bitcnt;
        }
        --bitcnt;
        base/=2;
        ll ans=0;
        for(int bit=bitcnt;bit>=0;--bit){
            int cur=((1<<bit)&n);
            if(!cur) continue;
            ans+=((poww(2,bit)*2)-1)*coef;
            coef*=-1;
        }
        return ans;
    }
};
