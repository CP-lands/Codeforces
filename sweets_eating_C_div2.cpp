//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1253/C
using namespace std;
 
#define ff first
#define ss second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
const int N = 200200;

ll candy[N];
void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < n; i++)
		cin>>candy[i];
	sort(candy, candy+n);
	ll res = 0;
	for(int i = 0; i < n; i++){
		if(i + 1 > m) candy[i] += candy[i - m];
		res += candy[i];
		cout<<res<<" ";
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
	return 0;
}
