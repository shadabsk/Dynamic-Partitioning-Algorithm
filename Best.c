/**
 * Title		:	Dynamic partitioning placement algorithm (Best fit) 
 * Author		:	Shadab Shaikh
 * Date			:	08-04-2018
 * Version		:	1.0
 * Availability	:	https://github.com/shadabsk
 */
#include<stdio.h>

int temp[100]={};

int findApplicable(int totalblk,int blksize[],int totalblkele,int blkelement[],int blkno[],int j)	//function of finding eligible fits
{
	int i;
	for(i=0;i<totalblk;i++)
	{
		if(blksize[i]>=blkelement[j])
		{
			temp[i]=blksize[i];
		}	
	}	
	for(i=0;i<totalblk;i++)
	{
		if(temp[i]==0||temp[i]!=blksize[i])
			temp[i]=-1;
	}
	return temp[i];
}

int findSmallest(int temp[],int totalblk)		//applying bubble sort to find the smallest
{
	int i,j=0;
	for(i=0;i<totalblk;i++)
	{
		for(j=i+1;j<totalblk;j++)
		{
			if(temp[i]>temp[j])
			{
				temp[50]=temp[i];
				temp[i]=temp[j];
				temp[j]=temp[50];
			}
		}
		
		temp[50]=temp[i];
		if(temp[50]!=-1)
			break;
	}
	return temp[50];
	
}

void bestFit(int temp[],int totalblk,int blksize[],int totalblkele,int blkelement[],int blkno[],int i,int j)	//placing the fit and recursively calling until last is reached
{
	for(i=0;i<totalblk;i++)
	{
		if(temp[50]==blksize[i]&&blksize[i]!=-1)
		{
			printf("\n%d\t\t%d\t\t\t%d",blkno[i],blkelement[j],blksize[i]);
			blksize[i]=-1;
		}
	}
	
	for(i=0;i<totalblk;i++)
	{
		temp[i]=0;
	}
	temp[50]=0;
	j+=1;
	
	if(j<totalblkele)
	{
		temp[totalblk]=findApplicable(totalblk,blksize,totalblkele,blkelement,blkno,j);
		findSmallest(temp,totalblk);
		bestFit(temp,totalblk,blksize,totalblkele,blkelement,blkno,0,j);
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
	temp[totalblk]=findApplicable(totalblk,blksize,totalblkele,blkelement,blkno,0);
	findSmallest(temp,totalblk);
	bestFit(temp,totalblk,blksize,totalblkele,blkelement,blkno,0,0);
		
	return 0;
}
