/**
 * // This is the interface for NestedInteger.
 * // You should not implement it, or speculate about its implementation.
 * class NestedInteger {
 *   public:
 *     bool isInteger() const;
 *     int getInteger() const;
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> flat;  // store flattened list
    int index = 0;

    // helper function to flatten nested list
    void flatten(const vector<NestedInteger> &nestedList) {
        for (auto &n : nestedList) {
            if (n.isInteger()) {
                flat.push_back(n.getInteger());
            } else {
                flatten(n.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    int next() {
        return flat[index++];
    }

    bool hasNext() {
        return index < flat.size();
    }
};
