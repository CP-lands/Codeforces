#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1468/problem/C
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
	int q;
	cin>>q;
	set<pair<int, int>> s1, s2;
	map<int, set<int>> mm;
	int index = 1;
	for(int i = 1; i <= q; i++){
		int type;
		cin>>type;
		if(type == 1){
			int m;
			cin>>m;
			s1.insert({index, m});
			s2.insert({m, index});
			mm[m].insert(index++);
		}
		if(type == 2){
			pair<int, int> p = *s1.begin();
			s1.erase(s1.begin());
			s2.erase({p.se, p.fi});
			cout<<p.fi<<" ";
		}
		if(type == 3){
			pair<int, int> p = *s2.rbegin();
			int k = *mm[p.fi].begin();
			cout<<k<<" ";
			s2.erase({p.fi, k});
			s1.erase({k, p.fi});
			mm[p.fi].erase(mm[p.fi].begin());
		}
	}
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}