// She says yes :)
#include<bits/stdc++.h>

//https://codeforces.com/contest/1496/problem/C
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Solve(){
	int n;
	cin>>n;
	vector<ll> x, y;
	for(int i = 0; i < 2 * n; i++){
		int a, b;
		cin>>a>>b;
		if(a == 0) y.pb(abs(b));
		else x.pb(abs(a));
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long double res = 0;
	int low = 0, high = 0;
	while(low < n){
		res += sqrt(x[low] * x[low] + y[high] * y[high]);
		low++;
		high++;
	}
	cout<<fixed<<setprecision(15)<<res<<nl;
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}