//--------Anivia_kid---------//
//https://codeforces.com/contest/1283/problem/D
#include<bits/stdc++.h>

using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

map<ll, int> mp;

void Anivia_kid(){
	int n, k;
	cin>>n>>k;
	queue<ll> q;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		q.push(x);
		++mp[x];
	}
	vector<ll> res;
	ll s = 0;
	while(!q.empty()){
		ll current = q.front();
		q.pop();
		if(!mp.count(current + 1)){
			mp[current + 1] = mp[current] + 1;
			q.push(current + 1);
			res.eb(current + 1);
			s += mp[current];
		}
		if(res.size() == k) break;
		if(!mp.count(current - 1)){
			mp[current - 1] = mp[current] + 1;
			q.push(current - 1);
			res.eb(current - 1);
			s += mp[current];
		}
		if(res.size() == k) break;
	}
	cout<<s<<'\n';
	for(auto x: res)
		cout<<x<<" ";

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
}