#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	vector<int> a(n);
	for (int&v:a) cin>>v;
	string s;cin>>s;
	int osz=sz(s);
	vector<int> nxt[2];
	nxt[0].assign(osz+1,-1);
	nxt[1].assign(osz+1,-1);	
	int cur0=osz,cur1=osz;
	for (int i=osz-1;i>=0;--i){
		nxt[0][i+1]=cur0+1;
		nxt[1][i+1]=cur1+1;
		if (s[i]=='0') cur0=i;
		else cur1=i;
	}
	nxt[0][0]=cur0+1;
	nxt[1][0]=cur1+1;
	ll acu=0;
	for (int &v:a) acu+=v;
	vector<ll> re(osz+1,0);
	for (int i=0;i<n;++i){
		int beg=0;
		int cur=a[i];
		while (beg<=osz&&cur>0){
			if (cur&1){
				beg=nxt[1][beg];
				if (beg>osz) break;
				re[beg]+=1;
				cur-=1;
			}
			else {
				beg=nxt[0][beg];
				if (beg>osz) break;
				re[beg]+=cur/2;
				cur/=2;
			}
		}
	}
	for (int i=1;i<=osz;++i){
		re[i]+=re[i-1];
		cout<<acu-re[i]<<'\n';
	}
}
