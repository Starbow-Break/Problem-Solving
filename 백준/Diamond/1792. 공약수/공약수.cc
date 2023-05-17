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

int muSum[50'001];

bool isPrime[50'001];
vector<int> primes;
void getPrimes() {
    fill(isPrime+2, isPrime+50'001, true);
    
    for(int i = 2; i <= 50'000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= 50'000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void getMuSum() {
    muSum[0] = 0;
    
    fill(muSum+1, muSum+50'001, 1);
    for(auto &p: primes) {
        for(int i = p; i <= 50000; i += p) {
            if(i%(1LL*p*p) == 0) muSum[i] = 0;
            else muSum[i] *= -1;
        }
    }
    
    for(int i = 1; i <= 50'000; i++) muSum[i] += muSum[i-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    getMuSum();
    
    int n; cin >> n;
    while(n--) {
        int a, b, d; cin >> a >> b >> d;
        
        vector<int> vecA, vecB;
        vecA.push_back(0); vecB.push_back(0);
        
        for(int k = 1; a/d < 1LL*(a/d/k)*(a/d/k+1); k++) {vecA.push_back(a/d/k);}
        for(int i = 1; a/d >= i*(i+1); i++) {vecA.push_back(i);}
        
        for(int k = 1; b/d < 1LL*(b/d/k)*(b/d/k+1); k++) {vecB.push_back(b/d/k);}
        for(int i = 1; b/d >= i*(i+1); i++) {vecB.push_back(i);}
        
        sort(vecA.begin(), vecA.end()); sort(vecB.begin(), vecB.end());
        
        int idxA = 0, idxB = 0;
        ll ans = 0;
        while(idxA < vecA.size()-1 && idxB < vecB.size()-1) {
            int s = max(vecA[idxA], vecB[idxB])+1;
            int f = min(vecA[idxA+1], vecB[idxB+1]);
            
            ans += 1LL*(muSum[f]-muSum[s-1])*(a/d/vecA[idxA+1])*(b/d/vecB[idxB+1]);
            
            if(vecA[idxA+1] > vecB[idxB+1]) idxB++;
            else if(vecA[idxA+1] < vecB[idxB+1]) idxA++;
            else {idxA++; idxB++;}
        }
        
        cout << ans << '\n';
    }

    return 0;
}