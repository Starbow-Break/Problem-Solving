#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MAX 1000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int T;
int gear[MAX+1][8];

void rotateGear(int num, int d) {
    if(d == 0) return;
    
    int temp[8];
    for(int i = 0; i < 8; i++) {
        temp[(i+8+d)%8] = gear[num][i];
    }
    for(int i = 0; i < 8; i++) {
        gear[num][i] = temp[i];
    }
}

void rotateGears(int start, int d) {
    int dir[T+1] = {0, }; dir[start] = d;
    for(int i = start-1; i >= 1; i--) {
        if(gear[i][2] == gear[i+1][6]) break;
        dir[i] = -dir[i+1];
    }
    for(int i = start+1; i <= T; i++) {
        if(gear[i][6] == gear[i-1][2]) break;
        dir[i] = -dir[i-1];
    }
    
    for(int i = 1; i <= T; i++) { rotateGear(i, dir[i]); }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for(int i = 1; i <= T; i++) {
        string s; cin >> s;
        for(int j = 0; j < 8; j++) { gear[i][j] = s[j]-'0'; }
    }
    
    int K; cin >> K;
    while(K--) {
        int num, d; cin >> num >> d;
        rotateGears(num, d);
    }

    int ans = 0;
    for(int i = 1; i <= T; i++) {
        ans += gear[i][0];
    }
    
    cout << ans;

    return 0;
}