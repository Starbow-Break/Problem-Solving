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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int dp[200][1<<14] = {0, };
char arr[14][15];
int score[6][6] = {{10, 8, 7, 5, 0, 1}, {8, 6, 4, 3, 0, 1}, {7, 4, 3, 2, 0, 1},
    {5, 3, 2, 2, 0, 1}, {0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int i = 0; i < N*M; i++) {
        for(int state = 0; state < (1<<M); state++) {
            if(i%M != M-1 && !(state & 1) && !(state & 2)) {
                dp[i+2][state>>2] 
                    = max(dp[i+2][state>>2], dp[i][state]+score[arr[i/M][i%M]-'A'][arr[(i+1)/M][(i+1)%M]-'A']);
            }
            if(i/M != N-1 && !(state & 1)) {
                dp[i+1][(state>>1)|(1<<(M-1))] 
                    = max(dp[i+1][(state>>1)|(1<<(M-1))], dp[i][state]+score[arr[i/M][i%M]-'A'][arr[i/M+1][i%M]-'A']);
            }
            dp[i+1][state>>1] = max(dp[i+1][state>>1], dp[i][state]);
        }
    }
    
    cout << dp[N*M][0];

    return 0;
}