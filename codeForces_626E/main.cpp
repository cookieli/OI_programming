//idea
//the final set must have odd number
//because if you have even, delete median above. answer will be better
//fixed median and ternary search
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;
const double MIN = numeric_limits<double>::min();

typedef long long int ll;


int num;
//vector<ll> sum;
//vector<ll> lst;
ll lst[200005];
ll sum[200005];
ll get_mean(int k, int c) {
   ll sum1 = sum[num] -sum[num-c] + sum[k] - sum[k-c-1];
   return sum1;
}
int solve(int m1,int m2,int i)
{
    ll s1=sum[num]-sum[num-m1]+sum[i]-sum[i-m1-1];
    ll s2=sum[num]-sum[num-m2]+sum[i]-sum[i-m2-1];
    return s1*(2*m2+1)<s2*(2*m1+1);
}
pair<pair<int, int>, ll> find_max_subset_with_fixed_median(int k) {
    int lo = 0;
    int hi = min(num-k, k-1);
    int ans;
    ll value;
    while (lo <= hi) {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo-2) / 3;
        if(solve(mid1, mid2, k)) {
            lo = mid1 + 1;
            ans = mid1;
        }
        else {
            hi = mid2 - 1;
            ans = mid2;
        }
//        ll real_mean1 = get_mean(k, mid1);
//        ll real_mean2 = get_mean(k, mid2);
//        int mean1 = real_mean1 * (2 * mid2 + 1);
//        int mean2 = real_mean2 * (2 * mid1 + 1);
//        bool mean_diff = mean1 < mean2;
//        if (!mean_diff) {
//            value = real_mean1 - (2 * mid1 +1) * lst[k];
//            ans = mid1;
//            hi = mid2 - 1;
//        } else {
//            value = real_mean2 - (2 * mid2 +1) * lst[k];
//            ans = mid2;
//            lo = mid1+1;
//        }
    }
    value = sum[num] - sum[num - lo] + sum[k] - sum[k-lo-1]-(2*lo+1)*lst[k];
    return pair<pair<int, int>, ll>(pair<int, int>(k, lo), value);
}

int main() {
    cin >> num;
    for (int i = 1; i <= num; i++) {
        ll tmp;
        cin >> tmp;
        lst[i] =tmp;
    }
    sort(lst+1, lst+num+1);
    sum[0] = 0;
    for (int i = 1; i <= num; i++) {
        sum[i]=sum[i-1]+lst[i];
    }
    auto max = find_max_subset_with_fixed_median(1);
    for (int i = 2; i < num; i++) {
        auto v = find_max_subset_with_fixed_median(i);
        if (v.second * (ll) (2 * max.first.second + 1) > max.second * (ll) (2 * v.first.second + 1)) {
            max = v;
        }
    }

    int k = max.first.first;
    int c = max.first.second;
    cout << 2 * c + 1 << endl;
//   if(2*c+1 == 179571){
//       cout <<"log: "<< log << endl;
//   }
    for(int i = k-c; i<=k; i++){
        cout << lst[i] << " ";
    }
    for (int i = num - c+1; i <= num; i++) {
        cout << lst[i] << " ";
    }
    cout << endl;
    return 0;
}

