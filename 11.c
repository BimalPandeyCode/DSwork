#include <stdio.h>
int power(int num, int raiseTo);
int linearSearch(int arr[10], int key);
int main(){
    printf("%d",power(5,3));
    return 0;
}
int power(int num, int raiseTo){
    if(raiseTo <= 1){
        return num;
    }
    return num * power(num, --raiseTo);
}

int linearSearch(int arr[10], int key){
    for(int i = 0;i<10;i++){
        if(key == arr[i]) return i;
    }
    return -1;
}
