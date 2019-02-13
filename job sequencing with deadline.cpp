#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
		   //low is first index i.e 0 and high is last index;
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n,i=1,temp,j,k=0,l;
    int flag=0;
    int profit;
    int *slot;
    slot=(int *)malloc(5*sizeof(int));
    int ch;
    ch='y';
    while (ch=='y') {
    system("cls");
    printf("\t\tJob sequencing with deadline by MDFire 12.02.2019\n\n");
    printf("How many jobs are there? ");
    scanf("%d",&n);
    printf("\n");
    int pro[n],deadline[n],val[n],sol[n];
    int duppro[n];
    k=0;
    temp=n;
    for (i=0;i<n;i++)
    {
        val[i]=i;
        //slot[n]=0;
        sol[i]=0;
    }
    i=0;
    while (temp>0)
    {
        printf("job %d profit and deadline ",i+1);
        scanf("%d %d",&pro[i],&deadline[i]);
        duppro[i]=pro[i];
        i++;
        temp--;
    }

    k=0;
    for (i=0;i<n;i++)
    {
        if (k <=deadline[i]) k=deadline[i];
    }
    slot=(int *)realloc(slot,k);
    for (i=0;i<k;i++)
    {
        slot[i]=0;
    }

    //profit sorting
    quickSort(pro,0,n-1);

    //pro ki value ke index sort hone ke pahle jo the unko sort hone ke baad val me store krna
    for (i=0;i<n;i++)
    {
        for (k=0;k<n;k++)
        {
            if (pro[i]==duppro[k]) val[i]=k;
        }
    }
    profit=0;
    temp = n-1;
    l=0;
    for (i=temp;i>=0;i--)
    {
        j=val[i];
        k=deadline[j];
        //debug//printf("j=%d k=%d ",j,k);
        j=k-1;
        while (j>=0)
        {
            if (flag==1)
            {
                break;
            }
            else if (slot[j]==0)
        {
            slot[j]=1;
            profit=profit+pro[i];
            sol[l]=val[i]+1;
            l++;
            flag=1;
        }
            j--;
        }
        flag=0;
        j=0;

    }

    printf("\nMaximum profit is %d\n",profit);
    printf("\nSolution is: ");
    for(i=0;i<l;i++)
    {
        printf("J%d, ",sol[i]);
    }
    printf("\n\nDo you want to process more data (y,n): ");
    fflush(stdin);
    scanf("%c",&ch);
    }
    free(slot);

    return 0;
}
