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

struct fishbowl {
    int fish, del;
};

int N, K; 
fishbowl arr[100][100];
int i, j, h;

void cleaningAir() {
    i = 0, j = 1, h = 0;
    
    for(int r = 1; r < 100; r++) {
        for(int c = 0; c < 100; c++) arr[r][c] = {0, 0};
    }
}

void propagate() {
    for(int i = 0; i < N; i++) {
        arr[0][i].fish += arr[0][i].del;
        arr[0][i].del = 0;
    }
}

bool check() {
    int minV = 1'000'000'000, maxV = 0;
    
    for(int i = 0; i < N; i++) {
        minV = min(minV, arr[0][i].fish);
        maxV = max(maxV, arr[0][i].fish);
    }
    
    return maxV-minV <= K;
}

void addFish() {
    int minV = 1'000'000'000;
    for(int i = 0; i < N; i++) minV = min(minV, arr[0][i].fish);
    for(int i = 0; i < N; i++) arr[0][i].fish += (arr[0][i].fish == minV);
}

void levitation1() {
    while(1) {
        if(j >= N || N-j <= h) break;
        
        for(int r = 0; r <= h; r++) {
            for(int c = i; c < j; c++) {
                arr[j-c][j+r] = arr[r][c];
            }
        }
        
        h = j-i;
        i = j;
        while(j < N && arr[1][j].fish > 0) j++;
    }
}

void levitation2() {
    for(int i = 0; i < N/2; i++) {
        arr[1][N-1-i] = arr[0][i];
    }
    
    for(int r = 0; r < 2; r++) {
        for(int c = 0; c < N/4; c++) {
            arr[3-r][N-1-c] = arr[r][N/2+c];
        }
    }
    
    i = 3*N/4; j = N; h = 3;
}

void movefish() {
    for(int c = i; c < N; c++) {
        for(int r = 0; r < h; r++) {
            if(arr[r+1][c].fish == 0) break;
            
            int d = arr[r+1][c].fish-arr[r][c].fish;
            
            if(d > 0) {
                arr[r][c].del += d/5;
                arr[r+1][c].del -= d/5;
            }
            else {
                arr[r][c].del -= (-d)/5;
                arr[r+1][c].del += (-d)/5;
            }
        }
    }
    
    for(int r = 0; r <= h; r++) {
        for(int c = i; c < N-1; c++) {
            if(arr[r][c+1].fish == 0) break;
            
            int d = arr[r][c+1].fish-arr[r][c].fish;
            
            if(d > 0) {
                arr[r][c].del += d/5;
                arr[r][c+1].del -= d/5;
            }
            else {
                arr[r][c].del -= (-d)/5;
                arr[r][c+1].del += (-d)/5;
            }
        }
    }
}

void alignFishbowl() {
    vector<fishbowl> temp;
    
    for(int c = i; c < N; c++) {
        for(int r = 0; r <= h; r++) {
            if(arr[r][c].fish == 0) break;
            temp.push_back(arr[r][c]);
        }
    }
    
    for(int i = 0; i < N; i++) {
        arr[0][i] = temp[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        arr[0][i] = {v, 0};
    }
    
    int ans = 0;
    while(1) {
        if(check()) break;
        
        cleaningAir();
        addFish();
        levitation1();
        movefish();
        alignFishbowl();
        propagate();
        
        cleaningAir();
        levitation2();
        movefish();
        alignFishbowl();
        propagate();
        
        ans++;
    }
    
    cout << ans;

    return 0;
}