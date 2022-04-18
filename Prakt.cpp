#include <iostream>
#include "post.h"
#include <fstream>
using namespace std;
int main()
{
	const char* username = "vanina@abv.bg";
    Post myPost(username);
	char input[MAXSIZE];
	char* command;
	cout << "Welcome user " << username <<endl;
	cout << "Enter \"help\" if you need help :0\n";
	
	do
	{
		cout <<"You currently have " << Letter::getLettersCount() << " letters in your mail\n"; 
		cin.getline(input,MAXSIZE);
		int length = strlen(input) + 1;
		command = new char[length];
		strcpy(command, input);
		if (strcmp(command, "help") == 0)
		{
			cout << "1.read\n2.send\n3.exit\n";
		}
		else if (strcmp(command, "read") == 0)
		{
			cout << "Enter letter title: " << endl;
			cin.getline(input, MAXSIZE); 
			int inputLength = strlen(input);
			char* fileName = new char[inputLength + 6]; // for terminating null + ".mail" extension 1+5=6
			strncpy(fileName, input, inputLength);
			
			strcpy(fileName + inputLength, ".mail");
			ifstream in(fileName,ios::binary);
			if (in)
			{
				myPost.readLetter(in);
			}
		}
		else if (strcmp(command, "send")==0)
		{
			myPost.sendLetterTo();
		}
		
	} while (strcmp(command,"exit")!=0);
}

