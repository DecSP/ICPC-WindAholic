#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

const ll INF = 1e18;
int n,m;
vector<vector<int>> adj;
vector<int> d;
vector<multiset<int>> lsE;
int dfs(int cur,int p){
	int mx=d[cur];
	for (int &v:adj[cur]){
		if (v==p) continue;
		d[v]=d[cur]+1;
		int dv=dfs(v,cur);
		mx=max(mx,dv);
		lsE[cur].insert(dv-d[cur]);
	}
	return mx;
}

void dfs2(int cur, int p){
	for (int &v:adj[cur]){
		if (v==p) continue;
		int dv = 1;
		int dc=*prev(lsE[cur].end());
		if (sz(lsE[v])) dv=*(prev(lsE[v].end()))+1;
		if (dc==dv){
			dc=(sz(lsE[cur])>=2)?(*prev(prev(lsE[cur].end()))):0;
		}
		lsE[v].insert(dc+1);
		dfs2(v,cur);
	}
}
int main(){
	fastio;
	cin>>n>>m;
	adj.assign(n,vector<int>());
	lsE.assign(n,multiset<int>());
	
	d.assign(n,0);
	for (int i=0;i<n-1;++i){
		int x,y;cin>>x>>y;--x;--y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(0,0);
	dfs2(0,0);
	vector<vector<int>> lsE2(n,vector<int>());
	for (int i=0;i<n;++i){
		for (int v:lsE[i]) {
			lsE2[i].push_back(v);
			
		}
	}
	
	
	for (int i=0;i<m;++i){
		int x,t;cin>>x>>t;--x;
		cout<<(int)(lsE2[x].end()-upper_bound(lsE2[x].begin(),lsE2[x].end(),t))<<'\n';
	}
}