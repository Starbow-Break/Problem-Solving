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

string tileList[34] = {
    "1s", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s",
    "1t", "2t", "3t", "4t", "5t", "6t", "7t", "8t", "9t",
    "1m", "2m", "3m", "4m", "5m", "6m", "7m", "8m", "9m",
    "e", "w", "s", "n", "h", "b", "j"
};

bool isThirteenOrphans(vector<string> &tiles) {
    map<string, int> mp;
    
    for(auto &tile: tiles) {
        if('2' <= tile[0] && tile[0] <= '8') return false;
        auto t = mp.find(tile);
            
        if(t == mp.end()) {
            mp.insert({tile, 1});
        }
        else {
            if(t->second >= 2) return false;
            (t->second)++;
        }
    }
    
    return mp.size() == 13;
}

bool isSevenHeads(vector<string> &tiles) {
    map<string, int> mp; bool flag = true;
    
    for(auto &tile: tiles) {
        auto t = mp.find(tile);
        
        if(t == mp.end()) {
            mp.insert({tile, 1});
        }
        else {
            if(t->second >= 2) return false;
            (t->second)++;
        }
        
        if(mp.size() > 7) return false;
    }
    
    return true;
}

int temp[10];
int check(int start, bool head) {
    int ret = -1;
    
    for(int i = start; i <= 9; i++) {
        if(temp[i]) {
            if(temp[i] >= 3) {
                temp[i] -= 3;
                ret = max(ret, check(i, head));
                temp[i] += 3;
            }
            if(!head && temp[i] >= 2) {
                temp[i] -= 2;
                ret = max(ret, check(i, true));
                temp[i] += 2;
            }
            if(i <= 7 && temp[i] && temp[i+1] && temp[i+2]) {
                int cnt = 0;
                while(temp[i] && temp[i+1] && temp[i+2]) {
                    temp[i]--; temp[i+1]--; temp[i+2]--; cnt++;
                }
                ret = max(ret, check(i, head));
                while(cnt > 0) {
                    temp[i]++; temp[i+1]++; temp[i+2]++; cnt--;
                }
            }
            
            return ret;
        }
    }
    
    return !head;
}

bool isCompleted(vector<string> &tiles) {
    int cntS[10] = {0, }, cntT[10] = {0, }, cntM[10] = {0, };
    vector<string> wordTiles;
    
    for(auto &tile: tiles) {
        if(tile.length() == 1) wordTiles.push_back(tile);
        else {
            if(tile[1] == 's') cntS[tile[0]-'0']++;
            if(tile[1] == 't') cntT[tile[0]-'0']++;
            if(tile[1] == 'm') cntM[tile[0]-'0']++;
        }
    }
    sort(wordTiles.begin(), wordTiles.end());
    
    bool head = false; string cur = ""; int cnt = 0;
    for(auto &wt: wordTiles) {
        if(cur == wt) cnt++;
        else {
            cur = wt;
            if(cnt == 2) {
                if(head) return false;
                head = true;
            }
            else if(cnt == 1 || cnt == 4) return false;
            cnt = 1;
        }
    }
    if(cnt == 2) {
        if(head) return false;
        head = true;
    }
    else if(cnt == 1 || cnt == 4) return false;
    
    int res;
    for(int i = 1; i <= 9; i++) temp[i] = cntS[i];
    res = check(1, head);
    if(res == -1) return false;
    if(res == 0) head = true;
    
    for(int i = 1; i <= 9; i++) temp[i] = cntT[i];
    res = check(1, head);
    if(res == -1) return false;
    if(res == 0) head = true;
    
    for(int i = 1; i <= 9; i++) temp[i] = cntM[i];
    res = check(1, head);
    if(res == -1) return false;
    if(res == 0) head = true;
    
    return true;
}

bool isSelfPickTile(vector<string> _tiles, string tile) {
    vector<string> tiles = _tiles;
    tiles.push_back(tile);
    
    //국사무쌍 체크
    if(isThirteenOrphans(tiles)) return true;
    //치또이츠 체크
    if(isSevenHeads(tiles)) return true;
    //특수한 경우를 제외하고 유효한 조합인지 체크
    if(isCompleted(tiles)) return true;
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<string> tiles, ans;
    map<string, int> mp;
    for(int i = 0; i < 13; i++) {
        string tile; cin >> tile;
        tiles.push_back(tile);
        
        auto t = mp.find(tile);
        
        if(t == mp.end()) mp.insert({tile, 1});
        else (t->second)++;
    }
    
    for(auto &tile: tileList) {
        auto t = mp.find(tile);
        if(t != mp.end() && t->second == 4) continue;
        
        if(isSelfPickTile(tiles, tile)) {
            ans.push_back(tile);
        }
    }
    
    if(ans.empty()) cout << "no tenpai";
    else {
        cout << "tenpai" << '\n';
        cout << ans.size() << '\n';
        sort(ans.begin(), ans.end());
        for(auto &t : ans) cout << t << ' ';
    }

    return 0;
}