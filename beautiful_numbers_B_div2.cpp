//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1265/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n + 1);
	vector<int> ord(n + 1);
	for(int i = 1; i <= n; i++){
		cin>>v[i];
		ord[v[i]] = i;
	}
	int minn = ord[1];
	int maxx = ord[1];
	cout<<1;
	for(int i = 2; i <= n; i++){
		minn = min(minn, ord[i]);
		maxx = max(maxx, ord[i]);
		if(maxx - minn == i - 1) cout<<1;
		else cout<<0;
	}
	cout<<"\n";
 
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
