//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#define ll long long int;
//#define MAXN 3000000
//using namespace std;
//int n, m;
//struct Edge {
//    int from;
//    int to;
//    int weight;
//    bool operator < (Edge &e){
//        return weight < e.weight;
//    }
//};
//Edge edges[MAXN];
//int f[MAXN];
//int g[MAXN];
//int main() {
//    cin >> n >> m;
//    for(int i = 1; i <= m; i++){
//        int tmpF, tmpTo, tmpW;
//        cin >> tmpF >> tmpTo >> tmpW;
//        edges[i] = Edge{tmpF, tmpTo, tmpW};
//    }
//    sort(edges+1, edges + m+1);
//    memset(f, 0, sizeof(f));
//    memset(g, 0, sizeof(g));
//    int t =1;
//    int ans = 0;
//    for(int i = 1; i<= m ; i++){
//        f[i] = g[edges[i].from] + 1;
//        if(edges[i].weight < edges[i+1].weight){
//            for(int j = t; j <= i; j++){
//                g[edges[j].to] = max(g[edges[j].to], f[j]);
//            }
//            t = i + 1;
//        }
//        ans = max(ans, f[i]);
//    }
//    cout << ans << endl;
//    return 0;
//}
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long int;
#define MAXN 3000000
using namespace std;
int n, m;
struct Edge {
    int from;
    int to;
    int weight;
    bool operator < (Edge &e){
        return weight < e.weight;
    }
};
Edge edges[MAXN];
int num_of_end[MAXN];
int last_w_of_end[MAXN];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int tmpF, tmpTo, tmpW;
        cin >> tmpF >> tmpTo >> tmpW;
        edges[i] = Edge{tmpF, tmpTo, tmpW};
    }
    sort(edges+1, edges + m+1);
    memset(num_of_end, 0, sizeof(num_of_end));
    memset(last_w_of_end, 0, sizeof(last_w_of_end));
    for(int i = 1; i<= m ; i++){
        int from   = edges[i].from;
        int to     = edges[i].to;
        int weight = edges[i].weight;
        if(last_w_of_end[from] < weight){
            if(num_of_end[to] < num_of_end[from] + 1){
                num_of_end[to] = num_of_end[from] + 1;
                last_w_of_end[to] = weight;
            }
        }
    }
    int max_path = 0;
    for(int i = 1; i <= n ; i++){
        if(num_of_end[i] > max_path){
            max_path = num_of_end[i];
        }
    }
    cout << max_path << endl;
    return 0;