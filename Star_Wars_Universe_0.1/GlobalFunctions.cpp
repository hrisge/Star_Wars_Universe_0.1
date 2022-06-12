#include "GlobalFunctions.h"

bool isLeftStringBeforeRightAlphabetically(const MyString& left, const MyString& right)
{
	unsigned sizeLeft = left.getStringLen();
	unsigned sizeRight = right.getStringLen();
	unsigned size = std::min(sizeLeft, sizeRight);
	
	for (unsigned i = 0; i < size; ++i)
	{
		if (left[i] < right[i])
			return true;
		else if (left[i] > right[i])
			return false;
	}
	
	if (sizeLeft < sizeRight)
		return true;
	
	return false;
}
bool doesStringContainsOnlyLettersAndSpaces(const MyString& string)
{
	unsigned size = string.getStringLen();
	for (unsigned i = 0; i < size; ++i)
	{
		if((string[i]>='A' && string[i]<='Z')||(string[i]>='a' && string[i]))
	}
}