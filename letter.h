#ifndef __Letter
#define __Letter

#define MAXSIZE 1024
#include <iostream>
using namespace std;

class Letter
{
	static int count;
	char* sender;
	char* recipient;
	char* title;
	char* content;
	char* creationDate;
	char* lastReadDate;

	void copy(const Letter& letter);
	void free();
public:
	char* getSender() const;
	char* getRecipient() const;
	char* getTitle() const;
	char* getContent() const;
	char* getCreationDate() const;
	char* getLastReadDate() const;
	static int getLettersCount();

	void setSender(const char* word);
	void setRecipient(const char* word);
	void setTitle(const char* word);
	void setContent(const char* word);
	void setCreationDate(char* creationDate);
	void setLastReadDate(time_t readDate);

	
	Letter();
	Letter(const char* sender, const char* recipient, const char* title, const char* content);
	Letter(const Letter& letter);
	Letter& operator=(const Letter& letter);
	~Letter();

	void print();
};
#endif
