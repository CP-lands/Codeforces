#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1515/problem/C
 
#define nl '\n'
#define pb push_back
#define fi first
#define se second
#define bug cout<<"bug here!\n"
typedef long long ll;
 
void Solve(){
	int n, m, x;
	cin>>n>>m>>x;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i].fi;
		v[i].se = i;
	}
	sort(v.begin(), v.end());
	vector<int> res(n);
	set<pair<int, int>> s;
	int index = 1;
	for(int i = n - 1; i >= 0; i--){
		if(s.size() < m){
			s.insert({v[i].fi, index});
			res[v[i].se] = index++;
		}
		else{
			pair<int, int> p = *s.begin();
			p.fi += v[i].fi;
			res[v[i].se] = p.se;
			s.erase(s.begin());
			s.insert(p);
		}
	
	}
	pair<int, int> p1 = *s.begin();
	pair<int, int> p2 = *s.rbegin();
	if(p2.fi - p1.fi > x) cout<<"NO"<<nl;
	else{
		cout<<"YES"<<nl;
		for(auto x: res) 
			cout<<x<<" ";
		cout<<nl;
	}
 
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
 
}