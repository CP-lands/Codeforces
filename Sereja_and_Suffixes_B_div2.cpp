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
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++)
		cin>>v[i];
	vector<int> res(n + 1);
	set<int> s;
	for(int i = n; i > 0; i--){
		s.insert(v[i]);
		res[i] = s.size();
	}
	for(int i = 0; i < m; i++){
		int x;
		cin>>x;
		cout<<res[x]<<"\n";
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
