/*
 * Connor Steed (crs268)
 * Data Structures and Algorithms
 * Assignment 3 - mergeSort
 * 10/25/2018
 */

#include <iostream>
using namespace std;

// Merges two sorted subarrays of A[].
// First sorted subarray is A[l..m].
// Second sorted subarray is A[m+1..r].
// You might want to call this function in function mergeSort().
void merge(int A[], int l, int m, int r)
{
    int nL = m - l + 1;
    int nR = r - m;
    int L[nL];
    int R[nR];

    //populate L and R arrays
    for (int n = 0; n < nL; n++) {
        L[n] = A[l + n];
    }
    for (int n = 0; n < nR; n++) {
        R[n] = A[m + n + 1];
    }

    //Merge L and R into A
    int i, j = 0;
    int k = l;
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    //add the rest of L to A
    while(i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    //add the rest of R to A
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// using mergeSort to sort sub-array A[l..r]
// l is for left index and r is right index of the
// sub-array of A[] to be sorted
void mergeSort(int A[], int l, int r)
{
    if (l < r) {
        int middle = (l + r) / 2;

        mergeSort(A, l, middle);
        mergeSort(A, middle + 1, r);

        merge(A, l, middle, r);
    }
}


int main()
{
    cout << "Please enter the length (number of elements) of the input array: ";
    int n;
    cin >> n;

    if(n <= 0) {
        cout << "Illegal input array length!" << endl;
        return 0;
    }

    int* A = new int [n];

    cout << "Please enter each element in the array" << endl;
    cout << "(each element must be an integer within the range of int type)." << endl;
    for(int i=0; i<n; i++) {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    cout << "Given array A[] is: ";
    for(int i=0; i<n-1; i++)
        cout << A[i] << ",";
    cout << A[n-1] << endl;

    mergeSort(A, 0, n-1);

    cout << "After quickSort, sorted array A[] is: ";
    for(int i=0; i<n-1; i++)
        cout << A[i] << ",";
    cout << A[n-1] << endl;


    delete [] A;
    return 0;
}
