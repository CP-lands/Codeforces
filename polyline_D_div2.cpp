#include<bits/stdc++.h>
 
//https://codeforces.com/contest/617/problem/D
using namespace std;
 
void Solve(){
 	int a, b, c, d, e, f;
 	cin>>a>>b>>c>>d>>e>>f;
 	if((a == c && c == e) || (b == d && d == f)){
 		cout<<1<<endl;
 		return;
 	}
 	if((a == c && (f >= max(b, d) || f <= min(b, d))) || (a == e && (d >= max(b, f) || d <= min(b, f))) || (c == e && (b <= min(d, f) || b >= max(d, f))) || (b == d &&(e <= min(a, c) || e >= max(a, c))) || (b == f && (c <= min(a, e) || c >= max(a, e)) || (d == f && (a <= min(e, c) || a >= max(c, e))))) cout<<2<<endl;
 	else cout<<3<<endl;
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}