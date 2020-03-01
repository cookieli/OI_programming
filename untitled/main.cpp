#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=250000,tt=1000000;

struct Car
{
    int vel;
    int pos;
    bool operator <= (const Car &a) const {
        return vel<=a.vel;
    }
}; //赛车的结构体
struct Heap
{
    int left,right;
    double ti,dis;
    Heap(){

    }
    Heap(int x, int y, double ti, double dis){
        this->left = x;
        this->right = y;
        this->ti = ti;
        this->dis = dis;
    }
    bool operator < (const Heap &a) const {
        return ti<a.ti||ti==a.ti&&dis<a.dis;
    }
}; //堆的结构体
int ship_num,h_pos,pass_cnt,l[maxn+5],r[maxn+5]; //l[i]表示i的左边，r[i]表示i的右边
Car cars[maxn+5],cars_rank[maxn+5],cars_backup[maxn+5];
Heap heap_s[maxn+10000+5]; //因为最多做10000次，每次最多会增加一个，所以要开maxn+10000
void swim(int k){
    while (k>1&&heap_s[k]<heap_s[k/2])
    {
        swap(heap_s[k],heap_s[k/2]);
        k=k/2;
    }
}

void sink(int k){
    while(2*k <= h_pos){
        int j = 2*k;
        if(j < h_pos && heap_s[j+1] < heap_s[j]) j = j+1;
        if(heap_s[k] < heap_s[j]) break;
        swap(heap_s[j], heap_s[k]);
        k = j;
    }
}
Heap del_s() //删除堆顶
{
    Heap ret = heap_s[1];
    heap_s[1]=heap_s[h_pos--];
    sink(1);
    return ret;
}
double getti(int i,int j) {
    return (double)(cars[j].pos-cars[i].pos)/(cars[i].vel-cars[j].vel);
} //得到i和j相遇的时间
double getdis(int i,int j) {
    return (double)cars[i].pos+getti(i,j)*cars[i].vel;
} //得到i和j相遇的位置
//int te;
void add_to_heap(int i, int j){
    if(cars[i].vel <= cars[j].vel) return;
    double meet_time = getti(i, j);
    double meet_pos  = getdis(i, j);
    heap_s[++h_pos]=Heap(i,j,meet_time,meet_pos);
    swim(h_pos);
//    put_s(i, j, getti(i, j), getdis(i, j));
}
bool update_cars(Heap h){
    int lft=h.left,rgt=h.right;
    if (r[lft]!=rgt||l[rgt]!=lft) return false; //判断该堆顶是否“过期”，也就是判重
    printf("%d %d\n",lft,rgt);//te++;
    int left_of_left=l[lft],right_of_right=r[rgt];
    if (right_of_right!=ship_num+1){
        l[right_of_right]=lft;
        add_to_heap(lft, right_of_right);
    } //x和y交换过后，x和r[y]产生新状况
    if (left_of_left) {
        r[left_of_left]=rgt;
        add_to_heap(left_of_left, rgt);
    } //x和y交换后，y和l[x]产生新状况
    l[lft]=rgt;
    r[lft]=right_of_right;
    l[rgt]=left_of_left; //修正链表
    r[rgt]=lft;
    return true;
}
void record_pass(){
    for (int i=1;i<=ship_num-1;i++) {
        add_to_heap(i, i + 1);
    }
    int te=1;
    while (h_pos && te <= 10000)
    {
        Heap min= del_s();
        if(update_cars(min)){
            te++;
        }
    }
}
void merge(int lo, int mid, int high){
    int i = lo, j = mid+1;
    for(int k = lo; k <= high; k++){
        cars_backup[k] = cars_rank[k];
    }
    for(int k = lo; k <= high; k++){
        if(i > mid)        cars_rank[k] = cars_backup[j++];
        else if(j > high)  cars_rank[k] = cars_backup[i++];
        else if(cars_backup[i] <= cars_backup[j]){
            cars_rank[k] = cars_backup[i++];
        }
        else {
            cars_rank[k] =cars_backup[j++];
            pass_cnt = (pass_cnt+mid-i+1)%tt;
        }
    }
}
void msort() //二路归并
{
    for(int sz = 1; sz < ship_num; sz = sz + sz){
        for(int lo = 1; lo <=  ship_num- sz; lo += sz + sz){
            merge(lo, lo + sz - 1, min(lo+sz+sz-1, ship_num));
        }
    }
}
int main()
{
    scanf("%d",&ship_num);
    int positon, velocity;
    h_pos = 0;
    for(int i = 1; i <= ship_num; i++){
        getchar();
        scanf("%d%d", &positon, &velocity);
        cars[i].vel = velocity;
        cars[i].pos = positon;
        l[i]      = i-1;
        r[i]      = i+1;
    }
    memcpy(cars_rank,cars,sizeof(cars)); //备份一个b用来二路归并求逆序对
    msort();
    printf("%d\n",pass_cnt);
    record_pass();
    return 0;
}
