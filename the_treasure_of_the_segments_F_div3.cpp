#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1462/problem/F
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
	int n;
	cin>>n;
	vector<pair<int, int>> v(n);
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++){
		cin>>x[i]>>y[i];
		v[i] = {x[i], y[i]};
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int res = n;
	for(int i = 0; i < n; i++){
		int x0 = v[i].fi;
		int y0 = v[i].se;
		int left = upper_bound(y.begin(), y.end(), x0 - 1) - y.begin();
		int right = upper_bound(x.begin(), x.end(), y0) - x.begin();
		right = n - right;
		res = min(res, left + right);
		//cout<<x0<<" "<<y0<<" "<<left<<" "<<right<<" "<<res<<nl;
	}
	cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}