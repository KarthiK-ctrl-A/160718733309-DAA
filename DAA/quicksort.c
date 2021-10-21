#include<stdio.h>
#include<time.h>
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

void quick(int a[],int low, int high)
{
    int i,j,k,key;
    if(low>=high)
    {
        return;
    }
    key = low;
    i = low+1;
    j = high;
    while(i<=j)
    {
        while(a[i]<=a[key])
            i++;
        while(a[j]>a[key])
            j--;
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[j],a[key]);
    quick(a,low,j-1);
    quick(a,j+1,high);
}

void main()
{
    clock_t st,et;
    int n,a[1000],k;
    double ts;
    clrscr();
    printf("Enter how many members \n");
    scanf("%d",&n);
    printf("\n The Random numbers are");
    for(k=1;k<=n;k++)
    {
        a[k] = rand();
        printf("%d \t",a[k]);
    }
    st = clock();
    quick(a,1,n);
    et = clock();
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    printf("\n The sorted numbers are: \n");
    for(k=1;k<=n;k++) //C:\msys64\mingw64\bin
    {
        printf("%d \t",a[k]);
    }
    printf("\n The time taken is %e",ts);
}