#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

int check(int cnt2,int cnt3,int cnt6,int c2,int c3){
	int dec;
	dec=min(cnt2,c2);
	c2-=dec;cnt2-=dec;
	dec=min(cnt2,c3);
	c3-=dec;cnt2-=dec;
	if (cnt2) return true;
	
	dec=min(cnt3,c3);
	c3-=dec;cnt3-=dec;
	dec=min(cnt3,c2/2);
	c2-=dec*2;cnt3-=dec;
	if (cnt3) return true;
	
	return c2*2+c3*3<cnt6*6;
}

void solve()
{
	string a, b;
	cin >> a >> b;
	int cnt6=0;
	vector<int> cnt(6);
	int temp = 0;
	for (int i=0;i<sz(a);++i){
		if (a[i] == '.') ++temp;
		else 
		{
			if (temp==2) ++cnt[2];
			else if (temp>2){
				--temp;
				++cnt[temp%6];
				cnt6+=temp/6;
			}
			temp=0;
		}
	}
	if (temp==2) ++cnt[2];
	else if (temp>2){
		--temp;
		++cnt[temp%6];
		cnt6+=temp/6;
	}
	
	cnt[2]+=cnt[4]*2;
	cnt[2]+=cnt[5];cnt[3]+=cnt[5];
	cnt[2]+=2*cnt[1];cnt[3]+=cnt[1];cnt6-=cnt[1];
	
	int c2=0,c3=0;
	int ed=sz(b)+1;
	if (!check(cnt[2],cnt[3],cnt6,c2,c3)) ed=0;
	else for (int i = 0; i < sz(b); i++)
	{
		if (b[i] == 'M') ++c2;
		else ++c3;
		
		if (!check(cnt[2],cnt[3],cnt6,c2,c3)) 
		{
			ed=i+1;
			break;
		}
	}
	for (int i=0;i<sz(b)+1;++i)	cout<<((i<ed)?'Y':'N');
	cout<<'\n';
}

int main()
{
	fastio;
	int t; cin >> t;
	while (t--) solve();
}