#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string S, T;
        cin >> S >> T;

        vector<int> ops;
        for (int i = 0; i < N - 1; ++i) {
            if (S[i] != T[i]) {
                if (S[i] == '1') {
                    S[i + 1] = (S[i + 1] == '0') ? '1' : '0';
                    ops.push_back(i + 1); // store 1-based index
                } else {
                    // Try to make S[i] == '1' by backtracking
                    bool found = false;
                    for (int j = i - 1; j >= 0; --j) {
                        if (S[j] == '1') {
                            // Flip forward up to i
                            for (int k = j; k < i; ++k) {
                                S[k + 1] = (S[k + 1] == '0') ? '1' : '0';
                                ops.push_back(k + 1);
                            }
                            // Now we are like in original '1' case
                            S[i + 1] = (S[i + 1] == '0') ? '1' : '0';
                            ops.push_back(i + 1);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << -1 << endl;
                        goto next_case;
                    }
                }
            }
        }

        // Finally, check last bit
        if (S[N - 1] != T[N - 1]) {
            cout << -1 << endl;
        } else {
            cout << ops.size() << endl;
            for (int x : ops) cout << x << " ";
            if (!ops.empty()) cout << endl;
        }

    next_case:;
    }

    return 0;
}
