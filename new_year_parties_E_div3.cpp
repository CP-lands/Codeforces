//--------Anivia_kid---------//
//https://codeforces.com/contest/1283/problem/E
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
map<int, int> mp;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
		++mp[v[i]];
	}
	int minn = 0;
	int maxx = 0;
	sort(v.begin(), v.end());
	int count = 0;
	vector<int> a = v;
	int i = 0;
	while(i < n){
		int x = v[i] + 2;
		while(i < n && v[i] <= x)
			i++;
		minn++;
	}
	vector<bool> visited(n + 2);
	for(auto x: mp){
		int k = x.fi;
		if(mp[k] == 1){
			if(visited[k - 1] == false){
				visited[k - 1] = true;
			}
			else if(visited[k] == false){
				visited[k] = true;
			}
			else
				visited[k + 1] = true;
		}
		else if(mp[k] == 2){
			int tmp = 0;
			if(visited[k - 1] == true){
				visited[k] = true;
				visited[k + 1] = true;
			}
			else{
				visited[k - 1] = true;
				visited[k] = true;
			}
			
		}
		else if(mp[k] >= 3){
			visited[k - 1] = true;
			visited[k + 1] = true;
			visited[k] = true;
		}
	}
	for(int i = 0; i <= n + 1; i++){
		if(visited[i]) maxx++;
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