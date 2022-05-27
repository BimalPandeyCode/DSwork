// KOI DEBUG GARNA SAKHXAU VANE TYO WHILE LOOP BATA EXIT HUDAINA HAI, SEGMENTATION ERROR VANXA MA CHAI KAM GARDINA YESMA AABA
#include <stdio.h>
struct connect{
    int weight;
    int to;
};
struct node{
    int level;
    struct connect connections[4];
};
int minIndex(int set[10],struct node nodes[6]);
int notMinusOne(int set[10]);
int firstNotMinusOne(int notS[10]);
int main(){
    struct node nodes[6];
    for(int i =0;i< 6;i++){
        int done = 1;
        nodes[i].level = 999;
        for(int j = 0;j< 4;j++){
            // printf("Are you done for the %d node?",i+1);
            // scanf("%d",&done);
            // if(done == 1){
            //     break;
            // }
            printf("Enter weight for %dth %d: ",i+1,j+1);
            scanf("%d",&nodes[i].connections[j].weight);
            printf("Enter to %dth %d: ",i+1,j+1);
            scanf("%d",&nodes[i].connections[j].to);
        }
    }
    
    int s[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int sIndex = 0;
    int notS[10] = {0,1,2,3,4,5,-1,-1,-1,-1};
    nodes[0].level = 0;
    while(notMinusOne(s) <= 6 && notMinusOne(notS) != 0 && firstNotMinusOne(notS) != -1){
        int u = minIndex(notS,nodes);
        printf("%d\n",u);
        s[sIndex] = u;
        sIndex++;
        for(int i =0;i<10;i++){
            if(notS[i] == u){
                notS[i] = -1;
                break;
            }
        }
        
        for(int i =0;i<5;i++){
            if(nodes[u].connections[i].weight != -1 && nodes[nodes[u].connections[i].to].level != -1){
                int compare = nodes[u].level + nodes[u].connections[i].weight;
                if(compare < nodes[nodes[u].connections[i].to].level){
                    nodes[nodes[u].connections[i].to].level = compare;
                }
            }
        }
    }
    for(int i = 0;i<10;i++){
        printf("%d  ",s[i]);
    }
    return 0;
}
int minIndex(int notS[10], struct node nodes[6]){
    int min = notS[firstNotMinusOne(notS)];
    for(int i = 0;i<10;i++){
        if(notS[i] != -1){
            if(nodes[notS[i]].level != -1){
                if(nodes[notS[i]].level < nodes[min].level){
                    min = notS[i];
                }
            }
        }
    }
    return min;
}

int firstNotMinusOne(int notS[10]){
    for(int i = 0;i< 10;i++){
        if(notS[i] != -1){
            return i;
        }
    }
    return -1;
}

int notMinusOne(int set[10]){
    int o = 0;
    for(int i = 0;i< 10;i++){
        if(set[i] != -1){
            o++;
        }
    }
    return o;
}
