//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/388/A
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	int count = 0;
	int res = 0;
	while(count < n){
		count++;
		int tmp = 0;
		v[0] = INT_MAX;
		for(int i = 1; i < n; i++){
			if(v[i] != INT_MAX && v[i] > tmp){
				tmp++;
				v[i] = INT_MAX;
			}
		}
		res++;
		sort(v.begin(), v.end());
		if(v[0] == INT_MAX) break;
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
