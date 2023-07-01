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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int computer[31][31];
int rowCnt[31] = {0, }, colCnt[31] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, u; cin >> N >> u;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> computer[i][j];
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) rowCnt[r] += computer[r][c];
    }
    
    for(int c = 0; c < N; c++) {
        for(int r = 0; r < N; r++) colCnt[c] += computer[r][c];
    }
    
    while(1) {
        bool change = false;
        
        for(int r = 0; r < N; r++) {
            if(u) {
                if(rowCnt[r] > N/2 && rowCnt[r] != N) {
                    change = true;
                    for(int c = 0; c < N; c++) {
                        if(computer[r][c] == 0) {
                            computer[r][c] = 1; 
                            rowCnt[r]++; colCnt[c]++;
                        }
                    }
                }
            }
            else {
                if(rowCnt[r] <= N/2 && rowCnt[r] != 0) {
                    change = true;
                    for(int c = 0; c < N; c++) {
                        if(computer[r][c] == 1) {
                            computer[r][c] = 0; 
                            rowCnt[r]--; colCnt[c]--;
                        }
                    }
                }
            }
        }
        for(int c = 0; c < N; c++) {
            if(u) {
                if(colCnt[c] > N/2 && colCnt[c] != N) {
                    change = true;
                    for(int r = 0; r < N; r++) {
                        if(computer[r][c] == 0) {
                            computer[r][c] = 1; 
                            rowCnt[r]++; colCnt[c]++;
                        }
                    }
                }
            }
            else {
                if(colCnt[c] <= N/2 && colCnt[c] != 0) {
                    change = true;
                    for(int r = 0; r < N; r++) {
                        if(computer[r][c] == 1) {
                            computer[r][c] = 0; 
                            rowCnt[r]--; colCnt[c]--;
                        }
                    }
                }
            }
        }
        
        if(!change) break;
    }
    
    bool pos = true;
    for(int r = 0; r < N; r++) {
        if(u) {if(rowCnt[r] < N) pos = false;}
        else {if(rowCnt[r] > 0) pos = false;}
    }
    cout << pos;

    return 0;
}