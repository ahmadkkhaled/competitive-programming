#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

/**
 * use policy_set<pair> for multi_set
 * order_of_key(k) number of elements strictly smaller than k
 * find_by_order(k) returns iterator to the largest k
 */
template <typename T>
using policy_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

