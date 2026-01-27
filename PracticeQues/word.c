#include<stdio.h>

char* temp(int n) {
    // Mapping digits to their corresponding words
    char* m[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    return m + (n - 1);  // Using pointer arithmetic
}

void convert(int n) {
    // Base case for recursion
    if (n == 0)
        return;

    // Call recursively for the next digit
    char* v = temp(n % 10);
    convert(n / 10);
    printf("%s ", v);  // Print the corresponding word for each digit
}

int main() {
    int x;
    printf("Enter the number: ");
    scanf("%d", &x);

    if (x == 0) {
        printf("zero");  // Special case for zero
    } else {
        convert(x);  // Call the function to convert number to words
    }

    return 0;
}
