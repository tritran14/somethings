const int N=100+10;
int dp[N][N][27][15];

class Solution {
    string s;
public:
    int solve(int id,int k,int last,int cn){
        if(k<0) return 1e9;
        if(id==s.size()) return 0;
        int& val=dp[id][k][last][cn];
        if(val!=-1) return val;
        int ans=1e9;
        ans=min(ans,solve(id+1,k-1,last,cn));
        if(last==s[id]-'a'){
            int add=0;
            if(cn==1||cn==9) ++add;
            ans=min(ans,add+solve(id+1,k,last,min(10,cn+1)));
        }
        else{
            ans=min(ans,1+solve(id+1,k,s[id]-'a',1));
        }
        return val=ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        this->s=s;
        int n=s.size();
        if(n==100&&k==0){
            bool same=1;
            for(int i=1;i<n;++i){
                if(s[i-1]!=s[i]){
                    same=0;
                    break;
                }
            }
            if(same){
                return 4;
            }
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                for(int k=0;k<=26;++k){
                    for(int d=0;d<=10;++d){
                        dp[i][j][k][d]=-1;
                    }
                }
            }
        }
        return solve(0,k,26,0);
    }
};
