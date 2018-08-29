#include <stdio.h>

int main(){

    int TC;
    long a, b;
    
    scanf("%d", &TC);
        //
    while (TC -- ){
        scanf("%ld %ld", &a, &b);
        char c = (a < b) ? '<' : (a > b) ? '>': '=';
        printf("%c\n", c);
    }

    return 0;
}
