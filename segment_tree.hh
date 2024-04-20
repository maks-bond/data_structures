#include <limits>
#include <vector>
#include <algorithm>

// This tree implements max operation.
// Used https://cp-algorithms.com/data_structures/segment_tree.html
template<typename T>
class SegmentTree {
public:
    SegmentTree(std::size_t size_) : size(size_), t(std::vector<T>(4*size_, 0)) {}
    SegmentTree(const std::vector<T> &a) : size(a.size()), t(std::vector<T>(4*size, 0)) {
        build(a, 1, 0, size-1);
    }

    void update(int idx, T val) {
        update(1, 0, size-1, idx, val);
    }

    T max(int l, int r) {
        return max(1, 0, size-1, l, r);
    }

    int upper_bound(int l, int r, T v) {
        return upper_bound(1, 0, size-1, l, r, v);
    }

    int lower_bound(int l, int r, T v) {
        return lower_bound(1, 0, size-1, l, r, v);
    }

    const std::vector<T> &get_array() const {
        return t;
    }

private:
    void build(const std::vector<T> &a, int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl+tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = std::max(t[v*2], t[v*2+1]);
        }
    }

    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = std::max(t[v*2], t[v*2+1]);
        }
    }
    
    T max(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return std::numeric_limits<T>::min();
        }
        if(l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl+tr)/2;
        return std::max(max(v*2, tl, tm, l, std::min(r, tm)), max(v*2+1, tm+1, tr, std::max(l, tm+1), r));
    }

    int upper_bound(int v, int tl, int tr, int l, int r, T x) {
        if(tl > r || tr < l) return -1;
        if(t[v] <= x) return -1;

        if (tl== tr) return tl;

        int tm = tl + (tr-tl)/2;
        int left = upper_bound(2*v, tl, tm, l, r, x);
        if(left != -1) return left;
        return upper_bound(2*v+1, tm+1, tr, l ,r, x);
    }

    int lower_bound(int v, int tl, int tr, int l, int r, T x) {
        if(tl > r || tr < l) return -1;
        if(t[v] < x) return -1;

        if (tl== tr) return tl;

        int tm = tl + (tr-tl)/2;
        int left = lower_bound(2*v, tl, tm, l, r, x);
        if(left != -1) return left;
        return lower_bound(2*v+1, tm+1, tr, l ,r, x);
    }

    std::size_t size;
    std::vector<T> t;
};

// Taken from https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/solutions/1390159/c-python-same-with-longest-increasing-subsequence-problem-clean-concise
int compress(std::vector<int>& arr) { // For example: arr = [1, 9999, 20, 10, 20]
    std::vector<int> uniqueSorted(arr);
    std::sort(uniqueSorted.begin(), uniqueSorted.end());
    uniqueSorted.erase(std::unique(uniqueSorted.begin(), uniqueSorted.end()), uniqueSorted.end()); // Remove duplicated values
    for (int& x : arr) x = lower_bound(uniqueSorted.begin(), uniqueSorted.end(), x) - uniqueSorted.begin() + 1;
    return uniqueSorted.size(); // Result: arr = [1, 4, 3, 2, 3]
}