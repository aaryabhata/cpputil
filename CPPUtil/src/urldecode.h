#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

long readFileIntoString(FILE* fp, char** buf, int length){

	int err;
	err = fseek(fp, 0L, SEEK_END);
	if (err != 0)
	{
		perror("Error when seeking to file");
		return -1;
	}

	long buflen;
	long fileSize = ftell(fp);

	if (fileSize == -1)
		return -1;

	if (length == -1){
		buflen = fileSize+1;
	}
	else{
		buflen = length+1;
	}

	*buf = (char*) malloc((buflen)*sizeof(char));

	if (*buf == NULL)
		return -1;

	rewind(fp);

	long readLen = fread(*buf, sizeof(char), buflen, fp);

	if (ferror(fp)){
		perror("Error while reading into buffer");
		free(buf);
		return -1;
	}

	return readLen;
}

/* Converts a hex character to its integer value */
char from_hex(char ch) {
  return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

/* Converts an integer value to its hex character*/
char to_hex(char code) {
  static char hex[] = "0123456789abcdef";
  return hex[code & 15];
}


/* Returns a url-encoded version of str */
/* IMPORTANT: be sure to free() the returned string after use */
char *url_encode(const char *str) {
  char *pstr = const_cast<char*> (str), *buf = (char*) malloc(strlen(str) * 3 + 1), *pbuf = buf;
  while (*pstr) {
    if (isalnum(*pstr) || *pstr == '-' || *pstr == '_' || *pstr == '.' || *pstr == '~')
      *pbuf++ = *pstr;
    else if (*pstr == ' ')
      *pbuf++ = '+';
    else
      *pbuf++ = '%', *pbuf++ = to_hex(*pstr >> 4), *pbuf++ = to_hex(*pstr & 15);
    pstr++;
  }
  *pbuf = '\0';
  return buf;
}


char* getReplaceString(const char* mobileReplaceTemplate, const char* fromToAddressString){

	long len = snprintf(NULL, 0, mobileReplaceTemplate, fromToAddressString );

	char* replaceBuf = (char*)malloc((len+1)*sizeof(char));
	snprintf(replaceBuf, 2000, mobileReplaceTemplate, fromToAddressString);

	return replaceBuf;
}

char *url_decode(const char *str) {
  char *pstr = const_cast<char*> (str);
  char *buf = (char*)malloc(strlen(str) + 1), *pbuf = buf;

  while (*pstr) {
    if (*pstr == '%') {
      if (pstr[1] && pstr[2]) {
        *pbuf++ = from_hex(pstr[1]) << 4 | from_hex(pstr[2]);
        pstr += 2;
      }
    } else if (*pstr == '+') {
      *pbuf++ = ' ';
    } else {
      *pbuf++ = *pstr;
    }
    pstr++;
  }
  *pbuf = '\0';
  return buf;
}

char* getNthBracketString(int n, const char* str){

	char* ret = NULL;
	int index = 1;
	char* pch1 = strchr(const_cast<char*> (str),'[');
	char* pch2 = NULL;

	while (pch1!=NULL && index < n)
	{
		pch1=strchr(pch1 +1,'[');
		index++;
	}

	//get the closing bracket
	if (index == n && pch1 != NULL)
	{
		pch2 = strchr(pch1 + 1, ']');
	}

	//create a string with the characters between them
	if (pch2 != NULL && pch1 != NULL)
	{
		ret = (char*) malloc(sizeof(char)* (pch2-pch1));

		strncpy(ret, pch1+1, (pch2-pch1-1));
	}
	return ret;
}
