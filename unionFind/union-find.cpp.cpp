#include<iostream>
#include<string>
using namespace std;

int parent[1001];

void makeSet(int n)
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
	}
}

int find(int v)
{
	if(v==parent[v]) return v;
	parent[v]=find(parent[v]); 
	return find(parent[v]);
}

int Union(int a, int b)
{
	cout<<"enter 2 doi tuong union : ";
	cin>>a>>b;
	a=find(a);
	b=find(b);
	if(a!=b) parent[b]=a;
}

void checkConnected(int a, int b)
{
	cout<<"enter 2 doi tuong check : ";
	cin>>a>>b;
	
	if(find(a)==find(b))
	{
	   cout<<a<<" va "<<b<<" conected ";
	} 
	else(cout<<a<<" va "<<b<<" Unconected ");
}

int main()
{
	int a,b;
	int v;
	int n;
	cout<<"enter n : ";
	cin>>n;

	makeSet(n);
	
	string str;
	
	while(true)
	{
	     Union(a,b);
	     cout<<"can you want union exit : ";
	     cin>>str;
	     if(str=="ok") break;
	}
	while(true)
	{
		checkConnected(a,b);
		cout<<"you can exit check : ";
		cin>>str;
		if(str=="ok") break;
	}
	
	return 0;
}
