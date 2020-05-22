#include<bits/stdc++.h>

//https://codeforces.com/contest/559/problem/B
using namespace std;

bool isEqual(string a, string b){
	if(a == b) return true;
	else if(a.size() % 2) return false;
	else{
		string a1 = "", a2 = "", b1 = "", b2 = "";
		for(int i = 0; i < a.size() / 2; i++){
			a1 += a[i];
			b1 += b[i];
			a2 += a[i + a.size() / 2];
			b2 += b[i + b.size() / 2];
		}
		if((isEqual(a1, b2) && isEqual(a2, b1)) || (isEqual(a1, b1) && isEqual(a2, b2))) return true;
		else return false;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b;
	cin>>a>>b;
	if(isEqual(a, b)) cout<<"YES\n";
	else cout<<"NO\n";

}