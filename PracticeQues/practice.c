#include <stdio.h>
#include <string.h>
// int main(){
    // int r, a[4][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    // r=++a[0][2]+ ++a[0][2]*a[2][0]++ %a[2][0]++ * ++a[3][3] %a[2][0];
    // printf("%d \n",r);
    

    // int n,max=1,num,count=0;
    // scanf("%d",&n);
    // for(int i=1;i<=n;i++){
    //     count=0;
    //     for(int j=1;j<=i;j++){
    //         if(i%j==0){
    //             count++;
    //         }
    //     }

    //     if(count>max){
    //         max=count;
    //         num=i;
    //     }
    // }

    // printf("The integer with the highest number of divisors between 1 and %d is %d with %d divisors.\n", n, num, max);

 
    
    // #include <stdio.h>

// Function to convert an integer to Roman numerals
void intToRoman(int num) {
    // Arrays containing Roman numeral symbols and their corresponding integer values
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    printf("Roman numeral: ");

    // Iterate through the values and symbols arrays
    for (int i = 0; i < 13; i++) {
        // While the current number is greater than or equal to the current value
        while (num >= values[i]) {
            // Print the corresponding Roman symbol
            printf("%s", symbols[i]);
            // Subtract the value from the number
            num -= values[i];
        }
    }
    printf("\n");
}

int main() {
    // int number;

    // printf("Enter an integer (1-3999): ");
    // scanf("%d", &number);

    // // Validate the input number
    // if (number < 1 || number > 3999) {
    //     printf("Invalid input. Please enter a number between 1 and 3999.\n");
    // } else {
    //     intToRoman(number);
    // }


    // int i,j,k=0;
    // for(i=0;i<7;i++){
    //     for(j=0;j<i;j++){
    //         if(i+j==3)
    //         continue;
    //         k=k+i+j;
    //     }
    //     printf("%d\n",k);
    // }
    // // printf("%d",k);

    // int a=5,b=10,x;
    // if((a<++a || b<++b && b<a++)?x=a|b:b){
    //     printf("%d %d %d",a,b,x);
    // }
    // else printf("John");
    return 0;
}
