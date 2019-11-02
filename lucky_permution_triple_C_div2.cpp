#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n == 1)
	{
		cout<<0<<endl<<0<<endl<<0;
		return 0;
	}

	if(n % 2 == 0)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i = 0; i < n; i++)
		cout<<i<<" ";
	cout<<endl;
	for(int i = 1; i <= n; i++)
		cout<<i % n<<" ";
	cout<<endl;
	for(int i = 0; i < n; i++)
	{
		int tmp = (i + (i + 1) % n) % n;
		cout<<tmp<<" ";
	}
	return 0;
}