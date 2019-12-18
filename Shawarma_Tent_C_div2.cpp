//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1271/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n, x, y;
	cin>>n>>x>>y;
	int u = 0, d = 0, l = 0, r = 0;
	for(int i = 0; i < n; i++){
		int a,b;
		cin>>a>>b;
		if(a < x) l++;
		if(a > x) r++;
		if(b < y) d++;
		if(b > y) u++;
	}
	if(u >= d && u >= l && u >= r){
		cout<<u<<"\n";
		cout<<x<<" "<<y + 1;
		return;
	}
	if(l >= u && l >= d && l >= r){
		cout<<l<<"\n";
		cout<<x - 1<<" "<<y;
		return;
	}
	if(r >= u && r >= d && r >= l){
		cout<<r<<"\n";
		cout<<x + 1<<" "<<y;
		return;
	}
	else{
		cout<<d<<"\n";
		cout<<x<<" "<<y - 1;
		return;
	}
 
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