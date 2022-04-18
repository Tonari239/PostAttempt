#include <iostream>
#include "post.h"
#include <fstream>
#include "broadMethods.h"
using namespace std;


void Post::free()
{
	delete[] sender;
}

void Post::copy(const Post& other)
{
	copyString(this->sender, other.sender);
}

Post::Post(const char* senderName)
	{
		copyString(this->sender, senderName);
	}

Post::Post(const Post& other)
	{
		copy(other);
	}

Post& Post::operator=(const Post& other)
	{
		if (this != &other)
		{
			free();
			copy(other);
		}
		return *this;
	}

Post::~Post()
	{
		free();
	}

Post& Post::sendLetterTo()
	{
		char input[MAXSIZE];
		cout << "Enter who you want to send a letter to:\n";
		cin.getline(input, MAXSIZE);
		char* recipient = new char[strlen(input)];
		copyString(recipient, input);
		cout << "Enter title:\n";
		cin.getline(input, MAXSIZE);
		char* title = new char[strlen(input)];
		copyString(title, input);

		cout << "Enter letter content:\n";
		cin.getline(input, MAXSIZE);
		char* content = new char[strlen(input)];
		copyString(content, input);

		Letter letter(this->sender, recipient, title, content);

		char* fileName = new char[strlen(title) + 6];
		strcpy(fileName, title);
		strcpy(fileName + strlen(title), ".mail");

		
		ofstream out(fileName, ios::binary);

		int length = strlen(this->sender);
		out.write((const char*)&length, sizeof(length));
		out.write((const char*)letter.getSender(), length);


		length = strlen(recipient);
		out.write((const char*)&length, sizeof(length));
		out.write((letter.getRecipient()), length);

		

		length = strlen(title);
		out.write((const char*)&length, sizeof(length));
		out.write(letter.getTitle(), length);

		length = strlen(content);
		out.write((const char*)&length, sizeof(length));
		out.write(letter.getContent(), length);


		delete[] recipient;
		delete[] title;
		delete[] content;
		return *this;
	}

void Post::readLetter(ifstream& file)
	{
		Letter letter;

		//sender
		int senderLength;

		file.read((char*)&senderLength, sizeof(senderLength)); 

		this->sender = new char[senderLength + 1];
		file.read(this->sender, senderLength);
		this->sender[senderLength] = '\0';

		letter.setSender(this->sender);

		//recipient
		int recipientLength;
		file.read((char*)&recipientLength, sizeof(recipientLength)); 

		char* recipient = new char[recipientLength + 1];
		file.read(recipient, recipientLength);
		recipient[recipientLength] = '\0';
		letter.setRecipient(recipient);

		//title
		int titleLength;
		file.read((char*)&titleLength, sizeof(titleLength));

		char* title = new char[titleLength + 1];
		file.read(title, titleLength);
		title[titleLength] = '\0';
		letter.setTitle(title);

		//content
		int contentLength;
		file.read((char*)&contentLength, sizeof(contentLength));

		char* content = new char[contentLength + 1];
		file.read(content, contentLength);
		content[contentLength] = '\0';
		letter.setContent(content);
		letter.print();
	}
