#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    cout << N*(N-1)/2 << '\n';
    for(int i = 1; i <= N; i++) {
        cout << fixed; cout.precision(0);
        cout << pow(2, i-1) << " ";
    }
    cout << '\n' << N-1 << '\n';
    for(int i = 1; i <= N; i++) {
        cout << i << " ";
    }

    return 0;
}