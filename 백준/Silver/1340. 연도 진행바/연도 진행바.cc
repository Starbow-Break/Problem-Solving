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

int calcTotal(int y) {
    bool check;
    if(y%4) {
        check = false;
    }
    else {
        if(y%100) {
            check = true;
        }
        else {
            if(y%400) {
                check = false;
            }
            else {
                check = true;
            }
        }
    }
    
    return (365+check)*24*60;
}

int calcMin(int y, int m, int d, int h, int min) {
    bool check;
    if(y%4) {
        check = false;
    }
    else {
        if(y%100) {
            check = true;
        }
        else {
            if(y%400) {
                check = false;
            }
            else {
                check = true;
            }
        }
    }
    
    int day = 0;
    for(int i = 1; i < m; i++) {
        switch(i) {
            case 2:
            day += 28+check;
            break;
            case 4:
            case 6:
            case 9:
            case 11:
            day += 30;
            break;
            default:
            day += 31;
        }
    }
    
    day += d-1;
    return day*24*60+h*60+min;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string date;
    getline(cin, date);
    
    string data[5];
    int idx = 0; string cur = "";
    for(auto &c: date) {
        if(c == ' ' || c == ',' || c == ':') {
            if(cur != "") {
                data[idx] = cur;
                cur = "";
                idx++;
            }
        }
        else {
            cur += c;
        }
    }
    data[idx] = cur;
    
    // for(int i = 0; i < 5; i++) cout << data[i] << '\n';
    
    int month, day, year, hour, minute;
    string monthName[12] = {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };
    
    for(int i = 0; i < 12; i++) {
        if(data[0] == monthName[i]) {
            month = i+1;
            break;
        }
    }
    
    for(int i = 1; i <= 4; i++) {
        int v = 0;
        for(auto &c: data[i]) {
            v = v*10+(c-'0');
        }
        switch(i) {
            case 1:
            day = v;
            break;
            case 2:
            year = v;
            break;
            case 3:
            hour = v;
            break;
            case 4:
            minute = v;
        }
    }
    
    int totalMin = calcTotal(year);
    int curMin = calcMin(year, month, day, hour, minute);
    
    cout << fixed << setprecision(12) << (double)curMin/totalMin*100;
    
    return 0;
}
