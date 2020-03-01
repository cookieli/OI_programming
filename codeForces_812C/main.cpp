#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
typedef unsigned long long int ll;
using namespace std;
ll num_of_goods;
ll total_money;
vector<ll> goods;
//int find_k_cheapest_sum(int k, int lo, int hi, vector<int>& vec){
//
//}
ll minimum_money_for_goods(ll k){
    if(k == 0) return 0;
    vector<ll> goods_prices;
    auto sz = goods.size();
    for(auto i = 1; i<= sz; i++){
        goods_prices.push_back(goods[i-1]+ (ll)i*k);
    }
    sort(goods_prices.begin(), goods_prices.end());
    return accumulate(goods_prices.begin(), (goods_prices.begin())+k, (ll)0);
}
void binary_search(ll n){
    ll lo = 0, hi = n, ans = 0, cost = 0;
    while(lo <= hi){
        ll mid = (lo + hi)/2;
        ll need_money = minimum_money_for_goods(mid);
        if(need_money > total_money){
            hi = mid - 1;
        } else if(need_money == total_money){
            cout << mid << " "<< need_money << endl;
            return;
        } else {
            ans = mid;
            cost = need_money;
            lo = mid+1;
        }
    }
    cout << ans <<" " << cost << endl;
}
int main() {
    cin >> num_of_goods >> total_money;
    for(ll i = 0; i < num_of_goods; i++){
        ll price;
        cin >> price;
        goods.push_back(price);
    }
    binary_search(num_of_goods);
    return 0;
}


