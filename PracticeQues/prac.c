#include <stdio.h>
 #include<stdio.h>
 #define ROWl 3
 #define COLl 4
 #define ROW2 4
 #define COL2 2
int main(){

    // int size=10;
    // int num[15]={1,2,3,4,5,6,7,8,10};
    // printf("%d",num[12]);

    // int max[][3]={
    //     {1,2},
    //     {2,4,5}
    // };
    // printf("%d",max[0][2]);

    // int arr1[ROWl][COLl]={{1,2,3,4},{4,5,6,4},{4,8,7,9}};
    // int arr2[ROW2][COL2]={1,2,3,4,5,6,7,8};
    // int arr3[COLl][ROW2]={0};
    // int sum=0;
    // for(int i=0;i<ROWl;i++){
    //     sum=0;
    //     for(int j=0;j<COL2;j++){
    //         for (int k = 0; k < COLl; k++)
    //         {
                
    //             arr3[i][j]+=arr1[i][k]*arr2[k][i];
    //         }
            

    //     }
        

    // }

    // for(int i=0;i<COLl;i++){
    //     for (int j = 0; j < ROW2; j++)
    //     {
    //         printf("%d ",arr3[i][j]);
    //     }
    //     printf("\n");
        
    // }

    // int *x,n=10;
    // x=&n;
    // printf("%u",sizeof(x));


    // char a[20];
    // scanf("%s ",a);
    // printf("%s",a);

    // int a=5,b=2;
    // scanf("%2d %3d",&a,&b);
    // a=a&b;
    // printf("%d",a);

    unsigned int a=5;
    unsigned int b=~a;
    printf("%i",b);

}