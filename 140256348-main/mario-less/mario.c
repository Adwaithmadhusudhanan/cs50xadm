#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do{

        n = get_int("Height: ");

    }
    while((n<1) || (n<0)  || (n>1 && n>8));

    for (int i = 1;i<=n; i++){
        for (int j = 1;j <=n-i; j++){
            printf(" ");
        }
        //printf("\n");

        for (int k=1;k<=i;k++){
          printf("#");
        }
        printf("\n");
    }
    return 0;
}