#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int validIpAddress(char *s)
{
	int i;
	int dotcount=0;
	for(i=0; s[i]!='\0';i++)
	{
		if(s[i]=='.')
		{
			if(i !=0 && i!=strlen(s)-1 && s[i-1] !='.' && s[i+1] != '.')
			{
				if(dotcount>3)
				return 0;
				dotcount++;
			}
			else
			return 0;
				
			
		}
		else if(s[i]>='0' && s[i]<='9')
		{
			if(s[i]=='0' && (s[i+1]>='0' && s[i+1]<='9') )
			return 0;
			int num=0;
			while(s[i] !='.' || i<strlen(s))
			{
				if(s[i]>='0' && s[i]<='9'){
						num=num*10 +(s[i]-'0');
						
					
				}
				else
				{
					return 0;
				}
				i++;
				
			 
				
			}
			if(num<0 || num>255)
			return 0;
		}
		else
		{
			return 0;
		}
		i--;
	}
	if(dotcount != 3)
	return 0;
	return 1;
}

int main()
{
	char s[100];
	scanf("%s",s);
	
	int valid=validIpAddress(s);
	if(valid)
	printf("Valid\n");
	else
	printf("InValid\n");
	
	
	
	
}
