#include "sortAlgos.h"
#include "listAlgos.h"
#include "urldecode.h"

int main(){
	//listAlgosDriver();

	FILE* fp = fopen("/home/vishnu/vpncert.pem", "r");

	if (fp != NULL)
	{
		char* str = NULL;
		int len = readFileIntoString(fp, &str, -1);

		if (len == -1)
			return 0;

		printf("file contents are %s", str);

		free(str);
		fclose(fp);
	}else{
		printf("error opening the file");
	}

	const char* mobileReplaceTemplate = "s_jr=%%5Bnull%%2C%%5B%%5Bnull%%2Cnull%%2Cnull%%2Cnull%%2Cnull%%2Cnull%%2Cnull%%2C%%5Bnull%%2C%%5Bnull%%2C%%5B%%5B%s%%5D%%5D%%2C%%5B%%5D%%2C%%5B%%5D%%2Cnull%%2C%%5B%%5D%%2Cnull%%2Cnull%%2C1%%2Cnull%%2Cnull%%2Cnull%%2Ctrue%%2Cnull%%5D%%5D%%5D%%5D%%2C2%%2Cnull%%2Cnull%%2Cnull%%2Cnull%%5D%%22%%3B%%0A%%0A";


	const char* fromToString = getNthBracketString(7, "s_jr=[null,[[null,null,null,null,null,null,null,null,null,[null,[null,[[null,\"rsadlpqe@gmail.com\",\"Rsadlpqe@gmail.com\"]],[],[],null,[],\"\",\"Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br><br>Ssn 111-22-3333<br>111-22-3333<br>111-22-3333<br>\",1,null,\"fm133\",null,true,null]]],[null,null,null,null,null,null,[null,true]],[null,[null,\"l:^i\",0,null,80,5,null,true,false,[]]]],2,null,null,null,\"ea131693fa\"]");

	cout<<url_encode(fromToString);

	cout<<"Replace string is"<<getReplaceString(mobileReplaceTemplate, url_encode(fromToString));
	return 0;
}
