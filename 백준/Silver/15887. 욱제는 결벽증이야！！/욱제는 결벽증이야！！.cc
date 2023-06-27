#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MOD 1'000'000'009

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int arr[1'001], idx[1'001];
vector<pii> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) {
        idx[arr[i]] = i;
    }
    
    for(int i = 1; i <= N; i++) {
        if(idx[i] != i) {
            ans.push_back({min(i, idx[i]), max(i, idx[i])});
            reverse(arr+min(i, idx[i]), arr+max(i, idx[i])+1);
            for(int i = 1; i <= N; i++) {
                idx[arr[i]] = i;
            }
        }
    }
    
    cout << ans.size() << '\n';
    for(auto &a: ans) cout << a << '\n';
    
    return 0;
}