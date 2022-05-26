#include <stdio.h>
int includes(char a, char b[5]);
void printEle(char arr[5]);
void unionCalc(char a[5], char b[5]);
void intersectionCalc(char a[5],char b[5]);
void difference(char a[5],char b[5]);
void cartesianProduct(char a[5],char b[5]);
struct ele{
    char first,second;
};
int main() {
    char a[5] = {'a','b','c','d'};
    char b[5] = {'c','d','e','f'};
    unionCalc(a,b);
    return 0;
}

int includes(char a, char b[5]){
    for(int i = 0;i<5;i++){
        if(b[i] == a){
            return 1;
        }
    }
    return 0;
}

void printEle(char arr[5]){
    for(int i = 0;i< 5 ;i++){
        printf("%c\n",arr[i]);
    }
}
void printCartesian(struct ele arr[16]){
    for(int i = 0;i< 16 ;i++){
        printf("%c,%c\n",arr[i].first,arr[i].second);
    }
}

void unionCalc(char a[4], char b[4]){
    int index = 3;
    for(int i = 0;i< 4;i++){
        if(includes(a[i],b) == 0){
            b[index] = a[i];
            index++;
        }
    }
    printEle(b);
}
void intersectionCalc(char a[5],char b[5]){
    char o[5];
    int index = 0;
    for(int i = 0;i< 5;i++){
        if(includes(a[i],b) == 1){
            o[index] = a[i];
            index++;
        }
    }
    printEle(o);
}
void difference(char a[5],char b[5]){
    char o[5];
    int index = 0;
    for(int i = 0;i<5;i++){
        if(includes(a[i],b) == 0){
            o[index] = a[i];
            index++;
        }
    }
    printEle(o);
}
void cartesianProduct(char a[4],char b[4]){
    struct ele o[25];
    int index = 0;
    for(int i = 0;i< 4;i++){
        for(int j = 0;j< 4;j++){
            struct ele one;
            one.first = a[i];
            one.second = b[j];
            o[index] = one;
            index++;
        }
    }
    printCartesian(o);
}
