#include<bits/stdc++.h>
 
//https://codeforces.com/contest/584/problem/C
using namespace std;
 
void Solve(){
 	int n, k;
 	cin>>n>>k;
 	string s1, s2;
 	cin>>s1>>s2;
 	int same = 0;
 	for(int i = 0; i < n; i++)
 		if(s1[i] == s2[i]) same++;
 	int common = n - k;
 	int rest = n - same;
 	if(rest / 2 < common - same) cout<<-1<<'\n';
 	else{
 		if(common - same <= 0){
 			string res = "";
 			for(int i = 0; i < n; i++){
 				if(s1[i] == s2[i]){
 					if(common > 0){
 						res += s1[i];
 						common--;
 					}
 					else{
 						for(char c = 'a'; c <= 'z'; c++){
 							if(c != s1[i] && c != s2[i]){
 								res += c;
 								break;
 							}
 						}
 					}
 				}
 				else{
 					for(char c = 'a'; c <= 'z'; c++){
 						if(c != s1[i] && c != s2[i]){
 							res += c;
 							break;
 						}
 					}
 				}
 			}
 			cout<<res<<'\n';
 		}
 		else{
 			string res = "";
 			int remain = common - same;
 			int remain1 = 0, remain2 = 0;
 			for(int i = 0; i < n; i++){
 				if(s1[i] == s2[i]) res += s1[i];
 				else{
 					if(remain1 < remain){
 						res += s1[i];
 						remain1++;
 					}
 					else if(remain2 < remain){
 						res += s2[i];
 						remain2++;
 					}
 					else{
 						for(char c = 'a'; c <= 'z'; c++){
 							if(c != s1[i] && c != s2[i]){
 								res += c;
 								break;
 							}
 						}
 					}
 				}
 			}
 			cout<<res<<'\n';
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