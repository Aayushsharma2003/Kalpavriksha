#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkanagrams(char *str1 , char *str2)
{
	if(strlen(str1) != strlen(str2))
	return 0;
	
	int hash[256]={0};
	
	int i;
	for(i=0;i<strlen(str1);i++)
	{
		hash[str1[i]]++;
		hash[str2[i]]--;
	}
	for(i=0;i<256;i++)
	{
		if(hash[i] !=0)
		return 0;
	}
	return 1;
}

int main()
{
	char str1[1000];
	char str2[1000];
	scanf("%[^\n]%*c",str1);
	scanf("%[^\n]%*c",str2);
	int res=checkanagrams(str1,str2);
	if(res)
	printf("true\n");
	else
	printf("false\n");
	
	return 0;
	
}
