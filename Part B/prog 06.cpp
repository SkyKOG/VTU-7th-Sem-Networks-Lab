//Author : SkyKOG

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int multi(int,int,int);

int main()
{
    system("clear");

    char msg[256];
    int pt[256],ct[256],n,d,e,p,q,z,i,len;
    
    cout<<"\nEnter the message : ";
    cin.getline(msg,256);
    len=strlen(msg);

    cout<<"\nEnter 2 Large Prime Numbers : ";
    cin>>p>>q;

    n=p*q;
    z=(p-1)*(q-1);

    cout<<"\nEnter Prime Value relative to "<<z<<"(z) : ";
    cin>>e;

    for(d=2;d<z;d++)
        if((e*d)%z==1)
            break;

    for(i=0;i<len;i++)
        pt[i]=msg[i];

    cout<<"\nCipher Text : \n";
    for(i=0;i<len;i++)
    {
        ct[i]=multi(pt[i],e,n);
        cout<<ct[i]<<" ";
    }

    cout<<"\n\nPlain Text : \n";
    for(i=0;i<len;i++)
    {
        pt[i]=multi(ct[i],d,n);
        cout<<(char)pt[i];
    }
    cout<<"\n\n";
    return 0;
}

int multi(int txt,int ed,int n)
{
    int i,rem=1;
    for(i=1;i<=ed;i++)
        rem=(rem*txt)%n;
    return rem;
}

