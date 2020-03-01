#include <iostream>
typedef  long long int ll;
int rep_of_B, rep_of_S, rep_of_C;
int num_of_B, num_of_S, num_of_C;
int pri_of_B, pri_of_S, pri_of_C;
ll rubles;
using namespace std;

ll cost_of_hamburgers(ll h){
    ll need_B = 0, need_S = 0, need_C = 0;
    need_B = max((h*rep_of_B - num_of_B), (ll)0);
    need_S = max((h*rep_of_S - num_of_S), (ll)0);
    need_C = max((h*rep_of_C - num_of_C), (ll)0);
    return need_B * pri_of_B + need_S * pri_of_S + need_C * pri_of_C;
}
void binary_search(){
    ll low = 0, high = rubles+1000 , mid = 0, ans = 0;
    while(low < high-1){
        mid = (low+high)/2;
//        cout << mid << endl;
        if(cost_of_hamburgers(mid) > rubles){
            high = mid;
        } else if (cost_of_hamburgers(mid) < rubles){
           low = mid;
           ans = mid;
        } else {
            cout << mid << endl;
            return;
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    string recipe;
    cin >> recipe;
    string::size_type n = recipe.size();
    rep_of_B = rep_of_S = rep_of_C = 0;
    for(auto i = 0; i < n; i++){
        if (recipe[i] == 'B')       rep_of_B++;
        else if (recipe[i] == 'S')  rep_of_S++;
        else                        rep_of_C++;
    }
    cin >> num_of_B >> num_of_S >> num_of_C;
    cin >> pri_of_B >> pri_of_S >> pri_of_C;
    cin >> rubles;
    binary_search();

    return 0;
}
