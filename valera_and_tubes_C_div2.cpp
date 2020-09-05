//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/441/C
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

void Anivia_kid(){
	int n, m, k;
	cin>>n>>m>>k;
	int x = 1, y = 1;
	vector<pair<int, int>> res;
	int count = 0;
	int direct = 1;
	while(true){
		//if(count < n * m - 2 * (k - 1) && count / 2 < k) res[count / 2].pb({x, y});
		res.pb({x, y});
		if(count % 2 == 1 &&  count / 2 < k - 1){
			cout<<2<<" ";
			for(auto x: res)
				cout<<x.fi<<" "<<x.se<<" ";
			cout<<"\n";
			res.clear();
		}
		if(count == n * m - 1) break;
		if(direct == 1){
			if(y == m){
				x++;
				direct = -1;
			}
			else y++;
			count++;
		}
		else if(direct == -1){
			if(y == 1){
				x++;
				direct = 1;
			}
			else y--;
			count++;
		}
	}
	cout<<n * m - 2 * (k - 1)<<" ";
	for(auto x: res)
		cout<<x.fi<<" "<<x.se<<" ";

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
