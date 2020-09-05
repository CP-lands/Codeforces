//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1243/B2
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 

void Anivia_kid(){
	int n;
	string s1, s2;
	cin>>n>>s1>>s2;
	vector<vector<int>> res;
	for(int i = 0; i < n; i++){
		if(s1[i] == s2[i]) continue;
		for(int j = i + 1; j < n; j++){
			if(s2[j] == s2[i] && s1[j] != s2[j]){
				res.push_back({i + 1, j + 1});
				char c = s1[i];
				s1[i] = s2[j];
				s2[j] = c;
				break;
			}
		}
		if(s1[i] != s2[i]){
			for(int j = i + 1; j < n; j++){
				if(s1[j] == s2[i] && s1[j] != s2[j]){
					res.push_back({j + 1, j + 1});
					char c = s1[j];
					s1[j] = s2[j];
					s2[j] = c;
					res.push_back({i + 1, j + 1});
					c = s1[i];
					s1[i] = s2[j];
					s2[j] = c;
					break;
				}
			}
		}
		if(s1[i] != s2[i]){
			cout<<"No"<<endl;
			return;
		}
	}
	if(res.size() > 2 * n){
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	cout<<res.size()<<endl;
	for(int i = 0; i < res.size(); i++)
		cout<<res[i][0]<<" "<<res[i][1]<<endl;

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
