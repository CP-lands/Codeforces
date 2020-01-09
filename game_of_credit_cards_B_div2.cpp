//--------Anivia_kid---------//
//https://codeforces.com/problemset/problem/777/B
#include<bits/stdc++.h>

using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

ll dp[100][2];

void Anivia_kid(){
	int n;
	string a, b;
	cin>>n>>a>>b;
	map<char, int> mp;
	for(auto x: b){
		++mp[x];
	}
	int minn = 0, maxx = 0;
	map<char, int> mpp = mp;
	for(auto x: a){
		bool ok = false;
		for(char c = x; c <= '9'; c++){
			if(mp[c] > 0){
				ok = true;
				mp[c]--;
				break;
			}
		}
		if(!ok){
			minn++;
			for(char c = '0'; c < x; c++){
				if(mp[c] > 0){
					mp[c]--;
					break;
				}
			}
		}
	}
	for(auto x: a){
		bool ok = false;
		for(char c = x + 1; c <= '9'; c++){
			if(mpp[c] > 0){
				mpp[c]--;
				ok = true;
				maxx++;
				break;
			}
		}
		if(!ok){
			for(char c = '0'; c < x; c++){
				if(mpp[c] > 0){
					mpp[c]--;
					break;
				}
			}
		}
	}
	cout<<minn<<" "<<maxx<<'\n';

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