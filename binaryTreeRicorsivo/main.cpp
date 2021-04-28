#include <iostream>
#include <vector>

using std::vector;

int binarySearch(vector<int> &A, int left, int right, int x){
    if (right>=left){
        int mid = left + (right-left)/2;

        if (A[mid] == x) return mid;

        if (A[mid] > x) return binarySearch(A, left,mid-1, x);

        return binarySearch(A,mid +1,right,x);
    }
    return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
