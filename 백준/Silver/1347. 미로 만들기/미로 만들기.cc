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

char arr[101][101];
int cntRow[101] = {0, }, cntCol[101] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i <= 100; i++) fill(arr[i], arr[i]+101, '#');
    arr[50][50] = '.'; cntRow[50] = 1; cntCol[50] = 1;
    
    int d = 2, r = 50, c = 50;
    int N; cin >> N;
    string s; cin >> s;
    
    for(int i = 0; i < N; i++) {
        switch(s[i]) {
            case 'L':
                d = (d+3)%4;
                break;
            case 'R':
                d = (d+1)%4;
                break;
            case 'F':
                switch(d) {
                    case 0:
                        r--;
                        break;
                    case 1:
                        c++;
                        break;
                    case 2:
                        r++;
                        break;
                    case 3:
                        c--;
                        break;
                }
        }
        
        if(arr[r][c] == '#') {
            cntCol[c]++; cntRow[r]++; arr[r][c] = '.';
        }
    }
    
    int r1 = -1, r2 = -1, c1 = -1, c2 = -1;
    for(int r = 0; r <= 100; r++) {
        if(cntRow[r]) {
            if(r1 == -1) r1 = r2 = r;
            else r2++;
        }
    }
    for(int c = 0; c <= 100; c++) {
        if(cntCol[c]) {
            if(c1 == -1) c1 = c2 = c;
            else c2++;
        }
    }
    
    for(int r = r1; r <= r2; r++) {
        for(int c = c1; c <= c2; c++) {
            cout << arr[r][c];
        }
        cout << '\n';
    }

    return 0;
}