#include <iostream>
#include <algorithm>

#define MAXN 103000
using namespace std;
typedef long long int ll;
ll num_of_string;
ll c[MAXN];
ll dp[MAXN][2]; //if snd is 0 last string not reverse value, else reverse value
string ss[MAXN];

string reverse_string(const string &s) {
    return string(s.rbegin(), s.rend());
}

void check() {
    dp[1][0] = 0;
    dp[1][1] = c[1];
    for (ll i = 2; i <= num_of_string; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
        if (dp[i - 1][0] >= 0) {
            if (ss[i] >= ss[i - 1]) {
                dp[i][0] = dp[i - 1][0];
            }
            if (reverse_string(ss[i]) >= ss[i - 1]) {
                dp[i][1] = dp[i - 1][0] + c[i];
            }
        }
        if (dp[i - 1][1] >=0){
            if(ss[i] >= reverse_string(ss[i-1])){
                if(dp[i][0] >= 0 && dp[i-1][1] <dp[i][0]){
                    dp[i][0] = dp[i-1][1];
                } else if(dp[i][0] == -1){
                    dp[i][0] = dp[i-1][1];
                }
            }
            if(reverse_string(ss[i]) >= reverse_string(ss[i-1])){
                if(dp[i][1] >=0 && dp[i-1][1] + c[i] < dp[i][1]){
                    dp[i][1] = dp[i-1][1] + c[i];
                } else if(dp[i][1] == -1){
                    dp[i][1] = dp[i-1][1] + c[i];
                }
            }
        }
        if(dp[i][0] == -1 && dp[i][1] == -1){
            cout << -1 << endl;
            return;
        }
    }
    if(dp[num_of_string][0] < 0){
        cout<< dp[num_of_string][1] << endl;
        return;
    }
    if(dp[num_of_string][1] <0 ){
        cout << dp[num_of_string][0] << endl;
        return;
    }
    cout << min(dp[num_of_string][0], dp[num_of_string][1]) << endl;
}

int main() {
    cin >> num_of_string;
    for (ll i = 1; i <= num_of_string; i++) {
        ll tmp;
        cin >> tmp;
        c[i] = tmp;
    }
    for (ll i = 1; i <= num_of_string; i++) {
        string str;
        cin >> str;
        ss[i] = str;
    }
    check();
    return 0;
}
