//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1253/B
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
	vector<int> v(n), res;
	for(int i = 0; i < n; i++)
		cin>>v[i];
	set<int> in, out;
	int days = 0;
	for(int i = 0; i < n; i++){
		if(v[i] > 0){
			if(in.find(v[i]) == in.end()) in.insert(v[i]);
			else{
				if(in.size() == out.size()){
					days++;
					res.pb(in.size() * 2);
					in.clear();
					out.clear();
					in.insert(v[i]);
				}
				else{
					cout<<-1<<endl;
					return;
				}
			}
		}
		else{
			if(out.find(v[i]) == out.end() && in.find(-v[i]) != in.end()) out.insert(v[i]);
			else{
				cout<<-1<<endl;
				return;
			}
		}
		if(!in.empty() && in.size() == out.size()){
			days++;
			res.pb(in.size() * 2);
			in.clear();
			out.clear();
		}
	}
	if(in.size() != out.size()){
		cout<<-1<<endl;
		return;
	}

	cout<<days<<"\n";
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<" ";
 
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
