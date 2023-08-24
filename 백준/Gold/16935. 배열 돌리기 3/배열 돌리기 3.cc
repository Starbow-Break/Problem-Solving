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

int N, M, R;
int arr[100][100];

void op1() {
    int temp[100][100];
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            temp[N-1-r][c] = arr[r][c];
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            arr[r][c] = temp[r][c];
        }
    }
}

void op2() {
    int temp[100][100];
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            temp[r][M-1-c] = arr[r][c];
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            arr[r][c] = temp[r][c];
        }
    }
}

void op3() {
    int temp[100][100];
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            temp[c][N-1-r] = arr[r][c];
        }
    }
    
    swap(N, M);
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            arr[r][c] = temp[r][c];
        }
    }
}

void op4() {
    int temp[100][100];
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            temp[M-1-c][r] = arr[r][c];
        }
    }
    
    swap(N, M);
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            arr[r][c] = temp[r][c];
        }
    }
}

void op5() {
    int temp[100][100];
    for(int r = 0; r < N/2; r++) {
        for(int c = 0; c < M/2; c++) {
            temp[r][c+M/2] = arr[r][c];
            temp[r+N/2][c+M/2] = arr[r][c+M/2];
            temp[r+N/2][c] = arr[r+N/2][c+M/2];
            temp[r][c] = arr[r+N/2][c];
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            arr[r][c] = temp[r][c];
        }
    }
}

void op6() {
    int temp[100][100];
    for(int r = 0; r < N/2; r++) {
        for(int c = 0; c < M/2; c++) {
            temp[r+N/2][c] = arr[r][c];
            temp[r][c] = arr[r][c+M/2];
            temp[r][c+M/2] = arr[r+N/2][c+M/2];
            temp[r+N/2][c+M/2] = arr[r+N/2][c];
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            arr[r][c] = temp[r][c];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> R;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cin >> arr[r][c];
    }
    
    while(R--) {
        int q; cin >> q;
        switch(q) {
            case 1:
            op1();
            break;
            case 2:
            op2();
            break;
            case 3:
            op3();
            break;
            case 4:
            op4();
            break;
            case 5:
            op5();
            break;
            case 6:
            op6();
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cout << arr[r][c] << ' ';
        cout << '\n';
    }
    
    return 0;
}
