#include <stdio.h>
int testReflexive(int arr[3][3]);
int testTransitive(int arr[3][3]);
int testSymmetric(int arr[3][3]);
int testAntiSymmetric(int arr[3][3]);
int main(){
    int a[5] = {2,4,10};
    int b[3] = {2,8,20};
    // for divides
    int o[3][3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(b[j]%a[i] == 0){
                o[i][j] = 1;
                printf("1\t");
            }else{
                o[i][j] = 0;
                printf("0\t");
            }
        }
        printf("\n");
    }
    if(testReflexive(o) == 1 && testTransitive(o) == 1 && testSymmetric(o)==1){
        printf("It is equivalence\n");
    }else{
         printf("It is not equivalence\n");
    }
    return 0;
}
int testReflexive(int arr[3][3]){
    for(int i = 0;i<3;i++){
        if(arr[i][i] != 1){
            printf("It is not refxexive\n");
            return 0;
        }
    }
    printf("It is refxexive\n");
    return 1;
}
int testTransitive(int arr[3][3]){
    int square[3][3];
    for(int i=0;i<3;i++) {    
        for(int j=0;j<3;j++){    
            square[i][j]=0;    
            for(int k=0;k<3;k++){    
                square[i][j]+=arr[i][k]*arr[k][j];    
            }    
        }    
    } 
    for(int i=0;i<3;i++){    
        for(int j=0;j<3;j++){
            if(square[i][j] == 0){
                printf("It is not transitive\n");
                return 0;
            }
        }    
        printf("\n");    
    }
    printf("It is transitive\n");
}
int testSymmetric(int arr[3][3]){
   for(int i = 0;i< 3;i++){
       for(int j = 0;j< 3;j++){
           if(arr[i][j] != arr[j][i]){
            printf("It is not symmetric\n");
               return 0;
           }
       }
   }
   printf("It is symmetric\n");
   return 1;
}
int testAntiSymmetric(int arr[3][3]){
    for(int i = 0;i< 3;i++){
       for(int j = 0;j< 3;j++){
           if(arr[i][j] == arr[j][i]){
               if(i != j){
                    printf("It is not Antisymmetric\n");
                    return 0;
               }
           }
       }
   }
   printf("It is Antisymmetric\n");
   return 1;
}
