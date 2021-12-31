#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


vector<int> a;
const ll INF = 1e18;
int main(){
	fastio;
	int n;cin>>n;
	a.assign(n,0);
	ordered_set s;
	vector<int> b(n,0);
	for (int i=0;i<n;++i) {
		cin>>a[i];
		b[a[i]-1]=i;
	}
	vector<ll> pref(n);
	vector<ll> suf(n);	
	for (int i=0;i<n;++i){
		if (i) pref[i]=pref[i-1];
		pref[i]+=i-s.order_of_key(b[i]);
		s.insert(b[i]);
	}
	s.clear();
	for (int i=n-1;i>=0;--i){
		if (i<n-1) suf[i]=suf[i+1];
		suf[i]+=s.order_of_key(b[i]);
		s.insert(b[i]);
	}
	ll re=INF;
	for (int i=0;i<n;++i){
		ll cur=0;
		if (i) cur+=pref[i-1];
		if (i<n-1) cur+=suf[i+1];
		re=min(cur,re);
	}
	cout<<re<<'\n';
}