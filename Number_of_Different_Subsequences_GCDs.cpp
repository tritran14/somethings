class Solution {
public:
    int gcd(int a,int b){
        if(!b) return a;
        return gcd(b,a%b);
    }
    int countDifferentSubsequenceGCDs(vector<int>& a) {
        vector<int> g(200005);
        for(int x:a){
            for(int j=1;j*j<=x;++j){
                if(x%j==0){
                    int num1=j;
                    int num2=x/j;
                    g[num1]=gcd(g[num1],x);
                    g[num2]=gcd(g[num2],x);
                }
            }
        }
        int maxx=*max_element(a.begin(),a.end());
        int cnt=0;
        for(int i=1;i<=maxx;++i){
            cnt+=g[i]==i;
        }
        return cnt;
    }
};
