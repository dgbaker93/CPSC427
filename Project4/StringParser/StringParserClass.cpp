
#include <string>
#include "..\Include\StringParserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

StringParserClass::StringParserClass() : pStartTag(NULL), pEndTag(NULL), areTagsSet(false), lastError(ERROR_NO_ERROR) {}
StringParserClass::~StringParserClass() {}

/*
	Function returns the value of lastError

	Input:
		None
	Output:
		int with a value of the error
*/
int StringParserClass::getLastError() {
	int temp = this -> lastError;
	this -> lastError = ERROR_NO_ERROR;
	return temp;
}

/*
	Sets the tag, flags an error if the 2nd index of pEndTag is not /

	Input:
		2 Const char pointers holding the tags

	Output:
		Success boolean
*/
bool StringParserClass::setTags(const char *pStartTag, const char *pEndTag) {
	if (pStartTag != NULL && pEndTag != NULL) { // maybe add a condition that checks for the '\0' char
		this -> pStartTag = (char *)pStartTag;
		this -> pEndTag = (char *)pEndTag;
		this -> areTagsSet = true;
	} else {
		this -> lastError = ERROR_TAGS_NULL;
		this -> areTagsSet = false;
	}
	
	return this -> areTagsSet;
}

/*
	

	Input:
		One C string, and one storage vector

	Output:
		Success bool
*/
bool StringParserClass::getDataBetweenTags(char *pDataToSearchThru, vector<string> &myvector) {
	int lengthOfStartTag = strlen(pStartTag)/sizeof(char);
	int lengthOfEndTag = strlen(pEndTag)/sizeof(char);
	int lengthOfData = strlen(pDataToSearchThru)/sizeof(char);

	bool startFound = false;
	string stringToAdd = "";

	for (int i = 0; i < lengthOfData; i++)
	{
		if (startFound)
		{
			if (pEndTag[0] == *(pDataToSearchThru + i) && (memcmp(pEndTag,(pDataToSearchThru + i),lengthOfEndTag) == 0))
			{
				myvector.push_back(stringToAdd);
				stringToAdd = "";
				i += lengthOfEndTag -1;
				startFound = false;
			}
			else 
			{
				stringToAdd += *(pDataToSearchThru + i);
			}
		}
		else if (pStartTag[0] == *(pDataToSearchThru + i) && (memcmp(pStartTag,(pDataToSearchThru + i),lengthOfStartTag) == 0))
		{
			i += lengthOfStartTag -1;
			startFound = true;
		}
	}

	return myvector.empty();
}

/*
	sets values to their default constuctor value(s)
*/
void StringParserClass::cleanup() {
	this -> pStartTag = NULL;
	this -> pEndTag = NULL;
	this -> lastError = ERROR_NO_ERROR;
	this -> areTagsSet = false;
}
/*
	Unused
*/
bool StringParserClass::findTag(char *tagToLookFor, char *&start, char *&end) {
	return false;
}
