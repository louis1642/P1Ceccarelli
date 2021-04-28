#include <iostream>
#include <vector>

using std::vector;

int binarySearch(vector<int> &A, int num){
    int n = A.size();
    int left = 0;
    int right = n-1;

    while (left<=right){
        int mid = (right+left)/2;
        if (A[mid] == num){
            return mid;
        }
        if (A[mid]<num){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
