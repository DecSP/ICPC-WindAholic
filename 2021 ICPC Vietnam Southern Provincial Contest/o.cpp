#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	map<int,int> m;
	vector<array<int,2>> a(n);
	for (auto &p:a) cin>>p[0]>>p[1];
	ll re=0;
	for (int i=0;i<n;++i) {
		int x=m[a[i][0]]++;
		re+=x;
	}
	m.clear();
	for (int i=0;i<n;++i) {
		int x=m[a[i][1]]++;
		re+=x;
	}
	
	map<array<int,2>,int> m2;
	for(int i=0;i<n;++i){
		int x=m2[{a[i][0],a[i][1]}]++;
		re-=x;
	}
	cout<<re<<'\n';
}
