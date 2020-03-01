#include <iostream>
#include <tuple>
#include <cstring>
#include <iomanip>
#define MAXN 130
using namespace std;
#define R 0
#define S 1
#define P 2
int r, s, p;
double prop_of[3][MAXN][MAXN][MAXN];
//rs, rp, sp
tuple<double, double, double> meetup_prop(double r, double s, double p){
    double total = r*s + s*p + p * r;
    return make_tuple((r*s)/total, (r*p)/total,
                      (p*s)/total);
}
double prop_of_win(int species, int r, int s, int p){
    if(r * s * p < 0)    return 0.0;
    if(species == R) {
        if (r == 0)      return 0.0;
        else if (p == 0) return 1.0;
    } else if(species == S){
        if(s == 0)       return 0.0;
        else if(r == 0)  return 1.0;
    } else{
        if(p == 0)      return 0.0;
        else if(s==0)   return 1.0;
    }
    if(prop_of[species][r][s][p] >= 0){
        return prop_of[species][r][s][p];
    }
    auto [P_rs, P_rp, P_sp] = meetup_prop((double)r,(double)s,(double)p);
    return prop_of[species][r][s][p] = (P_rs * prop_of_win(species, r,s-1, p)
                                      + P_rp * prop_of_win(species,r-1,s,p)
                                      + P_sp * prop_of_win(species,r, s, p-1));

}
int main() {
    cin >> r >> s >> p;
    memset(prop_of, -1, sizeof(prop_of));
    cout << fixed << setprecision(10)<< prop_of_win(R, r, s, p) << " " << prop_of_win(S, r,s,p)  << " " << prop_of_win(P, r,s, p) << endl;
}
