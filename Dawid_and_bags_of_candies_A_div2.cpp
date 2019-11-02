#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> a(4);
	int sum = 0;
	for(int i = 0; i < 4; i++)
	{
		cin>>a[i];
		sum = sum + a[i];
	}
	if(sum % 2 != 0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	sum = sum / 2;
	sort(a.begin(), a.end());
	if(a[0] + a[3] == a[2] + a[1] || a[0] + a[1] + a[2] == a[3])
	{
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}