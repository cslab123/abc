#include<stdio.h>
#include<stdlib.h>
struct node
{
int dist[20];
int from[20];
}rt[20];

int main()
{
int costmat[20][20];
int n,i,j,k,ct=0;
printf("Enter number of nodes:");
scanf("%d",&n);
printf("\n");
printf("Enter cost matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&costmat[i][j]);
costmat[i][i]=0;
rt[i].dist[j]=costmat[i][j];
rt[i].from[j]=j;
}
}

do
{
ct=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
for(k=0;k<n;k++)
{
if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
{
rt[i].dist[j]=costmat[i][k]+rt[k].dist[j];
rt[i].from[j]=k;
ct++;
}
}
}
}
}while(ct!=0);
for(i=0;i<n;i++)
{
printf("\n For router %d\n",i+1);
for(j=0;j<n;j++)
{
printf("Node %d via %d distance %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
}
}
printf("\n\n");
return 0;
}
