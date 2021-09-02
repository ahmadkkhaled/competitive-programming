/**
 * for all pairs of elements in the container <lhs, rhs>, if the function returns true, lhs is stored before (precedes) rhs in the ordering of the container
 * let lhs = int 1, rhs = int 5
 * calling cmp(1, 5) returns true, so we expect the ordering of the container to be in this form {..., 1, ..., 5, ...}
 * calling cmp(5, 1) returns false so we also expect the same ordering as shown.
 *
 * usage:
 * stl<type, container<type> (when needed), cmp> _name;
 */
struct cmp{
   bool operator()(const type &lhs, const type &rhs){
       // condition
   }
};

/** priority queue of pair example, note that the final element (successor of all elements) is priority_queue.top()
 * so if we aim to construct a max heap, we use the following comparator, so that greater elements are near the end (the top())
 * and in case of equality, the example uses > operator, so that lesser elements are near the end
 * In other words, if this comparator returns false, lhs is place nearer to top() than rhs.
 *
 * let lhs = int 5, rhs = int 3
 * example cmp(5, 3) returns false (if we use < operator for comparison)
 * therefore 5 is placed near top()
 */
struct cmp{
    bool operator()(const pair<int,int> &lhs, const pair<int, int> &rhs){
        int lh = lhs.second - lhs.first;
        int rh = rhs.second - rhs.first;
        if(lh != rh) return lh < rh;
        return lhs.first > rhs.first;
    }
};

