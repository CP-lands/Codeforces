//--------Anivia_kid---------//
//https://codeforces.com/contest/1283/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n + 1);
	set<int> s;
	vector<int> a(n + 1);
	vector<bool> visited(n + 1);
	vector<int> res;
	for(int i = 1; i <= n; i++){
		cin>>v[i];
		if(v[i] == 0) a[i] = 1;
		else{
			visited[v[i]] = true;
		}
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]) s.insert(i);
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == 1 && !visited[i]) res.pb(i);
	}
	if(res.size() == 1){
		if(res[0] != *s.begin()){
			v[res[0]] = *s.begin();
			s.erase(*s.begin());
		}
		else{
			v[res[0]] = *s.rbegin();
			s.erase(*s.rbegin());
		}
		a[res[0]] = 0;
	}
	if(res.size() > 1){
		for(int i = 0; i < res.size() - 1; i++){
			v[res[i]] = res[i + 1];
			a[res[i]] = 0;
			s.erase(res[i + 1]);
		}
		v[res[res.size() - 1]] = res[0];
		s.erase(res[0]);
		a[res[res.size() - 1]] = 0;
	}
 
	for(int i = 1; i <= n; i++){
		if(a[i] == 0) continue;
		v[i] = *s.rbegin();
		s.erase(*s.rbegin());
 
	}
	for(int i = 1; i <= n; i++)
		cout<<v[i]<<" ";
 
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