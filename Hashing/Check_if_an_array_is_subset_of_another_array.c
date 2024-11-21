//[Naive approach] Using Nested Loops – O(m*n) time and O(1) auxiliary space
#include <stdio.h>
#include <stdbool.h>

// Checks if an array is a subset of another array.
bool isSubset(int arr1[], int arr2[], int m, int n) {
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (arr2[i] == arr1[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, arr2, m, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}


//[Optimized Approach] Using Sorting & Two Pointers – O(m log m + n log n) time and O(1) auxiliary Space
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if arr2 is a subset of arr1
bool isSubset(int* arr1, int size1, int* arr2, int size2) {
    // Sort both arrays
    qsort(arr1, size1, sizeof(int), compare);
    qsort(arr2, size2, sizeof(int), compare);

    int i = 0, j = 0;

    // Traverse both arrays using two pointers
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] == arr2[j]) {
            i++;
            j++;
        } else {
            // If element in arr2 is not found in arr1
            return false;
        }
    }

    // If we have traversed all elements in arr2, it is a subset
    return (j == size2);
}

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, size1, arr2, size2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}



//[Expected Approach] Using Hashing – O(m + n) time and O(m) auxiliary space
#include <stdio.h>
#include <stdbool.h>

#define HASH_SIZE 100003

int hashTable[HASH_SIZE];

// Hash function
int hashFunction(int key) {
    return key % HASH_SIZE;
}

// Insert element into hash table
void insert(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % HASH_SIZE;
    }
    hashTable[index] = key;
}

// Search for an element in hash table
bool search(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return true;
        }
        index = (index + 1) % HASH_SIZE;
    }
    return false;
}

// Function to check if arr2 is a subset of arr1
bool isSubsetUsingHashing(const int* arr1, int size1, const int* arr2, int size2) {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = -1;
    }
    for (int i = 0; i < size1; i++) {
        insert(arr1[i]);
    }
    for (int i = 0; i < size2; i++) {
        if (!search(arr2[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[] = {1, 2, 3, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubsetUsingHashing(arr1, size1, arr2, size2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

