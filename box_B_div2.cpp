//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1262/B
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	vector<int> res(n);
	res[0] = v[0];
	int maxx = res[0];
	int tmp = 1;
	set<int> used;
	used.insert(res[0]);
	for(int i = 1; i < n; i++){
		if(v[i] > maxx){
			res[i] = v[i];
			maxx = res[i];
			used.insert(maxx);
		}
		else if(v[i] == maxx && v[i] >= i + 1) res[i] == 0;
		else{
			cout<<-1<<endl;
			return;
		}
	}
	vector<int> sub;
	for(int i = 1; i <= n; i++){
		if(used.find(i) == used.end()) sub.pb(i);
	}
	int j = 0;
	for(auto x: res){
		if(x != 0) cout<<x<<" ";
		else cout<<sub[j++]<<" ";
	}
	cout<<endl;
 
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
