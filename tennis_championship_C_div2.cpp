//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/735/C
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	ll n;
	cin>>n;
	ll res = 3;
	ll tmp1 = 2;
	ll count = 1;
	while(res <= n){
		count++;
		ll tmp = res;
		res += tmp1;
		tmp1 = tmp;
	}
	
	cout<<count<<endl;
 
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
