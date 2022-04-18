#include <iostream>
#include "letter.h"
#include "broadMethods.h"
using namespace std;

int Letter::count = 0;


void Letter::copy(const Letter& letter)
{
	copyString(this->creationDate, letter.creationDate);
	if (letter.lastReadDate != nullptr)
	{
		copyString(this->lastReadDate, letter.lastReadDate);
	}
	
	copyString(this->sender, letter.sender);
	copyString(this->recipient, letter.recipient);
	copyString(this->title, letter.title);
	copyString(this->content, letter.content);
}

void Letter::free()
{
	delete[] sender;
	delete[] recipient;
	delete[] title;
	delete[] content;
	delete[] creationDate;
	delete[] lastReadDate;
}

Letter::Letter() :sender(nullptr),recipient(nullptr),title(nullptr),content(nullptr)
{
	time_t now = time(0);
	setCreationDate(ctime(&now));
	setLastReadDate(NULL);
}

Letter::Letter(const char* sender, const char* recipient, const char* title, const char* content)
{
	setSender(sender);
	setRecipient(recipient);
	setTitle(title);
	setContent(content);
	time_t now = time(0);
	setCreationDate(ctime(&now));
	setLastReadDate(NULL);
	++count;
}

Letter::Letter(const Letter& letter)
{
	copy(letter);
}

Letter& Letter::operator=(const Letter& letter)
{
	if (this != &letter)
	{
		free();
		copy(letter);
	}
	return *this;
}

Letter::~Letter()
{
	free();
}

int Letter::getLettersCount() 
{
	return count;
}


char* Letter::getSender() const
{
	return this->sender;
}

char* Letter::getRecipient() const
{
	return this->recipient;
}

char* Letter::getTitle() const
{
	return this->title;
}

char* Letter::getContent() const
{
	return this->content;
}

char* Letter::getCreationDate() const
{
	return this->creationDate;
}

char* Letter::getLastReadDate() const
{
	return this->lastReadDate;
}

void Letter::setSender(const char* word)
{
	copyString(this->sender, word);
}

void Letter::setRecipient(const char* word)
{
	copyString(this->recipient, word);
}

void Letter::setTitle(const char* word)
{
	copyString(this->title, word);
}

void Letter::setContent(const char* word)
{
	copyString(this->content, word);
}

void Letter::setCreationDate(char* crDate)
{
	copyString(this->creationDate, crDate);
}

void Letter::setLastReadDate(time_t readDate)
{
	if (readDate != NULL)
	{
		time_t now = time(0);
		copyString(this->lastReadDate, ctime(&now));
	}
	else
	{
		this->lastReadDate = nullptr;
	}
}

void Letter::print()
{   
	cout << "__________________________________________________________________"<<endl;
	cout << "|Sender: " << this->sender << endl;
	cout << "|Recipient: " << this->recipient << endl;
	cout << "|Title: " << this->title << endl;
	cout << "|Content: " << this->content << endl;
	cout << "|                    Created On:" << this->getCreationDate();
	this->getLastReadDate() != NULL ? (cout << "|                    Last Read On:" << this->getLastReadDate()): cout<<"";
	cout << "|__________________________________________________________________"<<endl;
}
