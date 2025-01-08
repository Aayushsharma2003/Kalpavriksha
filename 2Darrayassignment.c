 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  
 
 int row,col;
 printf("Enter number of rows:");
 scanf("%d",&row);
 printf("Enter number of columns:");
 scanf("%d",&col);
 printf("Enter the names:\n");
 
 char** names=(char*)malloc((row*col)*sizeof(char));
 for(int i=0;i<(row*col);i++)
 {
     names[i]=(char*)malloc(101*sizeof(char));
 }
 int k=0;
 for(int i=0;i < row;i++)
 {
     
     for(int j=0;j<col;j++)
     {
         
         printf("Name at (%d,%d):",i,j);
         scanf("%s",names[k++]);
         
        
     }

     
 }
 int count=0;
 int maxlen=0,index;
 for(int i=0;i<(row*col);i++)
 {
     char c=names[i][0];
     if(c=='a'|| c=='i'||c=='o'||c=='u'||c=='e'||c=='A'||c=='E'||
     c=='I'||c=='O'||c=='U')count++;
     
     int len=strlen(names[i]);
     if(maxlen<len){
     maxlen=len;
     
     }
 }
 for(int i=0;i<(row*col);i++)
 {
     if(maxlen==strlen(names[i])){
     index=i;
     break;
     }
 }
 printf("The 2D array of names is:\n");
  k=0;
 for(int i=0;i < row;i++)
 {
     for(int j=0;j<col;j++)
     {
      
        printf("%s ",names[k++]);
        
        
     }
     printf("\n");

     
 }
 printf("\nNumber of names starting with a vowel: %d\n",count);
  printf("The longest name: %s \n",names[index],index);
 for(int i=0;i<(row*col);i++)
 {
     free(names[i]);
 }
 free(names);
 

    return 0;
}
