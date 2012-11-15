//Program to perform CRC generation and error detection
//For the CRC-CCITT 16 bit checksum.

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

#define GENERATOR_LENGTH 17

char XOR(char a , char b){
	if(a == b)
		return '0';
	else
		return '1';
}

string divide(string message,string generator){
	string remainder(message.size(),'-');
	int pos;
	pos = message.find('1');
	while(pos<(message.size()-16)){		
		cout<<"POS is : "<<pos<<endl;
		for (int i = pos ,j=0; j<generator.size() ; i++,j++){
			remainder[i]=XOR(message[i],generator[j]);	
		}
		cout<<"Till  Now remainder is:"<<remainder<<endl;
		pos = message.find('1',pos+1);		
	}
	return(remainder);
}

int main()
{
    system("clear");

	int c;
	string message;
	
    cout<<"Please enter the Message bit pattern :";
	cin>>message;
	
    string message_with_zeros=message+"0000000000000000";
	
    string generator("10001000000100001");
	
    cout<<"The CRC-CCITT Generator is : "<<generator<<endl;
	cout<<"The message with zeros is  : "<<message_with_zeros<<endl;
	
    string remainder;
	remainder = divide(message_with_zeros,generator); 
	cout<<"Remainder is: "<<remainder<<endl;
	string checksum (remainder,remainder.size()-16,16);
	cout<<"checksum :"<<checksum<<endl;

	string message_and_checksum;
	message_and_checksum = message + checksum;
	
	cout<<"Message to be sent to the reciever : "<<message_and_checksum<<endl;

	cout<<"Enter the Message recieved by the Reciever:";
	string reciever_message;
	cin>>reciever_message;

	remainder = divide(reciever_message,generator);
	int pos = remainder.find('1');
	if(pos == string::npos){
		cout<<"The message is error FREE !!"<<endl;
	}
	else{
		cout<<"The message contains ERRORS :(\n The Remainder is :"<<remainder<<endl;
	}
	return(0);
}
