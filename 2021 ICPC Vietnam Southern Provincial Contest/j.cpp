#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

int main(){
	fastio;
	int n,m;cin>>n>>m;
	vector<string> br(n);
	for (string &v:br) cin>>v;
	vector<vector<int>> 
	l(n,vector<int>(m,0)),
	r(n,vector<int>(m,0)),
	u(n,vector<int>(m,0)),
	d(n,vector<int>(m,0));
	
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (br[i][j]=='1'){
				l[i][j]=1;
				if (j) l[i][j]+=l[i][j-1];
			}
		}
	}

	for (int i=0;i<n;++i){
		for (int j=m-1;j>=0;--j){
			if (br[i][j]=='1'){
				r[i][j]=1;
				if (j<m-1) r[i][j]+=r[i][j+1];
			}
		}
	}
	
	for (int j=0;j<m;++j){
		for (int i=0;i<n;++i){
			if (br[i][j]=='1'){
				u[i][j]=1;
				if (i) u[i][j]+=u[i-1][j];
			}
		}
	}
	
	for (int j=0;j<m;++j){
		for (int i=n-1;i>=0;--i){
			if (br[i][j]=='1'){
				d[i][j]=1;
				if (i<n-1) d[i][j]+=d[i+1][j];
			}
		}
	}
	
	int mx=0;
	int rer,rec;
	
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			int cur=min(min(l[i][j],r[i][j]),min(u[i][j],d[i][j]));
			if (cur>mx) {
				mx=cur;
				rer=i;rec=j;
			}
		}
	}
	if (mx==0) cout<<"-1\n";
	else {
		cout<<mx*4-3<<'\n';
		cout<<rer+1<<' '<<rec+1<<'\n';
	}

}