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

const int RIGHT = 0;
const int LEFT = 1;
const int UP = 2;
const int DOWN = 3;

struct node {
    int temp, lazy;
    
    void propagate() {
        temp += lazy; lazy = 0;
    }
};

struct heater {
    int r, c, d; 
};

int R, C, K;
node room[21][21];
int wall[21][21] = {0, };
vector<pii> check;
vector<heater> heaters;

void windForHeater() {
    bool check[21][21];
    
    for(auto &h: heaters) {
        for(int i = 1; i <= 20; i++) fill(check[i], check[i]+21, false);
        
        if(h.d == RIGHT) {
            if(wall[h.r][h.c] & (1 << RIGHT)) continue;
            
            if(h.c+1 <= C) { check[h.r][h.c+1] = true; room[h.r][h.c+1].temp += 5; }
            for(int c = 1; c <= 4; c++) {
                for(int r = -(c-1); r <= c-1; r++) {
                    if(!(1 <= h.r+r && h.r+r <= R && 1 <= h.c+c && h.c+c <= C) || !check[h.r+r][h.c+c]) continue;
                    
                    if(1 <= h.r+r-1 && h.r+r-1 <= R && 1 <= h.c+c+1 && h.c+c+1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << UP)) && !(wall[h.r+r-1][h.c+c] & (1 << RIGHT))) {
                            if(!check[h.r+r-1][h.c+c+1]) {
                                room[h.r+r-1][h.c+c+1].temp += 5-c; check[h.r+r-1][h.c+c+1] = true;
                            }
                        }
                    }
                    if(1 <= h.r+r && h.r+r <= R && 1 <= h.c+c+1 && h.c+c+1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << RIGHT))) {
                            if(!check[h.r+r][h.c+c+1]) {
                                room[h.r+r][h.c+c+1].temp += 5-c; check[h.r+r][h.c+c+1] = true;
                            }
                        }
                    }
                    if(1 <= h.r+r+1 && h.r+r+1 <= R && 1 <= h.c+c+1 && h.c+c+1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << DOWN)) && !(wall[h.r+r+1][h.c+c] & (1 << RIGHT))) {
                            if(!check[h.r+r+1][h.c+c+1]) {
                                room[h.r+r+1][h.c+c+1].temp += 5-c; check[h.r+r+1][h.c+c+1] = true;
                            }
                        }
                    }
                }
            }
        }
        if(h.d == LEFT) {
            if(wall[h.r][h.c] & (1 << LEFT)) continue;
            
            if(h.c-1 >= 1) { check[h.r][h.c-1] = true; room[h.r][h.c-1].temp += 5; }
            for(int c = -1; c >= -4; c--) {
                for(int r = c+1; r <= -c-1; r++) {
                    if(!(1 <= h.r+r && h.r+r <= R && 1 <= h.c+c && h.c+c <= C) || !check[h.r+r][h.c+c]) continue;
                    
                    if(1 <= h.r+r-1 && h.r+r-1 <= R && 1 <= h.c+c-1 && h.c+c-1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << UP)) && !(wall[h.r+r-1][h.c+c] & (1 << LEFT))) {
                            if(!check[h.r+r-1][h.c+c-1]) {
                                room[h.r+r-1][h.c+c-1].temp += 5+c; check[h.r+r-1][h.c+c-1] = true;
                            }
                        }
                    }
                    if(1 <= h.r+r && h.r+r <= R && 1 <= h.c+c-1 && h.c+c-1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << LEFT))) {
                            if(!check[h.r+r][h.c+c-1]) {
                                room[h.r+r][h.c+c-1].temp += 5+c; check[h.r+r][h.c+c-1] = true;
                            }
                        }
                    }
                    if(1 <= h.r+r+1 && h.r+r+1 <= R && 1 <= h.c+c-1 && h.c+c-1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << DOWN)) && !(wall[h.r+r+1][h.c+c] & (1 << LEFT))) {
                            if(!check[h.r+r+1][h.c+c-1]) {
                                room[h.r+r+1][h.c+c-1].temp += 5+c; check[h.r+r+1][h.c+c-1] = true;
                            }
                        }
                    }
                }
            }
        }
        if(h.d == UP) {
            if(wall[h.r][h.c] & (1 << UP)) continue;
            
            if(h.r-1 >= 1) { check[h.r-1][h.c] = true; room[h.r-1][h.c].temp += 5; }
            for(int r = -1; r >= -4; r--) {
                for(int c = r+1; c <= -r-1; c++) {
                    if(!(1 <= h.r+r && h.r+r <= R && 1 <= h.c+c && h.c+c <= C) || !check[h.r+r][h.c+c]) continue;
                    
                    if(1 <= h.r+r-1 && h.r+r-1 <= R && 1 <= h.c+c-1 && h.c+c-1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << LEFT)) && !(wall[h.r+r][h.c+c-1] & (1 << UP))) {
                            if(!check[h.r+r-1][h.c+c-1]) {
                                room[h.r+r-1][h.c+c-1].temp += 5+r; check[h.r+r-1][h.c+c-1] = true;
                            }
                        }
                    }
                    if(1 <= h.r+r-1 && h.r+r-1 <= R && 1 <= h.c+c && h.c+c <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << UP))) {
                            if(!check[h.r+r-1][h.c+c]) {
                                room[h.r+r-1][h.c+c].temp += 5+r; check[h.r+r-1][h.c+c] = true;
                            }
                        }
                    }
                    if(1 <= h.r+r-1 && h.r+r-1 <= R && 1 <= h.c+c+1 && h.c+c+1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << RIGHT)) && !(wall[h.r+r][h.c+c+1] & (1 << UP))) {
                            if(!check[h.r+r-1][h.c+c+1]) {
                                room[h.r+r-1][h.c+c+1].temp += 5+r; check[h.r+r-1][h.c+c+1] = true;
                            }
                        }
                    }
                }
            }
        }
        if(h.d == DOWN) {
            if(wall[h.r][h.c] & (1 << DOWN)) continue;
            
            if(h.r+1 <= R) { check[h.r+1][h.c] = true; room[h.r+1][h.c].temp += 5; }
            for(int r = 1; r <= 4; r++) {
                for(int c = -(r-1); c <= r-1; c++) {
                    if(!(1 <= h.r+r && h.r+r <= R && 1 <= h.c+c && h.c+c <= C) || !check[h.r+r][h.c+c]) continue;
                    
                    if(1 <= h.r+r+1 && h.r+r+1 <= R && 1 <= h.c+c-1 && h.c+c-1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << LEFT)) && !(wall[h.r+r][h.c+c-1] & (1 << DOWN))) {
                            if(!check[h.r+r+1][h.c+c-1]) {
                                room[h.r+r+1][h.c+c-1].temp += 5-r; check[h.r+r+1][h.c+c-1] = true;
                            }
                        }
                    }
                    if(1 <= h.r+r+1 && h.r+r+1 <= R && 1 <= h.c+c && h.c+c <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << DOWN))) {
                            if(!check[h.r+r+1][h.c+c]) {
                                room[h.r+r+1][h.c+c].temp += 5-r; check[h.r+r+1][h.c+c] = true;
                            }
                        }
                    }
                    if(1 <= h.r+r+1 && h.r+r+1 <= R && 1 <= h.c+c+1 && h.c+c+1 <= C) {
                        if(!(wall[h.r+r][h.c+c] & (1 << RIGHT)) && !(wall[h.r+r][h.c+c+1] & (1 << DOWN))) {
                            if(!check[h.r+r+1][h.c+c+1]) {
                                room[h.r+r+1][h.c+c+1].temp += 5-r; check[h.r+r+1][h.c+c+1] = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void controlledTemperature() {
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c < C; c++) {
            if(!(wall[r][c] & (1 << RIGHT))) {
                int d = room[r][c+1].temp-room[r][c].temp;
                
                if(d > 0) {
                    room[r][c+1].lazy -= d/4;
                    room[r][c].lazy += d/4;
                }
                else {
                    room[r][c+1].lazy += (-d)/4;
                    room[r][c].lazy -= (-d)/4;
                }
            } 
        }
    }
    
    for(int c = 1; c <= C; c++) {
        for(int r = 1; r < R; r++) {
            if(!(wall[r][c] & (1 << DOWN))) {
                int d = room[r+1][c].temp-room[r][c].temp;
                
                if(d > 0) {
                    room[r+1][c].lazy -= d/4;
                    room[r][c].lazy += d/4;
                }
                else {
                    room[r+1][c].lazy += (-d)/4;
                    room[r][c].lazy -= (-d)/4;
                }
            }
        }
    }
    
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            room[r][c].propagate();
        }
    }
}

void coolingBorder() {
    for(int r = 1; r <= R; r++) {
        if(room[r][1].temp) room[r][1].temp--;
        if(room[r][C].temp) room[r][C].temp--;
    }
    
    for(int c = 2; c < C; c++) {
        if(room[1][c].temp) room[1][c].temp--;
        if(room[R][c].temp) room[R][c].temp--;
    }
}

bool checkgeK() {
    for(auto &c : check) {
        if(room[c.first][c.second].temp < K) return false;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C >> K;
    
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            int v; cin >> v;
            if(1 <= v && v <= 4) heaters.push_back({r, c, v-1});
            if(v == 5) check.push_back({r, c});
            
            room[r][c] = {0, 0};
        }
    }
    
    int W; cin >> W;
    while(W--) {
        int r, c, t; cin >> r >> c >> t;
        if(t) {
            wall[r][c] |= (1 << RIGHT);
            wall[r][c+1] |= (1 << LEFT);
        }
        else {
            wall[r][c] |= (1 << UP);
            wall[r-1][c] |= (1 << DOWN);
        }
    }
    
    int chocolate;
    while(chocolate <= 100) {
        windForHeater();
        controlledTemperature();
        coolingBorder();
        chocolate++;
        if(checkgeK()) break;
    }

    cout << chocolate;

    return 0;
}