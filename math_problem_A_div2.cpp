//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1227/A
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	int n;
	cin>>n;
	int start = INT_MAX;
	int end = INT_MIN;
	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		start = min(start, max(x, y));
		end = max(end, min(x, y));
	}
	if(end - start > 0) cout<<end - start<<endl;
	else cout<<0<<endl;
 
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
	return 0;
}
