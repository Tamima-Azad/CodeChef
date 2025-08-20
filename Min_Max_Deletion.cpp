#include<bits/stdc++.h>
using namespace std;

long long getMin(long long a, long long b) {
    return (a < b) ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, Q;
        cin >> N >> Q;

        vector<long long> A(N + 2, 0); 

        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }

        long long score = 0;
        for (int i = 1; i < N; i++) {
            score += getMin(A[i], A[i + 1]);
        }

        while (Q--) {
            int idx;
            long long X;
            cin >> idx >> X;

            if (idx > 1) score -= getMin(A[idx - 1], A[idx]);
            if (idx < N) score -= getMin(A[idx], A[idx + 1]);

            A[idx] = X;

            if (idx > 1) score += getMin(A[idx - 1], A[idx]);
            if (idx < N) score += getMin(A[idx], A[idx + 1]);

            cout << score << '\n';
        }
    }

    return 0;
}
