#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

int main(){
	fastio;
	string s;cin>>s;
	string mn="zz";
	for (int i=0;i<sz(s)-1;++i){
		string x=s.substr(i,2);
		mn=min(mn,x);
		swap(x[0],x[1]);
		mn=min(mn,x);
	}	
	int n;cin>>n;
	for (int i=0;i<n;++i){
		cout<<mn[i%2];
	}
	cout<<'\n';
}