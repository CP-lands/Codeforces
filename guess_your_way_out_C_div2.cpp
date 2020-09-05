//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/507/C
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	ll h, n;
	cin>>h>>n;
	ll res = 0;
	int dir = 1;
	for(int i = 1; i <= h; i++){
		if(n <= power(2, h - i)){
			if(dir == 1){
				res++;
				dir *= -1;
			}
			else if(dir == -1){
				res += power(2, h - i + 1);
			}
		}
		else{
			if(dir == 1){
				res += power(2, h - i + 1);
			}
			else if(dir == -1){
				res++;
				dir *= -1;
			}
			n -= power(2, h - i);
		}
	}
	cout<<res<<endl;
 
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
