#include "bits/stdc++.h"
using namespace std;
 
typedef int64_t ll;
 
enum Type {
    ADD,
    SUB,
    DIV,
    MUL,
    INT
};
 
typedef struct {
    Type type;
    int data;
} operation;
 
typedef struct node {
    node* l;
    node* r;
    operation op;
} node;
 
int eval(node* n, int* parens, bool* valid) {
    int l, r;
    if (n->op.type != INT) {
        l = eval(n->l, parens, valid);
        r = eval(n->r, parens, valid);
    }
    Type type;
    switch (n->op.type) {
        case ADD:
            return l + r;
        case SUB:
            return l - r;
        case DIV:
            if (r == 0 || l % r != 0) {
                *valid = false;
                return 0;
            }
            type = n->l->op.type;
            if (type == ADD || type == SUB) (*parens)++;
            type = n->r->op.type;
            if (type != INT) (*parens)++;
 
            return l / r;
        case MUL:
            type = n->l->op.type;
            if (type == ADD || type == SUB) (*parens)++;
            type = n->r->op.type;
            if (type == ADD || type == SUB) (*parens)++;
 
            return l * r;
        case INT:
            return n->op.data;
    }
}
 
int assign_ops(node* n, int seed, int* idx) {
    if (n->op.type == INT) return 0;
 
    Type ops[4] = {ADD,SUB,MUL,DIV};
 
    int tmp = seed;
    for (int i = 0; i < *idx; i++) tmp /= 4;
    assert(*idx < 3);
    n->op.type = ops[tmp % 4];
    (*idx)++;
 
    int ret = 1;
    ret += assign_ops(n->l, seed, idx);
    ret += assign_ops(n->r, seed, idx);
    return ret;
}
 
int assign(node* n, int* xs, int* idx) {
    if (n->op.type == INT) {
        n->op.data = xs[*idx];
        (*idx)++;
        return 1;
    }
 
    return assign(n->l, xs, idx) + assign(n->r, xs, idx);
}
 
node* clone(node* n) {
    node* ret = new node();
    ret->op.type = n->op.type;
    if (n->op.type == INT) {
        ret->op.data = n->op.data;
    } else {
        ret->l = clone(n->l);
        ret->r = clone(n->r);
    }
    return ret;
}
 
node* get_int(int n = 0);
 
node* get_int(int n) {
    node* ret = new node();
    ret->op.type = INT;
    ret->op.data = n;
 
    return ret;
}
 
node* pp(node* n, int depth = 0);
 
node* pp(node* n, int depth) {
    string pad = "";
    for (int i = 0; i < depth; i++) pad += " ";
    if (n->op.type == INT) {
        cout << pad << n->op.data << endl;
    } else {
        const char* names[4] = { "ADD", "SUB", "DIV", "MUL" };
 
        pp(n->l, depth + 1);
        cout << pad << names[n->op.type] << endl;
        pp(n->r, depth + 1);
    }
}
 
int inversions(int* a, int* b) {
    int tot = 0;
    for(int i = 0; i < 4; i++) {
        int j = i;
        while(b[j] != a[i]) j++;
        for(int k = j; k > i; k--) {
            swap(b[k], b[k-1]);
            if(b[k] != b[k-1]) tot++;
        }
    }
    return 2*tot; 
}
 
int main() {
    int a[4] = {1, 2, 2, 2};
    int b[4] = {2, 2, 2, 1};
    //cout << inversions(a, b) << endl;
 
    node* dbl = new node();
    dbl->l = get_int();
    dbl->r = get_int();
 
    node* trip1 = new node();
    trip1->l = get_int();
    trip1->r = clone(dbl);
    node* trip2 = new node();
    trip2->l = clone(dbl);
    trip2->r = get_int();
 
    node nodes[5];
    nodes[0].l = clone(dbl);
    nodes[0].r = clone(dbl);
    nodes[1].l = get_int();
    nodes[1].r = clone(trip1);
    nodes[2].l = get_int();
    nodes[2].r = clone(trip2);
    nodes[3].l = clone(trip1);
    nodes[3].r = get_int();
    nodes[4].l = clone(trip2);
    nodes[4].r = get_int();
 
    ll BAD = 1000000000;
 
    int nums[4];
    for (int i = 0; i < 4; i++) cin >> nums[i];
 
    int ori[4];
    memcpy(ori, nums, sizeof(nums));
    sort(nums, nums + 4);
 
    ll best = BAD;
    for (int i = 0; i < 24; i++) {
        next_permutation(nums, nums + 4);
        for (int i = 0; i < 5; i++) {
            node* n = &nodes[i];
            for (int j = 0; j < 4 * 4 * 4; j++) {
                int idx = 0;
                assert(assign_ops(n, j, &idx) == 3);
                assert(idx == 3);
                idx = 0;
                
                assert(assign(n, nums, &idx) == 4);
 
                bool valid = true;
                int parens = 0;
                int ret = eval(n, &parens, &valid);
                
                if (valid && ret == 24) {
                    int* a = (int*) malloc(100);
                    int* b = (int*) malloc(100);
                    memcpy(a, ori, sizeof(ori));
                    memcpy(b, nums, sizeof(nums));
                    ll score = parens + inversions(a, b);
                    if (score < best) {
    #if 0
                    cout << endl;
                    cout << i << ", " << j << endl;
                    pp(n);
    #endif
                    best = min(best, score);
                    }
                }
            }
        }
    }
     
    if (best == BAD) cout << "impossible";
    else cout << best;
    cout << endl;
    
    return 0;
}
