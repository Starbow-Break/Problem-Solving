#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MAX 10000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M;
int cnt[100001] = {0, }; int total = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int m; cin >> m;
        cnt[m]++; total += m;
    }
    cin >> M;
    
    int ans = 100000;
    while(total > M || !cnt[ans]) {
        total -= cnt[ans];
        cnt[ans-1] += cnt[ans];
        cnt[ans] = 0; ans--;
    }
    
    cout << ans;

    return 0;
}