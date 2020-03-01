#include <iostream>
#include <cstring>
#define MAXN 130
#define MAX 1e12
using namespace std;
typedef long long int ll;
int n,m,kth;
int color_of_tree[MAXN];
int back_up_color[MAXN];
ll p[MAXN][MAXN];
ll LitresOf[MAXN][MAXN][MAXN];
ll getLitres(int nth, int last_color, int k){ //fill nth with color to satisfy k
    if(nth == n+1){
        if(k == kth){
            return 0;
        } else{
            return MAX;
        }
    }
    if(LitresOf[nth][last_color][k] != -1){
        return LitresOf[nth][last_color][k];
    }
    ll min_litres = MAX;
    if(color_of_tree[nth] == 0){
        for(int i = 1; i<= m ; i++){
            if(i == last_color)  min_litres = min(min_litres, getLitres(nth+1, last_color, k) + p[nth][i]);
            else                 min_litres = min(min_litres, getLitres(nth+1, i,        k+1)+ p[nth][i]);
        }
    } else {
        if(last_color == color_of_tree[nth])
            min_litres = min(min_litres, getLitres(nth+1, last_color, k));
        else
            min_litres = min(min_litres, getLitres(nth+1, color_of_tree[nth], k+1));
    }
    LitresOf[nth][last_color][k] = min_litres;
    return min_litres;
}
int main() {
    cin >> n >> m >> kth;
    for(int i = 1; i <= n ;i++){
        int c;
        cin >> c;
        color_of_tree[i] = c;
        back_up_color[i] = c;
    }
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m;j++){
            ll tmp;
            cin >> tmp;
            p[i][j] = tmp;
        }
    }

    memset(LitresOf, -1, sizeof(LitresOf));
    ll litres = getLitres(1,0,0);
    if(litres == MAX){
        cout << -1 << endl;
    } else {
        cout << litres << endl;
    }
    return 0;
}
