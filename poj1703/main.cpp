#include <iostream>
#include <cstring>

#define MAX_N 1005000
int root[MAX_N];
int relation[MAX_N];
int total_crimal;
int M_lines;
int find_root(int x){
    if(root[x] == x) return x;
    int t = root[x];
    root[x]  = find_root(root[x]);
    relation[x] = (relation[x] + relation[t]) % 2;
    return root[x];
}
void union_crimal(int a, int b){
    int rootA = find_root(a);
    int rootB = find_root(b);
    root[rootB] = rootA;
    relation[rootB] = ((relation[a] + relation[b])  + 1)  % 2;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        getchar();
        scanf("%d%d", &total_crimal, &M_lines);
        memset(root, 0, MAX_N * sizeof(int));
        memset(relation, 0, MAX_N * sizeof(int));
        for(int i = 0; i <= total_crimal; i++){
            root[i] = i;
        }
        char catagory;
        int crimal_id1=0, crimal_id2=0;
        for(int i = 0; i < M_lines; i++){
            getchar();
            scanf("%c %d%d",  &catagory, &crimal_id1, &crimal_id2);
            if(catagory == 'A'){
                if(find_root(crimal_id1) != find_root(crimal_id2)){
                    printf("Not sure yet.\n");
                } else {
                    if(relation[crimal_id1] != relation[crimal_id2]){

                        printf("In different gangs.\n");
                    } else {
                        printf("In the same gang.\n");
                    }
                }
            } else {
                union_crimal(crimal_id1, crimal_id2);
            }
        }

    }
    return 0;
}
