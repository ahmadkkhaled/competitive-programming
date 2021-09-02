#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sof(v) (int)v.size()

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v) {
    for(const T &val: v)
        os << val << ' ';
    return os;
}

int current_case;

void run_case() {

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    for (current_case = 1; current_case <= test_cases; current_case++)
        run_case();
}