#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	int a[2*n];
	for(int i = 1; i < 2*n; i = i  + 2)
	{
		a[i] = i;
	}
	int temp = 2;
	for(int i = n + 1; i < 2*n; i = i + 2)
	{
		a[i] = temp;
		temp = temp + 2;
	}
	temp = 2*n;
	for(int i = n - 1; i >= 0; i = i - 2)
	{
		a[i] = temp;
		temp = temp - 2;
	}
	cout<<"YES"<<endl;
	for(int i = 0; i < 2*n; i++)
		cout<<a[i]<<" ";
	return 0;
}