#include <stdio.h>
#include <stdlib.h>

// Define a type for the set using a 32-bit unsigned integer
typedef unsigned int BitSet;

#define UNIVERSAL_SET_SIZE 32 // Only elements from 0 to 31 are allowed

// -----------------------------
// Function: create_set
// Description: Creates a bitset from an array of integers
// -----------------------------
BitSet create_set(int arr[], int size) {
    BitSet set = 0;

    for (int i = 0; i < size; i++) {
        int element = arr[i];
        if (element >= 0 && element < UNIVERSAL_SET_SIZE) {
            set |= (1 << element); // Set the bit for this element
        } else {
            printf("Warning: Element %d is out of bounds [0 to 31] and was ignored.\n", element);
        }
    }
    return set;
}

// -----------------------------
// Function: print_set
// Description: Prints the elements of the set in { a b c } format
// -----------------------------

void print_set(BitSet set) {
    printf("{ ");
    for (int i = 0; i < UNIVERSAL_SET_SIZE; i++) {
        if (set & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

// -----------------------------
// Set operation functions
// -----------------------------
BitSet set_union(BitSet a, BitSet b) {
    return a | b;
}

BitSet set_intersection(BitSet a, BitSet b) {
    return a & b;
}

BitSet set_difference(BitSet a, BitSet b) {
    return a & ~b;
}

int is_member(BitSet set, int element) {
    if (element < 0 || element >= UNIVERSAL_SET_SIZE)
        return 0;
    return (set & (1 << element)) != 0;
}

// -----------------------------
// Main Function: Gets user input and demonstrates set operations
// -----------------------------
int main() {
    int size1, size2;

    // ---------- Input for Set A ----------
    printf("Enter the number of elements in Set A: ");
    scanf("%d", &size1);

    int arr1[size1];
    printf("Enter %d elements for Set A (values between 0 and 31):\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // ---------- Input for Set B ----------
    printf("Enter the number of elements in Set B: ");
    scanf("%d", &size2);

    int arr2[size2];
    printf("Enter %d elements for Set B (values between 0 and 31):\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // ---------- Create BitSets ----------
    BitSet setA = create_set(arr1, size1);
    BitSet setB = create_set(arr2, size2);

    // ---------- Display sets ----------
    printf("\nSet A: ");
    print_set(setA);

    printf("Set B: ");
    print_set(setB);

    // ---------- Perform and display operations ----------
    BitSet unionSet = set_union(setA, setB);
    printf("Union (A UNION B): ");
    print_set(unionSet);

    BitSet intersectionSet = set_intersection(setA, setB);
    printf("Intersection (A INTERSECTION B): ");
    print_set(intersectionSet);

    BitSet differenceSet = set_difference(setA, setB);
    printf("Difference (A - B): ");
    print_set(differenceSet);

    // ---------- Membership test ----------
    int element;
    printf("\nEnter an element to check for membership: ");
    scanf("%d", &element);

    printf("Is %d in Set A? %s\n", element, is_member(setA, element) ? "Yes" : "No");
    printf("Is %d in Set B? %s\n", element, is_member(setB, element) ? "Yes" : "No");

    return 0;
}