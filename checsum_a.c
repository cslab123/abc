#include<stdio.h>
#include<string.h>
int main()
{
char a[20],b[20],complement[20],sum[20],carry;
int l,i=0;
printf("Enter the first string\n");
scanf("%s",a);
printf("Enter the second string\n");
scanf("%s",b);
if(strlen(a)==strlen(b))
{
l=strlen(a);
carry='0';
for(i=l-1;i>=0;i--)
{
if(a[i]=='0' && b[i]=='0' && carry=='0')
{
sum[i]='0';
carry='0';
}
else if(a[i]=='0' && b[i]=='0' && carry=='1')
{
sum[i]='1';
carry='0';
}
else if(a[i]=='0' && b[i]=='1' && carry=='0')
{
sum[i]='1';
carry='0';
}
else if(a[i]=='0' && b[i]=='1' && carry=='1')
{
sum[i]='0';
carry='1';
}
else if(a[i]=='1' && b[i]=='0' && carry=='0')
{
sum[i]='1';
carry='0';
}
else if(a[i]=='1' && b[i]=='0' && carry=='1')
{
sum[i]='0';
carry='1';
}
else if(a[i]=='1' && b[i]=='1' && carry=='0')
{
sum[i]='0';
carry='1';
}
else if(a[i]=='1' && b[i]=='1' && carry=='1')
{
sum[i]='1';
carry='1';
}
else
break;
}
sum[l]='\0';
//if(carry!='0'){
for(i=l-1;i>=0;i--){
if(sum[i]=='0' && carry=='1')
{
sum[i]='1';
carry='0';
}
else if(sum[i]=='1' && carry=='1')
{
sum[i]='0';
carry='1';
}
}
//}
printf("Sum=%s\n",sum);
for(i=0;sum[i]!='\0';i++)
{
if(sum[i]=='0')
complement[i]='1';
else
complement[i]='0';
}
         if(carry=='1')
carry='0';
else if(carry=='0')
carry='1';
complement[l]='\0';
printf("Checksum=%s\n",complement);
}
else{
printf("Wrong input string\n");
}
return 0;
}
