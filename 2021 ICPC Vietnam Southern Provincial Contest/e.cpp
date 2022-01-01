#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
using namespace std;

int main(){
	fastio;
	int a,h;cin>>a>>h;
	cout.precision(10);
	cout<<fixed;
	double x=(100.0-a)/(h/6.0);
	double y=-x*h/3+100;
	double g=(y-h*x)/(-2*x);
	double re1=0;
	if (g<h/3.0&&g>h/6.0) re1=(x*g+y)*(h-g);
	cout<<max(re1,max(1.0*a*h*5/6,1.0*100*h*2/3))<<'\n';
}