#ifndef __Post
#define __Post

#include "letter.h"
class Post
{
	char* sender;
	void free();
	void copy(const Post& other);

public:
	Post& sendLetterTo();
	Post(const char* senderName);
	Post(const Post& other);
	~Post();
	void readLetter(ifstream& file);
	Post& operator=(const Post& other);
};

#endif
