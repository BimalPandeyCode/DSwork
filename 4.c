#include <stdio.h>
int gcd(int a,int b);
int main(){
    int s1 = 1, s2 = 0;
    int t1= 0, t2 = 1;
    printf("gcd%d",egcd(161,28,s1,s2,t1,t2));
    return 0;
}
int gcd(int a, int b){
    int temp = 0;
    if(a < b){
        temp = a;
        a=b;
        b=temp;
    }
    int r = a%b;
    if(r==0) return b;
    return gcd(r,b);
}

int egcd(int a, int b,int s1,int s2, int t1,int t2 ){
    int temp = 0;
    if(a < b){
        temp = a;
        a=b;
        b=temp;
    }
    int r = a%b;
    int q = (a-r)/b;
    int s = s1 - s2*q;
    int t = t1 - t2*q;
    if(r==0){
        printf("s=%d\tt=%d\n",s2,t2);
        return b;
    }
    return egcd(b,r,s2,s,t2,t);
}
