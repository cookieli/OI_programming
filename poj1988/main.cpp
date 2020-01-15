#include <iostream>
#include <vector>
#include <cstring>
#define N 30010
using namespace std;
int fatherOfCube[N];
int underCube[N];
int num[N];
int find_root(int cube){
    if(fatherOfCube[cube] == cube) return cube;
    int father = fatherOfCube[cube];
    fatherOfCube[cube] = find_root(father);
    underCube[cube] += underCube[father];
    return fatherOfCube[cube];
}

void union_stack(int cube1, int cube2){
    int root_of_cube1 = find_root(cube1);
    int root_of_cube2 = find_root(cube2);
    fatherOfCube[root_of_cube1] = root_of_cube2;
    underCube[root_of_cube1] += num[root_of_cube2];
    num[root_of_cube2]       += num[root_of_cube1];
}

int main() {
    memset(underCube, 0, N* sizeof(int));
    int n;
    scanf("%d", &n);
    for(int i = 0; i < N; i++){
        fatherOfCube[i] = i;
        num[i] = 1;
    }
    char c;
    for(int i = 1; i <= n ; i++){
        scanf(" %c", &c);
        if(c == 'M'){
            int fst, snd;
            scanf(" %d", &fst);
            scanf(" %d", &snd);
            union_stack(fst, snd);
        } else {
            int t;
            scanf(" %d", &t);
            find_root(t);
            printf("%d\n", underCube[t]);
        }
    }
    return 0;
}