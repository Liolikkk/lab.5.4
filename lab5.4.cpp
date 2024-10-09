#include <iostream>
#include <cmath>

using namespace std;

double P0(const int N) {
    double p = 1;
    for (int i = N; i <= 10; i++) {
        p *= (i + 1.0 / (i * i)) / sqrt(1 + exp(i));
    }
    return p;
}

double P1(const int i, const int N) {
    if (i > 10)
        return 1;
    else
        return ((i + 1.0 / (i * i)) / sqrt(1 + exp(i))) * P1(i + 1, N);
}

double P2(const int i, const int N) {
    if (i < N)
        return 1;
    else
        return ((i + 1.0 / (i * i)) / sqrt(1 + exp(i))) * P2(i - 1, N);
}

double P3(const int i, const int N, double t) {
    t *= (i + 1.0 / (i * i)) / sqrt(1 + exp(i));
    if (i >= 10)
        return t;
    else
        return P3(i + 1, N, t);
}

double P4(const int i, const int N, double t) {
    t *= (i + 1.0 / (i * i)) / sqrt(1 + exp(i));
    if (i <= N)
        return t;
    else
        return P4(i - 1, N, t);
}

int main() {
    int N;
    cout << "N = "; cin >> N;

    if (N > 10) {
        cout << "N повинно бути не більше 10!" << endl;
        return 1;
    }

    cout << "(iter) P0 = " << P0(N) << endl;
    cout << "(rec up ++) P1 = " << P1(N, N) << endl;
    cout << "(rec down --) P2 = " << P2(10, N) << endl;
    cout << "(rec up ++) P3 = " << P3(N, 10, 1) << endl;
    cout << "(rec down --) P4 = " << P4(10, N, 1) << endl;

    return 0;
}
