//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1271/problem/E
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

bool odd(ll x, ll n, ll k){
	ll res = 0;
	ll count = 1;
	while(x <= n){
		if(n - x + 1 >= count) res += count;
		else res += n - x + 1;
		count *= 2;
		x *= 2;
	}
	if(res >= k) return true;
	else return false;
}

bool even(ll x, ll n, ll k){
	ll res = 0;
	ll count = 2;
	while(x <= n){
		if(n - x + 1 >= count) res += count;
		else res += n - x + 1;
		count *= 2;
		x *= 2;
	}
	if(res >= k) return true;
	else return false;
}

void Anivia_kid(){
	ll n, k;
	cin>>n>>k;
	if(n == k){
		cout<<1<<'\n';
		return;
	}
	ll res = 1;
	ll low = 1;
	ll high = n;
	while(high > low + 1){
		ll mid = low + (high - low) / 2;
		if(mid % 2 != 0){
			if(odd(mid, n, k)){
				if(res < mid) res = mid;
				low = mid;
			}
			else high = mid;
		}
		else{
			if(odd(mid + 1, n, k) && mid + 1 <= n){
				if(res < mid + 1) res = mid + 1;
				low = mid;
			}
			else if(odd(mid - 1, n, k) && mid - 1 >= 1){
				if(res < mid - 1) res = mid - 1;
				low = mid;
			}
			else high = mid;
		}
	}
	low = 1;
	high = n;
	while(high > low + 1){
		ll mid = low + (high - low) / 2;
		if(mid % 2 == 0){
			if(even(mid, n, k)){
				if(res < mid) res = mid;
				low = mid;
			}
			else high = mid;
		}
		else{
			if(even(mid + 1, n, k) && mid + 1 <= n){
				if(res < mid + 1) res = mid + 1;
				low = mid;
			}
			else if(even(mid - 1, n , k) && mid - 1 >= 0){
				if(res < mid - 1) res = mid - 1;
				low = mid;
			}
			else high = mid;
		}
	}
	if(n == 2){
		if(k == 1) res = 2;
		if(k == 2) res = 1;
	}

	cout<<res<<'\n';

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