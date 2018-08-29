#include <stdio.h>
#include <algorithm>

int main(){
    int TC, a[3];
    int cnt = 1;
    scanf("%d", &TC);
    while (TC--){
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        std::sort(a, a + 3);
        printf("Case %d: %d\n", cnt++, a[1]);
    }
    

    
    return 0;
}
