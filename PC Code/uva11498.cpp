#include <stdio.h>
#include <cstring>

int main(){
    int K, N, M;
    int X, Y;
    char res[5][7] = {"divisa",
                      "NE",
                      "NO",
                      "SO",
                      "SE"};
    int index;
    
    
    
    while (scanf("%d", &K), K){//while there is still a number with non-zero value

            //scan in the division point
        scanf("%d %d", &N, &M);
        while(K--){
            scanf("%d %d", &X, &Y);
            if (X == N || Y == M) index = 0;
            else{
                int sx = (X > N) ? 1 : 0;
                int sy = (Y > M) ? 1 : 0;
                int score = sx * 10 + sy;
                    // sx: 0, 1  sy: 0,1
                    // NE: 11
                    // NO: 1
                    // SO: 0
                    // SE: 10
//                printf("score : %d\n", score);
                switch (score) {
                    case 11:
                        index = 1;
                        break;
                    case 1:
                        index = 2;
                        break;
                    case 0:
                        index = 3;
                        break;
                    case 10:
                        index = 4;
                };
            }
//            printf("index : %d\n", index);
            printf("%s\n", res[index]);
        }
//        printf("out of inner loop\n");
        
    }
}
