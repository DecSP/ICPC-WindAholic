#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

struct ST{
	int n;
	vector<array<int,2>> arr;
	
	ST(vector<int> &a){
		n=a.size();
		arr.assign(4*n,{0,0});
		build(1,0,n-1,a);
	}
	
	void build(int v, int tl,int tr,vector<int> &a){
		if (tl==tr){
			arr[v][0]=a[tl];
			arr[v][1]=-tl;
			return;
		}
		int mid=(tl+tr)>>1;
		build(v*2,tl,mid,a);
		build(v*2+1,mid+1,tr,a);
		arr[v]=max(arr[v*2],arr[v*2+1]);
	}
	
	array<int,2> get(int v,int l,int r,int tl,int tr){
		if (l>r) return {-1,-1};
		if (tl==l&&tr==r) return arr[v];
		
		int mid=(tl+tr)>>1;
		auto g1=get(v*2,l,min(mid,r),tl,mid);
		auto g2=get(v*2+1,max(l,mid+1),r,mid+1,tr);
		if (g1[0]==-1) return g2;
		if (g2[0]==-1) return g1;
		return max(g1,g2);
	}
	
	void update(int v, int idx, int tl, int tr, int x){
		if (tl==tr) {
			arr[v][0]=x;
			return;
		}
		int mid = (tl+tr)>>1;
		if (idx<=mid) update(v*2,idx,tl,mid,x);
		else update(v*2+1,idx,mid+1,tr,x);
		arr[v]=max(arr[v*2],arr[v*2+1]);
	}
};


int main(){
	fastio;
	int n;cin>>n;
	vector<int> a(n);
	for (int &v:a) cin>>v;
	ST st(a);
	ll re=0;
	int curn=n;
	while (curn){
		int cur=0;
		while (cur<n&&curn>0){
			auto g=st.get(1,cur,n-1,0,n-1);
			int x= g[0],idx=-g[1];
			if (x<st.get(1,0,n-1,0,n-1)[0]) break;
			st.update(1,idx,0,n-1,0);
			--curn;
			cur=idx+1;
		}
		re+=curn;
	}
	cout<<re<<'\n';
}