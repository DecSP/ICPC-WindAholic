#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

int main(){
	fastio;
	ll n;cin>>n;
	vector<ll> a(n);
	for (ll &v:a) cin>>v;
	ll ass;cin>>ass;
	ll tg;cin>>tg;
	for (ll &v:a) v= abs(v-tg);
	ass = abs(ass-tg);
	sort(a.begin(),a.end());
	ll re=0,cur=0;
	while (re<n&&cur+a[re]<ass) {
		cur+=a[re];
		re+=1;
	}
	cout<<re<<'\n';	
}