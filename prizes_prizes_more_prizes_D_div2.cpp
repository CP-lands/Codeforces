// She says yes :)
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/208/problem/D
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Solve(){
	int n;
	cin>>n;
	vector<int> bar(n);
	for(int i = 0; i < n; i++)
		cin>>bar[i];
	vector<int> v(5);
	vector<pair<int, int>> a(5);
	for(int i = 0; i < 5; i++){
		cin>>v[i];
		a[i] = {v[i], i};
	}
	sort(a.rbegin(), a.rend());
	ll left = 0;
	vector<ll> res(5);
	for(int i = 0; i < n; i++){
		left += bar[i];
		for(int i = 0; i < 5; i++){
			if(left >= a[i].fi){
				int k = left / a[i].fi;
				res[a[i].se] += k;
				left -= (ll)k * a[i].fi;
			}
		}
	}
	for(auto x: res)
		cout<<x<<" ";
	cout<<nl<<left<<nl;
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}