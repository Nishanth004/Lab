#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int lsrec(int a[], int key, int low, int high)
{
        if(a[low]==key)
                return low;
        return lsrec( a,key,low+1, high);

}

int lsiter(int a[], int key, int low, int high)
{
	clock_t st,end;
        st=clock();
        for(int i=0;i<high;i++)
                if(a[i]==key)
                {
                        end=clock();
                        printf("\ntime=%lf\n",(double)(end-st)/CLOCKS_PER_SEC);
                        return i;
                }
        end=clock();
        printf("\ntime=%lf\n",(double)(end-st)/CLOCKS_PER_SEC);
        return -1;
}

int bsrec(int a[], int key, int low, int high)
{
	clock_t st,end;
           st=clock();
	while(low<=high)
	{
		int mid=(low+(high-low))/2;
		if(a[mid]==key)
			return mid;
		if(a[mid]<key)
			return bsrec(a,key,mid+1,high);
		return bsrec(a,key,low,mid-1);
	}
	return -1;
}

int bsiter(int a[], int key, int low, int high)
{
	clock_t st,end;
    st=clock();
	while(low<=high)
	{
		int mid=(low+(high-low))/2;
		if(a[mid]==key)
		{
			end=clock();
            printf("\ntime=%lf\n",(double)(end-st)/CLOCKS_PER_SEC);
			return mid;
		}
		if(a[mid]<key)
			low=mid+1;
		else high=mid-1;
	}
	end=clock();
    printf("\ntime=%lf\n",(double)(end-st)/CLOCKS_PER_SEC);

	return -1;
}



int main()
{
	int b[100], a[100], l=0,key, u=100, num;
	clock_t st, end;

	printf("\nUnsorted array=\n");
	for(int i=0;i<u;i++)
	{
		a[i]=rand()%(u-l+1)+l;
		printf("|%d",a[i]);
	}

	printf("\nSorted array=\n");
	for(int i=0;i<u;i++)
	{
		b[i]=i+1;
		printf("|%d",b[i]);
	}
		
	int ch;
	printf("\nEnter the element to search\n");
	scanf("%d",&key);

	while(1)
	{
		printf(" \n 1 .LSEARCH RECURSIVE \n 2.LSEARCH ITERATRIVE \n 3.BSEARCH RECURSIVE \n 4.BSEARCH ITERATIVE \n 5.EXIT \n ENTER YOUR CHOICE \n ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: st=clock();
				    printf("\nindex=%d\n",lsrec(a,key,0,u));
			        end=clock();
				    printf("\ntime=%lf\n",(double)(end-st)/CLOCKS_PER_SEC);
			        break;
			case 2: printf("\nindex=%d\n",lsiter(a,key,0,u));
                    break;
			case 3: st=clock();
			        printf("\nindex=%d\n",bsrec(b,key,0,u));
                    end=clock();
                    printf("\ntime=%lf\n",(double)(end-st)/CLOCKS_PER_SEC);
			        break;
			case 4: printf("\nindex=%d\n",bsiter(b,key,0,u));
                    break;
			case 5: exit(0);
			default:printf("\nInvalid choice\n");
		}
    }   
}

