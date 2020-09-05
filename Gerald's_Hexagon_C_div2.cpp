//------Anivia_kid----------
//https://codeforces.com/contest/560/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll; 
 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	vector<int> v(6);
	for(int i = 0; i < 6; i++)
		cin>>v[i];
	double area;
	double side = v[0] + v[1] + v[2];
	area = side * side * sqrt(3) / 4;
	area -= (v[0] * v[0] * sqrt(3) / 4 + v[2] * v[2] * sqrt(3) / 4 + v[4] * v[4] * sqrt(3) / 4);
	area /= sqrt(3) / 4;
	cout<<fixed<<setprecision(0)<<area<<endl;

	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
