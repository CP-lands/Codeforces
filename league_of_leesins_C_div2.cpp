//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1255/C
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

map<int, map<int, int>> mp;
set<int> visited;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> res(n + 1);
	map<int, int> mpp;
	
	for(int i = 0; i < n - 2; i++){
		int a, b, c;
		cin>>a>>b>>c;
		++mp[a][b];
		++mp[a][c];
		++mp[b][a];
		++mp[b][c];
		++mp[c][a];
		++mp[c][b];
		++mpp[a];
		++mpp[b];
		++mpp[c];
	}
	int first;
	for(auto x : mpp){
		if(x. se == 1){
			first = x.fi;
			break;
		}
	}
	res[1] = first;
	for(auto x : mp[first]){
		if(mpp[x.fi] == 2) res[2] = x.fi;
		if(mpp[x.fi] == 3) res[3] = x.fi;
	}
	visited.insert(res[1]);
	visited.insert(res[2]);
	visited.insert(res[3]);
	int i = 3;
	while(i < n - 2){
		for(auto x : mp[res[i]]){
			if(x.se == 2 && visited.find(x.fi) == visited.end()){
				res[++i] = x.fi;
				visited.insert(x.fi);
			}
		}
	}
	for(auto x : mpp){
		if(x.se == 1 && visited.find(x.fi) == visited.end()) res[n] = x.fi;
		if(x.se == 2 && visited.find(x.fi) == visited.end()) res[n - 1] = x.fi;
	}

	for(int i = 1; i <= n; i++)
		cout<<res[i]<<" ";
	cout<<endl;
	//3 2 1 7 6 5 4
 
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
