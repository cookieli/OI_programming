#include <iostream>
#include <vector>
using namespace std;
//typedef unsigned long long int ull;
typedef long long int ll;
int num_of_investments;
ll need_money;
vector<pair<ll, ll>> investments;
const ll r = 1e8;
ll get_maxed_earned_money(ll k){
    auto sz = investments.size();
    ll ret = 0;
    for(int i = 0; i < sz; i++){
        ll v = investments[i].first * k - investments[i].second;
        if(v > 0) ret += v;
    }
    return ret;
}
void binary_search(){
    ll lo = 0, hi = r;
    ll ret;
    while( lo <= hi){
        ll mid = (lo + hi)/2;
        ll earned_money = get_maxed_earned_money(mid);
        if(earned_money > need_money){
            ret = mid;
            hi = mid - 1;
        } else if(earned_money < need_money){
            lo = mid + 1;
        } else {
            cout << mid << endl;
            return ;
        }
    }
    cout << ret << endl;
}
int main() {
    cin >> num_of_investments >> need_money;
    for(int i = 0; i < num_of_investments; i++){
        ll profit, base;
        cin >> profit >> base;
        investments.push_back(pair<ll, ll>(profit, base));
    }
    binary_search();
    return 0;
}
