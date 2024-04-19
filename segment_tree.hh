#include <limits>
#include <vector>

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

    std::size_t size;
    std::vector<T> t;
};