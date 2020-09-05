#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/88/C
using namespace std;

int main() {
	int d, m;
	cin>>d>>m;
	int dd = d;
	int mm = m;
	int k = min(d, m);
	for(int i = 1; i <= k; i++)
		if(d % i == 0 && m % i == 0) {
			d /= i;
			m /= i;
		}
	long long fre = (long long)d * m;
	
	long long Dasha;
	long long Masha;
	if(fre % dd == 0 && fre % mm == 0) {
		Dasha = (long long)fre / dd;
		Masha = (long long)fre / mm;
	}
	else {
		Dasha = (long long)fre / d;
		Masha = (long long)fre / m;
	}
	if(d > m) Dasha++;
	if(d < m) Masha++;
	if(Masha > Dasha)
		cout<<"Masha"<<endl;
	if(Masha < Dasha)
		cout<<"Dasha"<<endl;
	if(Masha == Dasha)
		cout<<"Equal"<<endl;

   	return 0;
}
