#include <vector>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

using matrix = vector<vector<bool>>;

matrix read_input(int &N, int &K) {
    cin >> N >> K;
    matrix m;
    for (unsigned i = 0; i < N; ++i) {
        m.push_back(vector<bool>());
        for (unsigned j = 0; j < N; ++j) {
            char c;
            cin >> c;
            m[i].push_back(c == 'o');
        }
    }
    assert(m.size() == N);
    assert(m.back().size() == N);
    return m;
}

void negate_row(matrix &m, unsigned row) {
    vector<bool> &r = m[row];
    for (unsigned i = 0; i < r.size(); ++i) {
        r[i] = not r[i];
    }
}

void negate_col(matrix &m, unsigned col) {
    for (auto &r : m) {
        r[col] = not r[col];
    }
}

void negate(matrix &m, unsigned row, unsigned col) {
    m[row][col] = not m[row][col];
}

string print(matrix &m) {
    string s;
    for (const auto &r : m) {
        for (const bool b : r) {
            s += b ? 'o' : 'x';
        }
        s += '\n';
    }
    return s;
}

unsigned count_ones_row(matrix &m, unsigned row) {
    unsigned c = 0;
    auto &r = m[row];
    for (int i = 0; i < r.size(); ++i) {
        if (r[i]) {
            ++c;
        }
    }
    return c;
}

unsigned count_ones_col(matrix &m, unsigned col) {
    unsigned c = 0;
    for (int i = 0; i < m.size(); ++i) {
        if (m[i][col]) {
            ++c;
        }
    }
    return c;
}

matrix stupid_algorithm(matrix m) {
    auto N = m.size();
    auto threshold = N / 2;
    bool negated_something;
    do {
        negated_something = false;
        for (int i = 0; i < N; ++i) {
            if (count_ones_row(m, i) > threshold) {
                negate_row(m, i);
                negated_something = true;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (count_ones_col(m, i) > threshold) {
                negate_col(m, i);
                negated_something = true;
            }
        }
    } while (negated_something);
    return m;
}

int main() {
    int N, K;
    matrix m {read_input(N, K)};
    
    matrix m1 = stupid_algorithm(m);
    cout << print(m1);
}
