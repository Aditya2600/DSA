#include<iostream>
#include <vector>
using namespace std;
vector<int> st;
vector<int> lazy;
void buildTree(int arr[], int i, int lo, int hi){
    if(lo == hi){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(arr, 2*i+1, lo, mid);
    buildTree(arr, 2*i+2, mid+1, hi);
    st[i] = st[2*i+1] + st[2*i+2];
}
int getSum(int i, int lo, int hi, int l, int r){
    if(lazy[i]!=0){
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize * lazy[i];
        if(lo!=hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
}
if(l>hi || r<lo) return 0;
if(lo>=l && r>=hi) return st[i];
int mid = lo + (hi-lo)/2;
int leftSum = getSum(2*i+1, lo, mid, l, r);
int rightSum = getSum(2*i+2, mid+1, hi, l, r);
return leftSum + rightSum;
}
void updateRange(int i, int lo, int hi, int l, int r, int val){
    if(lazy[i] != 0){
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize * lazy[i];
        if(lo!=hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(l>hi || r<lo) return;
    if(lo>=l && hi<=r){
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize * val;
        if(lo != hi){
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    } 
    int mid = lo + (hi-lo)/2;
    updateRange(2*i+1, lo, mid, l, r, val);
    updateRange(2*i+2, mid+1, hi, l, r, val);
    st[i] = st[2*i+1] + st[2*i+2];
}
