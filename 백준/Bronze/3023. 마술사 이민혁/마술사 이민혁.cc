#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    char arr[100][100];
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            arr[2*N-1-r][c] = arr[r][c];
            arr[r][2*M-1-c] = arr[r][c];
            arr[2*N-1-r][2*M-1-c] = arr[r][c];
        }
    }
    
    int A, B; cin >> A >> B;
    A--; B--;
    if(arr[A][B] == '.') arr[A][B] = '#';
    else arr[A][B] = '.';
    
    for(int r = 0; r < 2*N; r++) {
        for(int c = 0; c < 2*M; c++) {
            cout << arr[r][c];
        }
        cout << '\n';
    }
    
    return 0;
}