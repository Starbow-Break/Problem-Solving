#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
int arr[1000];

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int solve() {
    vector<int> vec;
    for(int i = 1; i < N; i++) { vec.push_back(abs(arr[i]-arr[i-1])); }
    
    int ret = vec[0];
    for(int i = 1; i < N-1; i++) {
        ret = gcd(ret, vec[i]);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << solve() << '\n';

    return 0;
}