#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

const int mxn=1e7+5;
ll re[mxn];
ll f[mxn];
const ll M=1000000007LL;
int main(){
	fastio;
	re[1]=re[2]=0;
	f[0]=f[1]=1;f[2]=2;
	ll curadd=2,cursub=1;
	for (int i=3;i<mxn-1;++i){
		f[i]=(f[i-1]*i)%M;
		cursub=(cursub+curadd)%M;
		curadd=(curadd+f[i-1])%M;
		re[i]=(f[i]-(curadd*2-1-cursub)%M+M)%M;
	}
	int t;cin>>t;
	while (t--) {
		int n;cin>>n;cout<<re[n]<<'\n';
	}
}