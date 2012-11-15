/*
 * =====================================================================================
 *
 *       Filename:  prog8.cpp
 *
 *    Description:  Leaky Bucket Algorithm
 *
 *        Version:  1.0
 *        Created:  11/15/2012 03:38:40 PM
 *       Compiler:  GNU Compiler
 *	       Author:  SkyKOG
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void bktInput(int,int,int);

int main()
{
    system("clear");

    int op,pktSize,i,bktSize,n;
    
    cout<<"Enter Bucket Size : ";
    cin>>bktSize;
    cout<<"Enter Output Rate : ";
    cin>>op;
    cout<<"Enter Number of Packets : ";
    cin>>n;
    
    for(i = 0; i<n ; i++)
    {
        pktSize=rand()%1000;
        cout<<"\n\nPacket Number : "<<i<<"\nPacket Size : "<<pktSize;
        bktInput(pktSize,op,bktSize);
    }

    return 0;
}

void bktInput(int a,int b,int size)
{
    if(a>size)
        cout<<"\nBucket Overflow";
    else 
    {
        while(a>b)
        {
            cout<<"\nBytes Outputted : "<<b;
            a-=b;
        }
        if(a>0)
        {
            cout<<"\nLast Byte Sent : "<<a;
            cout<<"\nBucket Output Successful";
        }

    }
}

