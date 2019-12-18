//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/4/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, sum;
	cin>>n>>sum;
	vector<pair<int, int>> v;
	int maxx = 0;
	int minn = 0;
	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		v.pb({x, y});
		maxx += y;
		minn += x;
	}
	if(sum < minn || sum > maxx){
		cout<<"NO\n";
		return;
	}
	int need = sum - minn;
	cout<<"YES\n";
	for(int i = 0; i < n; i++){
		int tmp = min(v[i].se, v[i].fi + need);
		cout<<tmp<<" ";
		need -= tmp - v[i].fi;
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
