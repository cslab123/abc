#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char sum[10];
char checksum[10];
void calculate(char a[],char b[])
{
   int i,length;
   char carry='0';
   if(strlen(a) == strlen(b)){
      length=strlen(a);
      for(i=length-1;i>=0;i--){
         if(a[i]=='0' && b[i]=='0'){
            if(carry=='0'){
               sum[i]='0';
               carry='0';
            }
            else
            {
               sum[i]='1';
               carry='0';
            }
         }
         else if((a[i] == '0' && b[i]=='1') || (a[i]=='1'&& b[i]=='0')){
            if(carry=='0'){
               sum[i]='1';
               carry='0';
            }
            else
            {
               sum[i]='0';
               carry='1';
            }
         }
         else if(a[i]=='1' && b[i]=='1'){
            if(carry=='0'){
               sum[i]='0';
               carry='1';
            }
            else
            {
               sum[i]='1';
               carry='1';
            }
         }
      }
   for(int i=0;i<length;i++){
      if(sum[i]=='0')
         checksum[i]='1';
      else
         checksum[i]='0';
   }
   }
   else
   {
      printf("Wrong Input\n");
   }
}
void checks(){
   
}
int main()
{
   char a[10],b[10];
   int i;
   printf("Enter 2 values\n");
   scanf("%s%s",a,b);
   calculate(a,b);
   printf("Sum = %s\n",sum);
   printf("Checksum = %s\n",checksum);
   strcpy(a,sum);
   strcpy(b,checksum);
   calculate(a,b);
   for(i=0;i<strlen(a);i++){
      if(checksum[i]!='0'){
         printf("error\n");
         exit(0);
      }
   }
   printf("Errorless\n");
   return 0;
}
       
   
      
               
