#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;
#define FSIZE 3

int main(void){
	string message;

	//get message
	cout<<"Please enter the message :";
	getline(cin,message);
	cout<<"The message you entered is :"<<message;

	//parse the message in FSIZE frames.
	vector<string> frames;
	cout<<"Dividing the message into Frames of size : "<<FSIZE<<endl;
	for(int i = 0 ; i < message.size() ; i=i+3){
		string f(message,i,3);
		frames.push_back(f);
	}
	//Display the parsed Frames
	cout<<"The Frames after dividing are as follows:"<<endl;
	for(int i=0;i < frames.size();i++)
		cout<<i+1<<"   "<<frames.at(i)<<endl;
	//Get the random sequence of Packets recieved at the reciever.
	cout<<"Get the random sequence of Packets recieved at the reciever:";
	vector<int> reciever;
	for(int i=0;i<frames.size();i++){
		int n;
		scanf("%d",&n);
		reciever.push_back(n);
	}
	cout<<"The Jumbled Packets at the recieving end"<<endl;
	for(int i=0;i<reciever.size();i++){
		cout<<frames.at(reciever.at(i)-1)<<endl;
	}
	cout<<"Sorting the packets......";
	sort(reciever.begin(),reciever.end());
	cout<<"Packets sorted......\n";
	for(int i=0;i<frames.size();i++){
		cout<<frames.at(reciever.at(i)-1);
	}
	cout<<endl;
	return(0);
}
