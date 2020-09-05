//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/833/A
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

void Anivia_kid(){
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll st = 1;
	ll end = 1e6;
	while(end > st){
		ll mid = st + (end - st) / 2;
		if(mid * mid * mid > a * b) end = mid;
		else st = mid;
		if(end - st <= 1) break;
	}
	
	if(st * st * st == a * b && a % st == 0 && b % st == 0){
		printf("YES\n");
		return;
	}
	if(end * end * end == a * b && a % end == 0 && b % end == 0){
		printf("YES\n");
		return;
	}
	else printf("NO\n");

	return;

}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	//cin>>q;
	scanf("%d", &q);
	while(q--){
		Anivia_kid();
	}
	return 0;
}
