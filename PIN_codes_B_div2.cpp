//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1263/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
set<int> s;
void Anivia_kid(){
	int n;
	cin>>n;
	vector<string> v(n);
	map<string, int> mp;
	for(int i = 0; i < n; i++){
		cin>>v[i];
		++mp[v[i]];
		s.insert(string_to_int(v[i]));
	}
	if(mp.size() == n){
		cout<<0<<"\n";
		for(auto x: v)
			cout<<x<<"\n";
		return;
	}
	cout<<n - mp.size()<<"\n";
	for(auto x: v){
		if(mp[x] == 1) cout<<x<<"\n";
		else{
				string y = x;
				for(int i = 0; i < 4; i++){
					x = y;
					int k = x[i] - '0';
					while(k <= 19 && s.find(string_to_int(x)) != s.end()){
						x[i] = k % 10 + '0';
						k++;
					}
					if(s.find(string_to_int(x)) == s.end()) break;
				}
				s.insert(string_to_int(x));
				cout<<x<<"\n";
				mp[y]--;
		}
	}
 
	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
}