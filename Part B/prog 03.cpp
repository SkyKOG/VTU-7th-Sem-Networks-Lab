// Author : SkyKOG

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node 
{
	int dist[20];
	int from[20];
}rt[20];

int main()
{
	system("clear");

	int dmat[20][20];
	int n=0,i,j,k,count;

	cout<<"\nEnter The Number of Nodes : ";
	cin>>n;

	cout <<"\nEnter The Cost Matrix : ";
	for (i = 1; i <= n ; i++ )
 	{
 		for (j = 1; j <= n ; j++ )
 		{
 			cin>>dmat[i][j];
 			dmat[i][i]=0;
 			rt[i].dist[j]=dmat[i][j];
 			rt[i].from[j]=j;
 		}	
	}

	for ( i = 1; i <= n ; i++ )
	{
		for ( j = 1; j <= n ; j++ )
		{
			for ( k = 1; k <= n ; k++ )
			{
				if (rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j])
				{
					rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
					rt[i].from[j] = k;
				}
			}
		}
	}	

	for ( i = 1 ; i <= n; i++)
	{
		cout<<"\nState value for router : "<<i<<"\n";
		for ( j = 1; j <= n; j++)
		{
			cout<<"\nDestination Node : "<<j<<" Next Node : "<<rt[i].from[j]<<" Distance : "<<rt[i].dist[j]<<"\n";
		}
	}
	return 0;
}