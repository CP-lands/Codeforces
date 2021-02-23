//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>

using namespace std;
//https://codeforces.com/contest/1492/problem/C

#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;

void Solve(){
	int n, m;
	string s, t;
	cin>>n>>m>>s>>t;
	vector<int> left(m), right(m);
	int low = 0;
	int index = 0;
	while(low < n && index < m){
		char c = t[index];
		while(low < n && s[low] != c){
			low++;
		}
		left[index++] = low++;
	}
	int high = n - 1;
	index = m - 1;
	while(high >= 0 && index >= 0){
		char c = t[index];
		while(high >= 0 && s[high] != c){
			high--;
		}
		right[index--] = high--;
	}

	int res = 0;

	for(int i = 0; i < m - 1; i++){
		res = max(res, right[i + 1] - left[i]);
	}
	cout<<res<<nl;

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}
