//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1474/problem/C
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here"<<nl
typedef long long ll;
 
map<int, int> mm;
set<int> s;
 
void Solve(){
	int n;
	cin>>n;
	vector<int> v(2 * n);
	for(int i = 0; i < 2 * n; i++)
		cin>>v[i];
	sort(v.rbegin(), v.rend());
	for(int i = 1; i < 2 * n; i++){
		int x = v[0] + v[i];
		int ans = x;
		int sub = v[0];
		vector<pair<int, int>> res;
		
		for(int j = 0; j < 2 * n; j++){
			++mm[v[j]];
			s.insert(v[j]);
		}
		while(!s.empty()){
			int need = x - sub;
			if(s.find(need) == s.end() || (need == sub && mm[need] <= 1)) break;
			res.pb({sub, need});
			mm[sub]--;
			mm[need]--;
			if(mm[sub] <= 0){
				s.erase(sub);
			}
			if(mm[need] <= 0){
				s.erase(need);
			}
			x = sub;
			if(!s.empty()) sub = *s.rbegin();
		}
		if(s.empty()){
			mm.clear();
			s.clear();
			cout<<"YES"<<nl<<ans<<nl;
			for(auto y: res) cout<<y.fi<<" "<<y.se<<nl;
			return;
		}
		mm.clear();
		s.clear();
	}
	cout<<"NO"<<nl;
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}