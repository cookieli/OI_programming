#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <queue>
using namespace std;
const int MAXN = 40010;
int road_start[MAXN];
int road_end[MAXN];
int road_length[MAXN];
int road_direction[MAXN];
const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int root[MAXN];
int N, M;
int disX[MAXN];
int disY[MAXN];

int find_root(int pos){
    if(root[pos] == -1)
        return pos;
    int root_pos = find_root(root[pos]);
    disX[pos] += disX[root[pos]];
    disY[pos] += disY[root[pos]];
    return root[pos]= root_pos;
}

void bind(int pos0, int pos1, int length, int direction){
    int root0 = find_root(pos0);
    int root1 = find_root(pos1);
    if(root0 != root1){
        root[root0] = root1;
        disX[root0] =  disX[pos1] - disX[pos0] + length * dx[direction];
        disY[root0] =  disY[pos1] - disY[pos0] + length * dy[direction];
    }
}
int main()
{
    while(scanf("%d%d", &N, &M) == 2) {
        memset(root, -1, sizeof(root));
        memset(disX, 0, sizeof(disX));
        memset(disY, 0, sizeof(disY));
        for (int i = 0; i < M; i++) {
            char str[10];
            scanf("%d%d%d%s", &road_start[i], &road_end[i], &road_length[i], str);
            switch (str[0]) {
                case 'N':
                    road_direction[i] = UP;
                    break;
                case 'S':
                    road_direction[i] = DOWN;
                    break;
                case 'E':
                    road_direction[i] = RIGHT;
                    break;
                case 'W':
                    road_direction[i] = LEFT;
                    break;
            }
        }
        int query_time;
        scanf("%d", &query_time);
        int current_index = 0;
        for (int i = 0; i < query_time; i++) {
            int pos0, pos1, index;
            scanf("%d%d%d", &pos0, &pos1, &index);
            for (int j = current_index; j < index; j++) {
                bind(road_start[j], road_end[j], road_length[j], road_direction[j]);

            }
            int root0 = find_root(pos0);
            int root1 = find_root(pos1);
            if (root0 == root1) {
                int v_x = abs(disX[pos1] - disX[pos0]);
                int v_y = abs(disY[pos1] - disY[pos0]);
                printf("%d\n", v_x + v_y);
            } else {
                printf("%d\n", -1);
            }
            current_index = index;
        }
    }
    return 0;
}
