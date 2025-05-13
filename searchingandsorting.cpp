#include <iostream>
using namespace std;

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], 
        j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Merge Sort Helpers
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1, n2 = high - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[low + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Quick Sort Helpers
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Fibonacci Search
int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0, fib1 = 1, fib = fib2 + fib1;
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;
    while (fib > 1) {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else return i;
    }
    if (fib1 && offset + 1 < n && arr[offset + 1] == x)
        return offset + 1;
    return -1;
}

// Display Array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], original[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        original[i] = arr[i]; // to restore unsorted data
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Binary Search\n";
        cout << "6. Fibonacci Search\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        // Reset array before each sort to original
        for (int i = 0; i < n; i++) arr[i] = original[i];

        switch (choice) {
        case 1:
            insertionSort(arr, n);
            cout << "Sorted using Insertion Sort: ";
            printArray(arr, n);
            break;
        case 2:
            bubbleSort(arr, n);
            cout << "Sorted using Bubble Sort: ";
            printArray(arr, n);
            break;
        case 3:
            mergeSort(arr, 0, n - 1);
            cout << "Sorted using Merge Sort: ";
            printArray(arr, n);
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            cout << "Sorted using Quick Sort: ";
            printArray(arr, n);
            break;
        case 5: {
            int target;
            cout << "Enter element to search: ";
            cin >> target;
            insertionSort(arr, n); // sort before binary search
            int index = binarySearch(arr, n, target);
            if (index != -1)
                cout << "Element found at index " << index << ".\n";
            else
                cout << "Element not found.\n";
            break;
        }
        case 6: {
            int target;
            cout << "Enter element to search: ";
            cin >> target;
            insertionSort(arr, n); // sort before fibonacci search
            int index = fibonacciSearch(arr, n, target);
            if (index != -1)
                cout << "Element found at index " << index << ".\n";
            else
                cout << "Element not found.\n";
            break;
        }
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
