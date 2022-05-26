#include <stdio.h>
int add(int a,int b);
int main(){
    add(123,321);
    return 0;
}
int add(int a, int b){
    int b1[20], b2[20];
    int i1 = 19, i2 = 19;
    int output[20];
    int carry = 0, sum = 0;
    while(a != 0 && b != 0){
        //  * 1
        int r1 = a%10;
        a = (int)a/10;
        b1[i1] = r1;
        // * 2
        int r2 = b%10;
        b = (int)b/10;
        b2[i1] = r2;
        sum = carry + r1 + r2;
        if(sum > 9){
            carry = 1;
            sum = sum%10;
        }
        output[i1] = sum;
        i1--;
    }
    output[i1] = carry;
    for(int i = 0;i<20;i++){
        printf("%d ",output[i]);
    }
    return 0;
}
