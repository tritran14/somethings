#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define trace(...) debug(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void debug(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  debug(comma + 1, args...);
}

const int INF=1000000000+5;
const int N=10+5;
const int M=30;
const ll oo=LLONG_MAX;
const int mod=1e9+7;

int fac[N];

void add_self(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}

int mul(int a,int b){
	return 1ll*a*b%mod;
}

int poww(int a,int b){
	int r=1;
	while(b){
		if(b&1) r=mul(r,a);
		a=mul(a,a);
		b>>=1;
	}
	return r;
}

int inv(int x){
	return poww(x,mod-2);
}

void init(){
	fac[0]=fac[1]=1;
	for(int i=2;i<N;++i){
		fac[i]=mul(fac[i-1],i);
	}
}

int bino(int n,int k){
	if(k>n) return 0;
	return mul(fac[n],mul(inv(fac[n-k]),inv(fac[k])));
}
		

int calcAll(int num){
	if(!num) return 0;
	int ans=1;
	for(int i=num;i>=1;--i){
		add_self(ans,bino(9,i));
	}
	return ans;
}

bool checkIncrease(int a){
	if(!a) return 1;
	vector<int> dig;
	while(a){
		dig.push_back(a%10);
		a/=10;
	}
	reverse(all(dig));
	for(int i=1;i<(int)dig.size();++i){
		if(dig[i-1]>=dig[i]) return 0;
	}
	return 1;
}
	

int stupidAlgo(int n){
	int ret=0;
	for(int i=0;i<=n;++i){
		if(checkIncrease(i)){
			//~ trace(i);
			++ret;
		}
	}
	return ret;
}

int stupidAlgo(int l,int r){
	int ret=0;
	for(int i=l;i<=r;++i){
		if(checkIncrease(i)){
			//~ trace(i);
			++ret;
		}
	}
	return ret;
}	
		
int calc(int n){
	if(!n) return 1;
	int tmp=n;
	int cnt=0;
	vector<int> a;
	while(tmp){
		++cnt;
		a.push_back(tmp%10);
		tmp/=10;
	}
	reverse(all(a));
	int ans=calcAll(cnt-1);
	//~ trace(calcAll(cnt-1));
	int pre=0;
	for(int i=0;i<cnt;++i){
		if(a[i]<=pre) break;
		int remainNumber=cnt-i-1;
		int now=a[i];
		for(int dig=pre+1;dig<=now-1;++dig){
			int remain=9-dig;
			add_self(ans,bino(remain,remainNumber));
		}
		pre=a[i];
	}
	return ans;
}	
	
int getInterval(int l,int r){
	if(!l) return calc(r);
	return calc(r)-calc(l-1);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	//~ trace(bino(5,2));
	//~ int n=10000;
	//~ cin>>n;
	//~ trace(stupidAlgo(n),calc(n));
	int l,r;
	cin>>l>>r;
	//~ trace(stupidAlgo(l,r),getInterval(l,r));
	cout<<getInterval(l,r);
	return 0;
}
