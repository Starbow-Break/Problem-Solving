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
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
int S[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N; S[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> S[i]; S[i] += S[i-1];
    }
    
    int M; cin >> M;
    while(M--) {
        int l, r; cin >> l >> r;
        cout << S[r]-S[l-1] << '\n';
    }

    return 0;
}