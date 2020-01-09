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
map<ll, int> ss;
map<ll, int> sub;
 
void Anivia_kid(){
	int n, k;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		++mp[x];
	}
	ss = mp;
	int count = 0;
	vector<ll> res;
	ll s = 0;
	while(count < k){
		for(auto x: mp){
			if(!ss.count(x.fi - 1) && !sub.count(x.fi - 1)){
				sub[x.fi - 1] = mp[x.fi] + 1;
				++ss[x.fi - 1];
				count++;
				res.eb(x.fi - 1);
				s += mp[x.fi];
			}
			if(count == k) break;
			if(!ss.count(x.fi + 1) && !sub.count(x.fi + 1)){
				sub[x.fi + 1] = mp[x.fi] + 1;
				++ss[x.fi + 1];
				count++;
				res.eb(x.fi + 1);
				s += mp[x.fi];
			}
			if(count == k) break;
		}
		mp = sub;
		sub.clear();
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