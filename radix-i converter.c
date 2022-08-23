#include <stdio.h>

int main(){
    printf("Hello World\nEnter name: ");
    char name[20];
    scanf("%s",name);
    printf("Your name is: %s\nYour age is: ",name);
    int age;
    scanf("%d",age);
    printf("\nYour name is %d",age);
    return 0;
}
