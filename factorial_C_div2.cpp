#include<iostream>
#include <bits/stdc++.h> 

//https://codeforces.com/problemset/problem/515/C
using namespace std;

int main() {
	int n,tmp;
	string a;
	cin>>n>>a;
	string s;
	int k = 0;
	map<int, string> M;
	M[4] = "322";
	M[6] = "53";
	M[8] = "7222";
	M[9] = "7332";
	for(int i = 0; i < n; i++) if (a[i] > '1') {
		tmp = a[i] - '0';
		if (M.count(tmp))
			s += M[tmp];
		else
			s += a[i];
	}
	//sort(end(s), begin(s));
	sort(begin(s), end(s));
	reverse(begin(s), end(s));
	cout << s << endl;
	return 0;
}
