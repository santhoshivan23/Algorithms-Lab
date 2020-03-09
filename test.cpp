#include <iostream>
using namespace std;
int maxsimum(int a[], int l, int r) {
    if (l == r)
        return a[l];
    int m = (l+r)/2;
    int u = maxsimum(a,l,m);
    int v = maxsimum(a,m+1,r);
    return u>v?u:v;
}

int main() {
    int a[] = {34,23,45,56,30,31,57,33,55,10};
    int n = sizeof(a)/sizeof(int);
    cout << maxsimum(a,0,n-1) << endl;
    return 0;
}
