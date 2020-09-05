//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/274/A
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	ll n, k;
	cin>>n>>k;
	set<int> s;
	if(k == 1){
		cout<<n<<endl;
		return;
	}
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		if(v[i] % k != 0) s.insert(v[i]);
		else{
			if(s.find(v[i] / k) == s.end()) s.insert(v[i]);
		}
	}

	cout<<s.size()<<endl;
	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
