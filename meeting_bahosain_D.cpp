//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/gymProblem/102263/D
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int m, n;
	cin>>m>>n;
	vector<int> v1(m), v2(n);
	for(int i = 0; i < m; i++)
		cin>>v1[i];
	for(int i = 0; i < n; i++)
		cin>>v2[i];
	int gcd2 = v2[0];
	for(int i = 1; i < n; i++){
		gcd2 = get_gcd(gcd2, v2[i]);
	}
	for(int i = 1; i < m; i++){
		if((v1[i] - v1[i - 1]) % gcd2 != 0){
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
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
