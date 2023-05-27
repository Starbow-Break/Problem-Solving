#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int arr[999], ans[999];
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    int sum = 0;
    for(int i = 0; i < N; i++) sum += arr[i];
    sum /= 2;
    
    ans[N-1] = sum;
    for(int i = 0; i < N-1; i += 2) {
        ans[N-1] -= arr[i];
    }
    
    for(int i = N-2; i >= 0; i--) {
        ans[i] = arr[i]-ans[i+1];
    }
    
    for(int i = 0; i < N; i++) cout << ans[i] << '\n';

    return 0;
}