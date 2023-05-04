#include <iostream>
#include <cmath>
#include <vector>
#include <complex>

using namespace std;

typedef complex<double> comp;
const double PI = 3.14159265358979323846;

void FFT(vector<comp> &a, comp w) {
    int n = a.size();
    if(n == 1)
        return;
        
    vector<comp> even(n/2), odd(n/2);
    for(int i = 0; i < n; i++) {
        if(i%2) {
            odd[i/2] = a[i];
        }
        else {
            even[i/2] = a[i];
        }
    }
    
    FFT(even, w*w); FFT(odd, w*w);
    
    comp t(1, 0);
    for(int i = 0; i < n/2; i++) {
        a[i] = even[i] + t*odd[i];
        a[i+n/2] = even[i] - t*odd[i];
        t *= w;
    }
}

vector<comp> polyMulti(vector<comp> a, vector<comp> b) {
    vector<comp> result(262144);
    
    comp w(cos(2*PI/262144), sin(2*PI/262144));
    FFT(a, w); FFT(b, w);
    
    for(int i = 0; i < 262144; i++) {
        result[i] = a[i]*b[i];
    }
    
    comp e(1, 0);
    FFT(result, e/w);
    for(int i = 0; i < 262144; i++) {
        result[i] /= comp(262144, 0);
        result[i] = comp(round(result[i].real()), round(result[i].imag()));
    }
    
    return result;
}

int main()
{
    int N;
    vector<comp> a(262144);
    vector<comp> b(262144);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        double value;
        cin >> value;
        a[i] = comp(value, 0);
        a[N+i] = comp(value, 0);
    }
    
    for(int i = N-1; i >= 0; i--) {
        double value;
        cin >> value;
        b[i] = comp(value, 0);
    }
    
    vector<comp> c = polyMulti(a, b);
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(ans < c[N-1+i].real())
            ans = c[N-1+i].real();
    }
    
    cout << ans;

    return 0;
}