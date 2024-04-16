#include <vector>
#include <iostream>

// Used https://cp-algorithms.com/data_structures/fenwick.html
// And https://www.youtube.com/watch?v=uSFzHCZ4E-8&ab_channel=StableSort
template <typename T>
class FenwickTree {
public:
    FenwickTree(int n) {
        bit.resize(n+1);
    }

    // TODO: Improve this constructor with O(n) approach.
    FenwickTree(const std::vector<T> &v) {
        for(int i = 0; i<v.size(); ++i) {
            add(i, v[i]);
        }
    }

    T sum(int idx) {
        // Move into 1-based system.
        idx = idx+1;

        T res = 0;
        while(idx > 0) {
            res+=bit[idx];
            idx -= idx & (-idx);
        }
        return res;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int idx, int delta) {
        // Move into 1-based system.
        idx = idx+1;

        int n = static_cast<int>(bit.size());
        while(idx < n) {
            bit[idx]+=delta;
            idx += idx & (-idx);
        }
    }

private:
    std::vector<T> bit;
};