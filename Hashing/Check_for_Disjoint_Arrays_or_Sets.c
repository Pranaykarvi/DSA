//[Naive Approach] Using Two Nested Loops – O(n x m) Time and O(1) Space

// C program to check if the given arrays are disjoint
// using two nested loops

#include <stdio.h>

int areDisjoint(int a[], int n, int b[], int m) {
    
    // Take every element of array a 
    // and search it in array b
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            // If any common element is found
            // given arrays are not disjoint
            if(a[i] == b[j])
                return 0; 
        }
    }
    
    return 1; 
}

int main() {
    int a[] = {12, 34, 11, 9, 3};
    int b[] = {7, 2, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    
    if(areDisjoint(a, n, b, m))
        printf("True");
    else
        printf("False");
        
    return 0;
}



//[Better Approach] Using Merge of Merge Sort – O(n Log n + m Log m) Time and O(1) Space

// C program to check if the given arrays are disjoint
// using merge of merge sort

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int areDisjoint(int a[], int n, int b[], int m) {
    
    // Sorting both the arrays
    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);
    
    // Initializing pointers at the  
    // beginning of both the arrays
    int i = 0, j = 0;
    
    while(i < n && j < m) {
        
        // If any common element is found, then
        // given arrays are not disjoint
        if(a[i] == b[j])
            return 0; 
            
        // Incrementing the pointer  
        // having smaller value
        if(a[i] < b[j])
            i++;
        else
            j++;
    }
    
    return 1; 
}

int main() {
    int a[] = {12, 34, 11, 9, 3};
    int b[] = {7, 2, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    
    if(areDisjoint(a, n, b, m))
        printf("True");
    else
        printf("False");
        
    return 0;
}

//[Expected Approach] Using Hashing – O(n + m) Time and O(n) Space


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASH_SIZE 1000

int hashFunction(int key) {
    return abs(key) % HASH_SIZE;
}

void insertIntoHashTable(int hashTable[], int key) {
    int index = hashFunction(key);
    hashTable[index] = 1;
}

bool searchInHashTable(int hashTable[], int key) {
    int index = hashFunction(key);
    return hashTable[index] == 1;
}

bool areDisjoint(int a[], int n, int b[], int m) {
    int hashTable[HASH_SIZE] = {0};

    for (int i = 0; i < n; i++) 
        insertIntoHashTable(hashTable, a[i]);

    for (int i = 0; i < m; i++) {
        if (searchInHashTable(hashTable, b[i]))
            return false;
    }

    return true;
}

int main() {
    int a[] = {12, 34, 11, 9, 3};
    int b[] = {7, 2, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    if (areDisjoint(a, n, b, m))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
