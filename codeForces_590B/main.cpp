#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double x_initial,y_initial, x_end, y_end;
double v_max, time_after;
double v_x, v_y;
double w_x, w_y;
double time_to_beyond_des(double t){
    if(t <= time_after){
        double x_0 = x_initial + v_x * t;
        double y_0 = y_initial + v_y * t;
//        if (x_0 == x_end && y_0 == y_end) return 0.0;
//        if((x_0 >=x_end && y_0 >=y_end)) return 1.0;
        double dis = sqrt(pow((y_end- y_0),2.0)+pow((x_end - x_0), 2.0));
        return t*v_max - dis;
    } else{
        double x_0 = x_initial + v_x * time_after;
        double y_0 = y_initial + v_y * time_after;
        double res_t = t - time_after;
        x_0 += res_t * w_x;
        y_0 += res_t * w_y;
//        if (x_0 == x_end && y_0 == y_end) return 0.0;
//        if((x_0 >=x_end && y_0 >=y_end)) return 1.0;
        double dis = sqrt(pow((y_end- y_0),2.0)+pow((x_end - x_0), 2.0));
        return t*v_max - dis;
    }
}
void binary_search(){
    double lo = 0, hi = 1e9;
    double ans;
    while(lo + 1e-8 <= hi){
        double mid = (lo + hi)/2;
        double time_beyond = time_to_beyond_des(mid);
        if(time_beyond > 0.0){
            ans = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(7)<<ans << endl;
}
int main() {
    cin >> x_initial >> y_initial >> x_end >> y_end;
    cin >> v_max >> time_after;
    cin >> v_x >> v_y;
    cin >> w_x >> w_y;
    binary_search();
    return 0;
}
