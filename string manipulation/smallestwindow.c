#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void FindSmallestWindow(char *s1,char *s2)
{
   
   
   
    int len;
    int minlen=200;
    int minsubstart=-1,minsubend=-1;
   
   
    // // for(int j=0; j<strlen(s1);j++)
    // //     {
           
    //          int hash[255]={0};
    //          for(int w=0;w<strlen(s2);w++)
    //          {
    //             hash[s2[w]]++;
    //          }
    //          for(int i=0;s2[i] !='\0';i++)
    //          {
    //              if(hash[s2[i]] > 0)
    //              printf("%c",s2[i]);
    //              hash[s2[i]]--;
                 
    //          }
    //     // }
    for(int i=0; i<strlen(s1) ; i++)
    {
       
       
        for(int j=i; j<strlen(s1);j++)
        {
           
             int hash[255]={0};
             for(int w=0;w<strlen(s2);w++)
             {
                hash[s2[w]]++;
             }
            //  for(int i=0;s2[i] !='\0';i++)
            //  {
            //      if(hash[s2[i]] > 0)
            //      printf("%c",s2[i]);
            //  }
           
   
            int start=i;
            int end=j;
            while(start<=end)
            {
                if(hash[s1[start]] > 0)
                 hash[s1[start]]--;
                 
                 start++;
            }
            int flag=1;
             for(int t=0;s2[t]!='\0';t++)
             {
                 if(hash[s2[t]] >0)
                 {
                     flag=0;
                 }
                 
             }
             if(flag)
             {
                 len=j+1-i;
                 if(len<minlen)
                 {
                     minlen=len;
                     minsubstart=i;
                     minsubend=j;
                     
                 }
               
                 
                 
             }
             
             
           
           
        }
       
    }
    // printf("len : %d  minsubstart : %d minsubend : %d\n",minlen,minsubstart,minsubend);
   
    if(minsubstart !=-1 && minsubend !=-1)
    for(int i= minsubstart;i<=minsubend;i++)
    {
        printf("%c",s1[i]);
    }
    // else
    // printf("Not Working\n");
   
   
}
int main()
{
    char str[100];
    char pat[100];
   
    scanf("%[^\n]",str);
    scanf(" %s",pat);
   
    // printf("%s\n",str);
    // printf("%s",pat);
   
    FindSmallestWindow(str,pat);
   
   
    return 0;
}
