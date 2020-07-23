/************************************************************
******************** @Author PRANAV YADAV *******************
************************ PID : 192124 **********************
*********" Implementation of Modular Programming using*******
********************- Arrays and Pointers "*****************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int fact(int );
int swap(int*, int* );
void factadd(void);
void demo2d(void);
void swapping(void);

int main()
{
    int ch;

    while(1)
    {
        printf("Menu :\n 1. Factorial Add\n 2. 2D-Array Demo\n 3. Swapping\n 4. Exit\n");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            factadd();
            break;

        case 2:
            demo2d();
            break;

        case 3:
            swapping();
            printf("\n\n");
            break;

        case 4:
            exit(0);
        default:
            printf("Invalid Input!!! \n\n");
            break;
        }
    }

    return 0;
}

int fact(int x)
{
    int i, ft=1;
    for(i=x; i > 0; i--)
    {
        ft *= i;
    }
    return ft;
}

int swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

void factadd()
{
    int a[100], i, n, f=0;
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("Enter the array elements :\n");
    for(i=0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i < n; i++)
    {
        f += fact(a[i]);
    }

    printf("\n Factorial Addition : %d \n\n",f);

}

void demo2d()
{
    int a[100][100], i, j, m, n, sum=0;
    printf("Enter size for 2D Matrix : \n");
    scanf("%d %d",&m,&n);
    printf("Enter Matrix elements :\n");

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            sum += a[i][j];
        }
    }

    printf("\n Sum of all elements of 2D Matrix is : %d \n\n",sum);

}

void swapping()
{
    int a[100], n, i, j;
    printf("Enter size of the Array : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");

    for(i=0; i < n; i++)
    {
        scanf("%d",&a[i]);

    }
    for(i=0,j=(n-1); (i < n/2)&&(j >= 0); i++,j--)
    {
        swap(&a[i],&a[j]);
    }

    printf("The Swapped Array is : \n");

    for(i=0; i < n; i++)
    {
        printf("%d \t",a[i]);

    }

}
