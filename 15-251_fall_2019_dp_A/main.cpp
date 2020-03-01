#include <iostream>
#include <string>
using namespace std;
string sign;
int can_be_dropped[1030][1030];//-1 not, 1 yes, 0 undefined
int can_sign_drop(int begin, int end){
    if(begin >= end) return 1;
    if(can_be_dropped[begin][end] != 0){
        return can_be_dropped[begin][end];
    }
    if(sign[begin] == sign[begin+1]){
        if(can_be_dropped[begin+2][end] == 0){
            can_be_dropped[begin+2][end] = can_sign_drop(begin+2, end);
        }
        if(can_be_dropped[begin+2][end] > 0) {
            can_be_dropped[begin][end] = 1;
            return 1;
        }
    }
    if(sign[begin] == sign[end]){
        if(can_be_dropped[begin+1][end-1] == 0){
            can_be_dropped[begin+1][end-1] = can_sign_drop(begin+1, end-1);
        }
        if(can_be_dropped[begin+1][end-1] > 0) {
            can_be_dropped[begin][end] = 1;
            return 1;
        }
    }
    if(sign[end] == sign[end-1]){
        if(can_be_dropped[begin][end-2] == 0){
            can_be_dropped[begin][end-2] = can_sign_drop(begin, end-2);
        }
        if(can_be_dropped[begin][end-2] > 0) {
            can_be_dropped[begin][end] = 1;
            return 1;
        }
    }
    can_be_dropped[begin][end] = -1;
    return -1;

}
int main() {
    cin >> sign;
//    cout <<sign.length() << endl;
    if(can_sign_drop(0, sign.length()-1) > 0){
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
