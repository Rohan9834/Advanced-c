#include <stdio.h>
#define max 999
int getmin(int dist[10],int visited[10],int n)
{
	int min=max;
	int index;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0&&dist[i]<min)
		{
			min=dist[i];
			index=i;
		}
	}	
return index; 
}
void digikstar(int adj[10][10],int source,int n)
{
	int visited[10];
	int dist[10];
	int min;
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
		dist[i]=max;
	}
	dist[source]=0;
	for(int i=0;i<n;i++)
	{
		min=getmin(dist,visited,n);
		visited[min]=1;
		for(int j=0;j<n;j++)
		{
			if(adj[min][j]!=0&&visited[j]==0&&dist[min]!=max)
			{
				if(adj[min][i]+dist[min]<dist[j])
				{
					dist[j]=dist[min]+adj[min][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d %d\n",i,dist[i]);
	}
}
int main()
{
	int adj[10][10]{
					{0,1,2,3,0},
					{1,0,0,2,2},
					{2,0,0,1,0},
					{3,2,1,0,4},
					{0,2,0,4,0}
		};
		digikstar(adj,0,5);
}
