#include <stdio.h>
int OR(int a,int b);
int AND(int a,int b);
int NOT(int a);
int Bijunction(int a,int b);
int OR(int a,int b){
    if(a == 1 || b == 1) return 1;
    return 0;
}
int AND(int a,int b){
    if(a == 1 && b == 1) return 1;
    return 0;
}
int NOT(int a){
    if(a == 0) return 1;
    return 0;
}
int Bijunction(int a,int b){
    if( a== b) return 1;
    return 0;
}
int main(){
    // for and
     printf("AND\n");
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            printf("%d AND %d = %d\n",i,j,AND(i,j));
        }
    }
     // for or
     printf("\nOR\n");
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            printf("%d AND %d = %d\n",i,j,OR(i,j));
        }
    }
    // for not
     printf("\nNOT\n");
    for(int i = 0;i<2;i++){
            printf("%d NOT = %d\n",i,NOT(i));
    }
    // for or
     printf("\nBijunction\n");
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            printf("%d <-> %d = %d\n",i,j,Bijunction(i,j));
        }
    }
    return 0;
}
