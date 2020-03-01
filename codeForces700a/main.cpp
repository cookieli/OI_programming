#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double n_pupil, distance, v1, v2, k_seats;
    cin >> n_pupil >> distance >> v1 >> v2 >> k_seats;
    int num_of_groups = ceil(n_pupil/k_seats);
    double rgt_part  = distance/v1;
    double left_part = num_of_groups - 1
                      + v2/v1 + (num_of_groups - 1)
                      *(v2 - v1)/(v1 + v2);
    double time = rgt_part/left_part;
    time += (distance - v2 * time)/v1;
    cout << fixed << setprecision(7) << time << endl;
    return 0;
}
