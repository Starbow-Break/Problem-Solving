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

int N, M;
bool check[201][201] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        check[a][b] = true; check[b][a] = true;
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            for(int k = j+1; k <= N; k++) {
                if(!check[i][j] && !check[i][k] && !check[j][k]) ans++;
            }
        }
    }
    
    cout << ans;

    return 0;
}