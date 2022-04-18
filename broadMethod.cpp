#include "broadMethods.h"

void copyString(char*& str1, const char* str2)
{
	int length = strlen(str2) + 1;
	str1 = new char[length];
	strncpy(str1, str2, length);
}
