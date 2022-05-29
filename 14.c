#include <stdio.h>
void dijkstra(int nodes[6][6],int start);
int minLevel(int nodes[6][6], int arr[6]);
int length(int arr[6]);
void printArray(int arr[6]);
int firstNonNegativeElement(int arr[6]);
// Yo comment chai 69 ooe line banauna matra ho hai. 
int main() {
    //  if element has same index as row and colum it is it's level
    int nodes[6][6] = {
        {9999,3,0,2,0,0},
        {3,9999,6,2,1,0},
        {0,6,9999,0,0,1},
        {2,2,0,9999,3,0},
        {0,1,0,3,9999,4},
        {0,0,1,0,4,9999},
    };
    dijkstra(nodes,0);
    return 0;
}
void dijkstra(int nodes[6][6],int start){
    nodes[start][start] = 0;
    int s[6] = {};
    int sIndex = 0;
    int notS[6] = {0,1,2,3,4,5};
    while(length(notS) != 0 && minLevel(nodes,notS) != -1){
        int u = minLevel(nodes,notS);
        s[sIndex] = u;
        notS[u] = -1;
        // Calculate v
        int v[6];
        int vIndex = 0;
        for(int i = 0;i< 6;i++){
            if(i==u) v[vIndex] = -1;
            if(nodes[u][i] != 0) v[vIndex] = i; else v[vIndex] = -1;
            vIndex++;
        }
        for(int i = 0;i< 6;i++){
            if(v[i] == -1) continue;
            int compare = nodes[u][u] + nodes[u][v[i]];
            if(compare < nodes[v[i]][v[i]]){ 
                nodes[v[i]][v[i]] = compare;
            }
        }
        sIndex++;
    }
    // Thorai code change garera harek path dekhauna nih milxa tara malai nindra lagi sakyo ma chai sute. ani MST wala nih gara hai. ko ko herxau, hereu ani yo msg padeu vane malai msg gara hai. Voli sir lai 3 no ra 9 no aayena, bujaidinu wa gardinu vana hai.
    printArray(s);
}
int length(int arr[6]){
    int len = 0;
    for(int i = 0;i< 6;i++) if(arr[i] != -1) len++;
    return len;
}
int minLevel(int nodes[6][6],int notS[6]){
    int min = firstNonNegativeElement(notS);
    for(int i = 1;i< 6;i++){
        if(notS[i] != -1) if(nodes[notS[i]][notS[i]] < nodes[min][min]) min = i;
    }
    if(min == 0) if(notS[min] == -1) return -1;
    return min;
}
void printArray(int arr[6]){
    for(int i = 0;i< 6;i++) printf("%d\t",arr[i]);
    printf("\n");
}
int firstNonNegativeElement(int arr[6]){
    for(int i = 0;i< 6;i++) if(arr[i] != -1) return i;
}
