//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1257/C
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<vector<int>> v(n, vector<int>(2));
	for(int i = 0; i < n; i++)
	{
		cin>>v[i][0];
		v[i][1] = i;
	}
	sort(v.begin(), v.end());
	int res = INT_MAX;
	for(int i = 0; i < n - 1; i++){
		if(v[i][0] == v[i + 1][0]){
			if(res > v[i + 1][1] - v[i][1]) res = v[i + 1][1] - v[i][1];
		}
	}
	if(res == INT_MAX) cout<<-1<<endl;
	else
		cout<<res + 1<<endl;
	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
