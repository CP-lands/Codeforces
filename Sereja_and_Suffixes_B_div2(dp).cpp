//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/368/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	int v[100005];
	int res[100005] = {0};
	bool e[100005];
	for(int i = 1; i <= n; i++){
		cin>>v[i];
	}
	for(int i = n; i > 0; i--){
		if(e[v[i]] == true) res[i] = res[i + 1];
		else{
			res[i] = res[i + 1] + 1;
			e[v[i]] = true;
		}
	}
	for(int i = 0; i < m; i++){
		int tmp;
		cin>>tmp;
		cout<<res[tmp]<<"\n";
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
