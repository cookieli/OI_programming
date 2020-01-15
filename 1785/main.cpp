#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#define N 50010
using namespace std;
struct Node {
    char label[100];
    int priority;
    int l_child, r_child;
    int parent;
}T[N];
int n, order[N];
bool cmpNodeByOrder(int i, int j){
    return strcmp(T[i].label, T[j].label) < 0;
}

void insertTree(int index){
    int p = order[index - 1];
    index = order[index];
    int priority = T[index].priority;
    while(T[p].priority < priority){
        p = T[p].parent;
    }
    T[index].l_child = T[p].r_child;
    T[p].r_child = index;
    T[index].parent = p;
}

void dfsPrintf(int index){
    if (index == 0) return;
    putchar('(');
    dfsPrintf(T[index].l_child);
    printf("%s/%d", T[index].label, T[index].priority);
    dfsPrintf(T[index].r_child);
    putchar(')');
}

int main() {
    while(scanf("%d", &n) && n){
        memset(T, 0, N);
        memset(order, 0 , N);
        T[0].priority = INT_MAX;
        T[0].l_child = 0;
        T[0].r_child = 0;
        for(int i = 1; i <= n; i++){
            scanf(" %[a-z]/%d", T[i].label, &T[i].priority);
            T[i].l_child = 0;
            T[i].r_child = 0;
            T[i].parent  = 0;
            order[i] = i;
        }
        sort(order+1, order+n+1, cmpNodeByOrder);
        for(int i = 1; i <= n; i++){
            insertTree(i);
        }
        dfsPrintf(T[0].r_child);
        puts("");
    }
}