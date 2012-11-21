/*
 * Authors: SkyKOG & MoNk
 * Distance Vector Routing Algorithm 
 */

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

	int flag = 1;

	while (flag) 
	{
		flag = 0;
		for ( i = 1; i <= n ; i++ )
		{
			for ( j = 1; j <= n ; j++ )
			{
				for ( k = 1; k <= n ; k++ )
				{
					if ( rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j])
					{
						flag = 1;
						rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
						rt[i].from[j] = k;
					}
				}
			}
		}	
	}
	

	for ( i = 1 ; i <= n; i++)
	{
		cout<<"\nRouting table for NODE :"<<i<<" \n";
		cout<<"Destination\tOutgoing Line\tTotal Distance\t\n"; 
		for ( j = 1; j <= n; j++)
		{
			if(i==j) continue;
			cout<<j<<"\t\t"<<rt[i].from[j]<<"\t\t"<<rt[i].dist[j]<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
