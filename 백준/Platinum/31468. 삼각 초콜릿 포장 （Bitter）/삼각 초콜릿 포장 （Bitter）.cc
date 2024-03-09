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

char triangle2[2][3] = {
    "R",
    "RR"
};

char triangle9[9][10] = {
    "R",
    "RR",
    "RBB",
    "RRBR",
    "RBBRR",
    "RRBBBR",
    "BBBBBRR",
    "RBRBRBBR",
    "RRRRRRBRR"
};

char triangle11[11][12] = {
    "R",
    "RR",
    "RBB",
    "RRBR",
    "RBBRR",
    "RRBBBR",
    "BBBBBRR",
    "RBRBRBBR",
    "RRRRRRBRR",
    "RBBRBBRBBR",
    "RRBRRBRRBRR"
};

char triangle12[12][13] = {
    "R",
    "RR",
    "RBB",
    "RRBR",
    "RBBRR",
    "RRBBBR",
    "BBBBBRR",
    "RBRBRBBR",
    "RRRRRRBRR",
    "BBBBBBBBBB",
    "RBRBRBRBRBR",
    "RRRRRRRRRRRR"
};

char ans[5001][5001];

void useTriangle2(int r, int c, bool mirror = false) {
    if(!mirror) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j <= i; j++) {
                ans[r+i][c+j] = triangle2[i][j];
            }
        }
    }
    else {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j <= i; j++) {
                ans[r+(1-i)][c+(1-j)] = (triangle2[i][j] == 'R' ? 'B' : 'R');
            }
        }
    }
}

void useTriangle9(int r, int c, bool mirror = false) {
    if(!mirror) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j <= i; j++) {
                ans[r+i][c+j] = triangle9[i][j];
            }
        }
    }
    else {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j <= i; j++) {
                ans[r+(8-i)][c+(8-j)] = (triangle9[i][j] == 'R' ? 'B' : 'R');
            }
        }
    }
}


void useTriangle11(int r, int c, bool mirror = false) {
    if(!mirror) {
        for(int i = 0; i < 11; i++) {
            for(int j = 0; j <= i; j++) {
                ans[r+i][c+j] = triangle11[i][j];
            }
        }
    }
    else {
        for(int i = 0; i < 11; i++) {
            for(int j = 0; j <= i; j++) {
                ans[r+(10-i)][c+(10-j)] = (triangle11[i][j] == 'R' ? 'B' : 'R');
            }
        }
    }
}

void useTriangle12(int r, int c, bool mirror = false) {
    if(!mirror) {
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j <= i; j++) {
                ans[r+i][c+j] = triangle12[i][j];
            }
        }
    }
    else {
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j <= i; j++) {
                ans[r+(11-i)][c+(11-j)] = (triangle12[i][j] == 'R' ? 'B' : 'R');
            }
        }
    }
}

void makeTriangle(int sz) {
    if(sz <= 12) {
        switch(sz) {
            case 2:
                useTriangle2(0, 0);
                break;
            case 9:
                useTriangle9(0, 0);
                break;
            case 11:
                useTriangle11(0, 0);
                break;
            case 12:
                useTriangle12(0, 0);
                break;
           
        }
       
        return;
    }
    
    if(sz % 12) {
        makeTriangle(sz/12*12);
        switch(sz%12) {
            case 2:
                for(int i = 0; i < sz/12*12; i += 3) {
                    useTriangle2(sz/12*12, i);
                    useTriangle2(sz/12*12, i+1, true);
                }
                useTriangle2(sz/12*12, sz/12*12);
                break;
            case 11:
                for(int i = 0; i < sz/12*12+9; i += 3) {
                    useTriangle2(sz/12*12+9, i);
                    useTriangle2(sz/12*12+9, i+1, true);
                }
                useTriangle2(sz/12*12+9, sz/12*12+9);
            case 9:
                for(int i = 0; i < sz/12*12; i += 12) {
                    useTriangle9(sz/12*12, i);
                    useTriangle2(sz/12*12, i+1, true);
                    useTriangle2(sz/12*12+1, i+3);
                    useTriangle2(sz/12*12+3, i+4, true);
                    useTriangle2(sz/12*12+4, i+6);
                    useTriangle2(sz/12*12+6, i+7, true);
                    useTriangle2(sz/12*12+7, i+9);
                    useTriangle9(sz/12*12, i+3, true);
                }
                useTriangle9(sz/12*12, sz/12*12);
                break;
        }
    }
    else {
        for(int i = 0; i < sz/12; i++) {
            useTriangle12(i * 12, 0);
            for(int j = 0; j < i; j++) {
                useTriangle12(i * 12, j * 12 + 1, true);
                useTriangle11(i * 12 + 1, j * 12 + 13);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    makeTriangle(N);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
