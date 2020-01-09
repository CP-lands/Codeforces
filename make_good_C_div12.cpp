//--------Anivia_kid---------//
//https://codeforces.com/contest/1270/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	ll n, m;
	cin>>n>>m;
	ll s = m;
	for(int i = 1; i < n; i++){
		int x;
		cin>>x;
		s += x;
		m = m ^ x;
	}
	cout<<2<<'\n';
	cout<<m<<" "<<s + m<<'\n';
 
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