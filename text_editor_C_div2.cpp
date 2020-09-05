//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/253/C
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++){
		int tmp;
		cin>>tmp;
		v[i] = tmp + 1;
	}
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	int pos = b;
	int res = INT_MAX;
	for(int i = 1; i <= n; i++){
		pos = b;
		int minn = min(a, min(i, x));
		int maxx = max(a, max(i, x));
		for(int j = minn; j <= maxx; j++)
			if(v[j] < pos) pos = v[j];
		int tmp = abs(a - i) + abs(x - i) + abs(pos - y);
		if(res > tmp) res = tmp;
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
