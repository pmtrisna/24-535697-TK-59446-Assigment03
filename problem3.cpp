#include <iostream>
using namespace std;


// O(n)
int linearSearch(int* arr, int n, int target) {

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}


// O(log n)
int binarySearch(int* arr, int n, int target) {

    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {

        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            lo = mid + 1;

        else
            hi = mid - 1;
    }

    return -1;
}


// O(n)
int* generateSortedArray(int n) {

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = 2 * i;   // contoh: 0,2,4,6,...
    }

    return arr;
}



int main() {

    int sizes[3] = {10, 100, 1000};

    for (int s = 0; s < 3; s++) {

        int n = sizes[s];

        cout << "Array size = " << n << endl;

        int* arr = generateSortedArray(n);

        // Target yang ADA (midpoint)
        int targetExist = arr[n / 2];

        int indexLinear = linearSearch(arr, n, targetExist);
        int indexBinary = binarySearch(arr, n, targetExist);

        cout << "Search existing value (" << targetExist << ")" << endl;
        cout << "Linear Search index : " << indexLinear << endl;
        cout << "Binary Search index : " << indexBinary << endl;

        if (indexLinear == indexBinary)
            cout << "Result: OKE\n";
        else
            cout << "Result: NOT OKE\n";


        cout << endl;


        // Target yang TIDAK ADA
        int targetNotExist = -1;

        indexLinear = linearSearch(arr, n, targetNotExist);
        indexBinary = binarySearch(arr, n, targetNotExist);

        cout << "Search non-existing value (" << targetNotExist << ")" << endl;
        cout << "Linear Search index : " << indexLinear << endl;
        cout << "Binary Search index : " << indexBinary << endl;

        if (indexLinear == indexBinary)
            cout << "Result: OKE\n";
        else
            cout << "Result: NOT OKE\n";

        cout << "-----------------------------\n";

        delete[] arr;
    }

    return 0;
}
