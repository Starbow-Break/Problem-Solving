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
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct routePart {
    pii start, finish;
    
    int length() {
        return abs(start.x-finish.x)+abs(start.y-finish.y);
    }
};

char d = 'R'; //뱀의 이동방향
bool survive = true; //뱀의 생존 여부
ll sec = 0; //뱀의 생존 시간 (초 단위)
vector<routePart> route; //뱀이 지나간 경로

int check(routePart rt) {
    int ret = rt.length();
    
    for(int i = 0; i < route.size()-1; i++) {
        if(route[i].start.x == route[i].finish.x) {
            if(rt.start.x == rt.finish.x) {
                int d = min(route[i].start.y, route[i].finish.y);
                int u = max(route[i].start.y, route[i].finish.y);
                if(rt.start.x == route[i].start.x) {
                    if((d > rt.start.y && rt.finish.y >= d) || (u < rt.start.y && rt.finish.y <= u))
                        ret = min(ret, min(abs(rt.start.y-route[i].start.y), abs(rt.start.y-route[i].finish.y))-1);    
                }
            }
            else {
                int l = min(rt.start.x, rt.finish.x);
                int r = max(rt.start.x, rt.finish.x);
                int d = min(route[i].start.y, route[i].finish.y);
                int u = max(route[i].start.y, route[i].finish.y);
                if((d <= rt.finish.y && rt.finish.y <= u) && (l <= route[i].start.x && route[i].start.x <= r)) {
                    ret = min(ret, abs(rt.start.x-route[i].start.x)-1);
                }
            }
        }
        else {
            if(rt.start.x == rt.finish.x) {
                int d = min(rt.start.y, rt.finish.y);
                int u = max(rt.start.y, rt.finish.y);
                int l = min(route[i].start.x, route[i].finish.x);
                int r = max(route[i].start.x, route[i].finish.x);
                if((l <= rt.finish.x && rt.finish.x <= r) && (d <= route[i].start.y && route[i].start.y <= u)) {
                    ret = min(ret, abs(rt.start.y-route[i].start.y)-1);
                }
            }
            else {
                int l = min(route[i].start.x, route[i].finish.x);
                int r = max(route[i].start.x, route[i].finish.x);
                if(rt.start.y == route[i].start.y) {
                    if((l > rt.start.x && rt.finish.x >= l) || (r < rt.start.x && rt.finish.x <= r)) {
                        ret = min(ret, min(abs(rt.start.x-route[i].start.x), abs(rt.start.x-route[i].finish.x))-1);    
                    }
                }
            }
        }
    }
    
    return ret;
}

void rotate(char r) {
    if(r == 'L') {
        switch(d) {
            case 'R':
                d = 'U';
                break;
            case 'L':
                d = 'D';
                break;
            case 'U':
                d = 'L';
                break;
            case 'D':
                d = 'R';
                break;
        }
    }
    else {
        switch(d) {
            case 'R':
                d = 'D';
                break;
            case 'L':
                d = 'U';
                break;
            case 'U':
                d = 'R';
                break;
            case 'D':
                d = 'L';
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int L, N; cin >> L >> N;
    route.push_back({{0, 0}, {0, 0}});
    while(N-- && survive) {
        int t; char r; cin >> t >> r;
        pii s, f;
        
        s = route.back().finish;
        
        switch(d) {
            case 'R':
                f = {s.x+t, s.y};
                break;
            case 'L':
                f = {s.x-t, s.y};
                break;
            case 'U':
                f = {s.x, s.y+t};
                break;
            case 'D':
                f = {s.x, s.y-t};
                break;
        }

        int add = check({s, f});
        if(add == t) {
            if((-L <= f.x && f.x <= L) && (-L <= f.y && f.y <= L)) {
                sec += add;
                route.push_back({s, f});
                rotate(r);
            }
            else {
                survive = false;
                switch(d) {
                    case 'R':
                        sec += L-s.x;
                        break;
                    case 'L':
                        sec += s.x+L;
                        break;
                    case 'U':
                        sec += L-s.y;
                        break;
                    case 'D':
                        sec += s.y+L;
                        break;
                }
            }
        }
        else {
            sec += add;
            survive = false;
        }
    }
    if(survive) {
        pii s = route.back().finish, f;
        
        switch(d) {
            case 'R':
                f = {L, s.y};
                break;
            case 'L':
                f = {-L, s.y};
                break;
            case 'U':
                f = {s.x, L};
                break;
            case 'D':
                f = {s.x, -L};
                break;
        }
        
        sec += check({s, f});
    }
    
    cout << ++sec;

    return 0;
}