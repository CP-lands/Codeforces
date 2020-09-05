//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/115/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
int l[2001];

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> g[2001];
	queue<int> q;
	vector<bool> visited(2001);
	for(int i = 1; i <= n; i++){
		int x;
		cin>>x;
		if(x == -1){
			q.push(i);
			visited[i] = true;
			l[i] = 1;
		}
		else g[x].pb(i);
	}
	int res = 1;
	while(!q.empty()){
		int k = q.front();
		q.pop();
		for(auto x: g[k]){
			if(!visited[x]){
				visited[x] = true;
				l[x] = l[k] + 1;
				if(res < l[x]) res = l[x];
				q.push(x);
			}
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
