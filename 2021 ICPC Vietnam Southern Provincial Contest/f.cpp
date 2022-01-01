#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;
vector<vector<int>> lDiv;
vector<ll> fac;
int n;
const ll M=1000000007LL;

void sieve(){
	for (int i=2;i<=n;++i){
		for (int j=2*i;j<=n;j+=i){
			lDiv[j].push_back(i);
		}
	}
}

ll pw(ll x,ll y){
	ll re=1;
	while (y){
		if (y&1) re=(re*x)%M;
		y>>=1;
		x=(x*x)%M;
	}
	return re;
}

int main(){
	fastio;
	cin>>n;

	lDiv.assign(n+1,vector<int>());
	sieve();
	
	fac.assign(n+1,0);
	fac[0]=1;
	for (int i=1;i<=n;++i) fac[i]=(fac[i-1]*i)%M;
	
	vector<ll> dp(n+1,0);
	for (int i=n;i>=2;--i){
		dp[i]=(dp[i]+fac[n-1]*(n/i))%M;
		for (int &d:lDiv[i]) {
			dp[d]=(dp[d]+M-dp[i]*pw(n-n/i,M-2)%M*(n-n/d)%M)%M;
		}
	}
	ll re=fac[n];
	for (int i=2;i<=n;++i) re=(re+dp[i])%M;
	re=(re*pw(fac[n],M-2))%M;
	cout<<re<<'\n';
}