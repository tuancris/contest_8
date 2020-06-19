#include<bits/stdc++.h>
using namespace std;
int m,n,a[1005][1005],check[1005][1005];
bool is_ok(int x,int y)
{
	if(x>=1 && x<=m && y>=1 && y<=n)
	return true;
	return false;
}
int move()
{
	int ans=0;
	if(m==1 && n==1)
	return 0;
	pair<int,int> p={1,1};
	queue<pair<int,int>> q;
	q.push(p);
	while(!q.empty())
	{
		ans++;
		int size=q.size();
		while(size--)
		{
 
		   p=q.front(); q.pop();
		   int x=p.first,y=p.second;
		   int tmp=y+a[x][y];
		   if(tmp==n && x==m)
		   return ans;
		   else if(is_ok(x,tmp) && check[x][tmp]==0)
		   {   
		       q.push(make_pair(x,tmp));
		       check[x][tmp]=1;
		    }
		    tmp=x+a[x][y];
		    if(tmp==m && y==n)
		    return ans;
		    else if(is_ok(tmp,y) && check[tmp][y]==0)
		    {
		    	q.push(make_pair(tmp,y));
		    	check[tmp][y]=1;
		    }
		}
	}
	return -1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(check,0,sizeof(check));
		check[1][1]=1;
		cin>>m>>n;;
		for(int i=1;i<=m;i++)
		   for(int j=1;j<=n;j++)
		      cin>>a[i][j];
	    cout<<move()<<endl;
	}
	return 0;
}
 