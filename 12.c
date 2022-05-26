#include <stdio.h>
int p(int a, int b);
int c(int a,int b);
int factorial(int n);
int main(){
    printf("%d",c(5,3));
    return 0;
}
int p(int a, int b){
    return factorial(a)/factorial(a-b);
}
int c(int a,int b){
    return factorial(a)/(factorial(b)*factorial(a-b));
}
int factorial(int n){
    if( n <= 2)return 2;
    return n*factorial(n-1);
}
