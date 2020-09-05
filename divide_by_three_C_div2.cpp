//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/792/C
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

void Anivia_kid(){
	string n;
	cin>>n;
	vector<vector<int>> v(n.size(), vector<int> (2));
	set<int> s0, s1, s2;
	ll sum = 0;
	for(int i = 0; i < n.size(); i++){
		if((n[i] - '0') % 3 == 0) s0.insert(i);
		if((n[i] - '0') % 3 == 1) s1.insert(i);
		if((n[i] - '0') % 3 == 2) s2.insert(i);
		sum += n[i] - '0';
	}
	if(sum % 3 == 0){
		cout<<n<<endl;
		return;
	}

	if(s1.size() > s2.size()){
		if((s1.size() - s2.size()) % 3 == 1) s1.erase(*s1.rbegin());
		if((s1.size() - s2.size()) % 3 == 2){
			if(s2.size() > 0 && (*s2.rbegin() > 0 || n[1] != '0')) s2.erase(*s2.rbegin());
			else{
				s1.erase(*s1.rbegin());
				s1.erase(*s1.rbegin());
			}
		}
	}
	if(s2.size() > s1.size()){
		if((s2.size() - s1.size()) % 3 == 1) s2.erase(*s2.rbegin());
		if((s2.size() - s1.size()) % 3 == 2){
			if(s1.size() > 0 && (*s1.rbegin() > 0 || n[1] != '0')) s1.erase(*s1.rbegin());
			else{
				s2.erase(*s2.rbegin());
				s2.erase(*s2.rbegin());
			}
		}
	}

	string res = "";
	while(true){
		int a = INT_MAX;
		int b = INT_MAX;
		int c = INT_MAX;
		if(!s0.empty()){
			a = *s0.begin();
		}
		if(!s1.empty()){
			b = *s1.begin();
		}
		if(!s2.empty()){
			c = *s2.begin();
		}
		if(a < b && a < c){
			res += n[a];
			s0.erase(*s0.begin());
		}
		if(b < a && b < c){
			res += n[b];
			s1.erase(*s1.begin());
		}
		if(c < b && c < a){
			res += n[c];
			s2.erase(*s2.begin());
		}
		if(s0.empty() && s1.empty() && s2.empty()) break;
	}
	if(res.size() == 0){
		cout<<-1<<endl;
		return;
	}
	if(res[0] != '0'){
		cout<<res<<endl;
		return;
	}
	int i = 0; 
	while(res[i] == '0')
		i++;
	if(i == res.size()){
		cout<<0<<endl;
		return;
	}
	for(i; i < res.size(); i++)
		cout<<res[i];

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
