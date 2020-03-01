#include <iostream>
#define MAXN 250110
using namespace std;
typedef struct ship{
    int id;
    int velocity;
    int pos;
    int prev;
    int next;
    bool operator <= (const struct ship & s){
        return velocity <= s.velocity ;
    }
} ship_t;
ship_t ships[MAXN], ships_aux[MAXN], ships_dup[MAXN];

typedef struct Heap{
    double time;
    double dis;
    int passFrom;
    int passTo;
    bool operator < (const struct Heap &h){
        return (time < h.time) || (time == h.time && dis < h.dis);
    }
} heap_t;

heap_t heap[2*MAXN+3];
int heap_pos;
int ship_num;
int pass_cnt;

void swap(int i, int j){
    heap_t temp = heap[i];
    heap[i]     = heap[j];
    heap[j]     = temp;
}

void swim(int k){
    while(k > 1 && heap[k] < heap[k/2]){
        swap(k, k/2);
        k /= 2;
    }
}

void sink(int k){
    while(2 * k <= heap_pos){
        int j = 2 * k;
        if(j < heap_pos && heap[j+1] < heap[j]) j=j+1;
        if(!(heap[j] < heap[k]))  break;
        swap(k, j);
        k = j;
    }
}
double get_meet_time(int i, int j){
    return (double)(ships[j].pos - ships[i].pos)/(ships[i].velocity - ships[j].velocity);
}

double get_meet_pos(int i, double time){
    return ships[i].pos + time * ships[i].velocity;
}
void insert_heap(heap_t h_data){
    heap[++heap_pos] = h_data;
    swim(heap_pos);
}

void add_new_data_to_heap(int i, int j){
    if(ships[i].velocity <= ships[j].velocity || i < 0 || j >= ship_num){
        return;
    }
    double new_meet_time = get_meet_time(i, j);
    double new_meet_pos  = get_meet_pos(i, new_meet_time);
    heap_t h = {new_meet_time,new_meet_pos,i,j};
    insert_heap(h);
}

void update_ship(heap_t h){
    ship_t &cur = ships[h.passFrom];
    ship_t &nxt = ships[h.passTo];
    int cur_before = cur.prev;
    int nxt_nxt    = nxt.next;
    cur.prev = nxt.id;
    ships[cur.prev].next = cur.id;
    cur.next = nxt_nxt;
    ships[cur.next].prev = cur.id;
    nxt.prev = cur_before;
    ships[cur_before].next = nxt.id;
    nxt.next = cur.id;
    add_new_data_to_heap(nxt.prev, nxt.id);
    add_new_data_to_heap(cur.id, cur.next);
}

heap_t deplete_min(){
    heap_t min = heap[1];
    swap(1, heap_pos--);
    sink(1);
    return min;

}

void record_ship_pass(){
    for(int i = 0; i < ship_num-1; i++){
        add_new_data_to_heap(i, i+1);
    }

    int cnt = 0;
    while(heap_pos>0 && cnt < 10000) {
        heap_t heap_head = deplete_min();
        if(ships[heap_head.passFrom].next != heap_head.passTo || ships[heap_head.passTo].prev != heap_head.passFrom) {
            continue;
        }
        printf("%d %d\n", heap_head.passFrom+1, heap_head.passTo+1);
        update_ship(heap_head);
        cnt++;
    }

}
void merge(int lo, int mid, int high){
    int i = lo, j = mid+1;
    for(int k = lo; k <= high; k++){
        ships_aux[k] = ships_dup[k];
    }
    for(int k = lo; k <= high; k++){
        if(i > mid)                              ships_dup[k] = ships_aux[j++];
        else if (j > high)                       ships_dup[k] = ships_aux[i++];
        else if (ships_aux[i] <= ships_aux[j])   {
            ships_dup[k] = ships_aux[i++];
        }
        else                                     {
            pass_cnt += mid-i  + 1;
            ships_dup[k] = ships_aux[j++];
        }
    }
}

void bottom_up_msort(){
    for(int sz = 1; sz < ship_num; sz = sz + sz){
        for(int low = 0; low < ship_num - sz; low += sz + sz){
            merge(low, low + sz-1, min(low+sz+sz-1, ship_num-1));
        }
    }

}

int main() {
    scanf("%d",&ship_num);
    int pos, vel;
    pass_cnt = 0;
    heap_pos = 0;
    for(int i = 0; i < ship_num; i++){
        getchar();
        scanf("%d%d", &pos, &vel);
        ships[i].id       = i;
        ships[i].id       = i;
        ships[i].pos          = pos;
        ships_dup[i].pos      = pos;
        ships[i].velocity     = vel;
        ships_dup[i].velocity = vel;
        ships[i].prev         = i - 1;
        ships_dup[i].prev     = i - 1;
        ships[i].next         = i + 1;
        ships_dup[i].next     = i + 1;
    }

    bottom_up_msort();
    printf("%d\n", pass_cnt % 1000000);
    record_ship_pass();
    return 0;
}
