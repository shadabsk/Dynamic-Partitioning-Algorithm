/**
 * Title		:	Dynamic partitioning placement algorithm (First fit) 
 * Author		:	Shadab Shaikh
 * Date			:	17-04-2018
 * Version		:	1.0
 * Availability	:	https://github.com/shadabsk
 */
#include<stdio.h>

void firstFit(int totalblk,int blksize[],int totalblkele,int blkelement[],int blkno[],int i,int j)	//first vacant fits the element and recursively being called
{
	if(blkelement[i]<=blksize[j])
	{
		printf("\n%d\t\t%d\t\t\t%d",blkno[j],blkelement[i],blksize[j]);
		blksize[j]=-1;
		i+=1;
		j+=1;
	}
	else
	{
		j+=1;
	}
	
	if(i<totalblkele&&j<totalblk)
		firstFit(totalblk,blksize,totalblkele,blkelement,blkno,i,j);
	else
	{
		if(blkelement[i]!=0)
		{
			j=0;
			if(i<totalblk)
			{
				firstFit(totalblk,blksize,totalblkele,blkelement,blkno,i,j);
			}
		}
	}
	
	
	
}

int main()
{
	int i,j,totalblk,blksize[10],totalblkele,blkelement[10]={},blkno[10];
	printf("Enter the total number of block\n");
	scanf("%d",&totalblk);
	printf("Enter the block sizes\n");
	for(i=0;i<totalblk;i++)
	{
		blkno[i]=i+1;
		scanf("%d",&blksize[i]);
	}
	printf("Enter the total processes\n");
	scanf("%d",&totalblkele);
	printf("Enter the process elements\n");
	for(j=0;j<totalblkele;j++)
		scanf("%d",&blkelement[j]);
	
	printf("\nblock number\tprocess elements\tblock size");
	firstFit(totalblk,blksize,totalblkele,blkelement,blkno,0,0);
		
	return 0;
}
