#include<bits/stdc++.h>

//https://codeforces.com/contest/1360/problem/F 
using namespace std;
 
void Solve(){
	int n, m;
	cin>>n>>m;
	vector<string> s(n);
	for(int i = 0; i < n; i++)
		cin>>s[i];
	for(int i = 0; i < n; i++){
		string t = s[i];
		bool good = true;
		
		for(int j = 0; j < m; j++){
			for(char c = 'a'; c <= 'z'; c++){
				t[j] = c;
				good = true;
				for(int a = 0; a < n; a++){
					if(a == i) continue;
					int diff = 0;
					for(int b = 0; b < m; b++){
						if(t[b] != s[a][b]) diff++;
					}
					if(diff > 1) good = false;
				}
				if(good){
					cout<<t<<'\n';
					return;
				}
				t[j] = s[i][j];
			}
		}
	}
	cout<<-1<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}