#include <stdio.h>
int ceiling(float a);
int floorCalc(float num);
int main() {
    printf("%d",floorCalc(5.02));
    return 0;
}
int ceiling(float num){
    return (int) num + 1;
}
int floorCalc(float num){
    return (int) num;
}
