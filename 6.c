#include <stdio.h>
void join(int a[3][3], int b[3][3]);
int OR(int a, int b);
int AND(int a, int b);
void printM(int a[3][3]);
int main(){
    int a[3][3] = {
        {1,0,1},
        {0,1,0},
        {1,0,1}
    };
    int b[3][3] = {
        {0,1,0},
        {1,0,1},
        {1,1,1}
    };
    
    join(a,b);
    int a2[3][2] = {
        {1,0},
        {0,1},
        {1,0}
    };
    int b2[2][3] = {
        {1,1,0},
        {0,1,1}
    };
    product(a2,b2);
    return 0;
}
int OR(int a, int b){
    if(a == 1 || b == 1) return 1;
    return 0;
}
int AND(int a, int b){
    if(a == 1 && b == 1) return 1;
    return 0;
}
void printM(int a[3][3]){
    for(int i = 0;i< 3;i++){
        for(int j = 0;j<3;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void join(int a[3][3],int b[3][3]){
    int o[3][3];
    for(int i = 0;i< 3;i++){
        for(int j = 0;j<3;j++){
            o[i][j] = OR(a[i][j],b[i][j]);
        }
        printf("\n");
    }
    printM(o);
}
void product(int a[3][2],int b[2][3]){
    int o[3][3];
    for(int i = 0;i< 3;i++){
        for(int j = 0;j<3;j++){
            int temp = -1;
            for(int k = 0;k<2;k++){
                int temp2 = AND(a[i][k],b[k][j]);
                if(temp == -1){
                    temp = temp2;
                }else{
                    temp = OR(temp,temp2);
                }
            }
            o[i][j] = temp;
        }
        printf("\n");
    }
    printM(o);
}
