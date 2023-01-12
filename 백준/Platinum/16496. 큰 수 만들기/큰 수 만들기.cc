#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<int> numbers;

int A[10]; int B[10];
int lenA = 0; int lenB = 0;
bool cmp(int a, int b) {
    lenA = 0; lenB = 0;
    
    if(a == 0) { A[0] = 0; lenA = 1;}
    while(a > 0) {
        A[lenA] = a%10;
        lenA++; a /= 10;
    }
    
    if(b == 0) { B[0] = 0; lenB = 1;}
    while(b > 0) {
        B[lenB] = b%10;
        lenB++; b /= 10;
    }
    
    int i = lenA-1; int j = lenB-1;
    while(1) {
        if(i < 0 && j < 0) return (lenA > lenB);
        
        if(i < 0) i = lenA-1;
        if(j < 0) j = lenB-1;
        
        if(A[i] != B[j]) return (A[i] < B[j]);
        
        i--; j--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    bool flag = true;
    while(N--) {
        int v; cin >> v;
        numbers.push_back(v);
        if(v != 0) flag = false;
    }
    
    if(flag) { cout << 0; }
    else {
        sort(numbers.rbegin(), numbers.rend(), cmp);
        
        for(auto &item: numbers) {
            cout << item;
        }
    }

    return 0;
}