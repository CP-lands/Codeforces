#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1468/problem/K
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
	string s;
	cin>>s;
	int n = s.size();
	int dx = 0, dy = 0;
	vector<pair<int, int>> v;
	for(auto x: s){
		if(x == 'L') dx--;
		if(x == 'R') dx++;
		if(x == 'D') dy--;
		if(x == 'U') dy++;
		v.pb({dx, dy});
	}
	if(dx == 0 && dy == 0){
		cout<<2334563<<" "<<2355345<<nl;
	}
	for(int i = 0; i < v.size(); i++){
		int x = v[i].fi;
		int y = v[i].se;
		if(x == 0 && y == 0) continue;
		bool good = true;
		dx = 0;
		dy = 0;
		for(auto j: s){
			int dxx = dx;
			int dyy = dy;
			if(j == 'L') dxx--;
			if(j == 'R') dxx++;
			if(j == 'D') dyy--;
			if(j == 'U') dyy++;
			if(!(dxx == x && dyy == y)){
				dx = dxx;
				dy = dyy;
			}
		}
		if(dx == 0 && dy == 0){
			cout<<x<<" "<<y<<nl;
			return;
		}
	}
	cout<<0<<" "<<0<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}