//--------Anivia_kid---------//
//https://codeforces.com/problemset/problem/230/B
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
	vector<ll> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	for(int i = 0; i < n; i++){
		if(v[i] <= 3){
			cout<<"NO\n";
			continue;
		}
		ll low = 2;
		ll high = INT_MAX;
		ll goal = 0;
		while(high > low){
			ll mid = low + (high - low) / 2;
			if(mid * mid == v[i]){
				goal = mid;
				break;
			}
			if(mid * mid < v[i]) low = mid;
			else high = mid;
			if(high == low + 1){
				if(high * high == v[i]){
					goal = high;
					break;
				}
				if(low * low == v[i]){
					goal = low;
					break;
				}
				break;
			}
		}
		bool ok = false;
		if(goal == 0) cout<<"NO\n";
		else{
			for(int i = 2; i * i <= goal; i++){
				if(goal % i == 0){
					ok = true;
					cout<<"NO\n";
					break;
				}
			}
			if(!ok) cout<<"YES\n";
		}
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