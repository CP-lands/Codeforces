#include<bits/stdc++.h>
//https://codeforces.com/contest/1277/problem/B
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
map<int, int> mp;
set<int> s;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
		if(v[i] % 2 == 0) s.insert(v[i]);
	}
	ll res = 0;
	while(!s.empty()){
		int k = *s.rbegin();
		int count = 0;
		while(k % 2 == 0){
			count++;
			k /= 2;
			if(s.find(k) != s.end()) s.erase(k);
		}
		res += count;
		s.erase(*s.rbegin());
	}
 
	cout<<res<<"\n";
 
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