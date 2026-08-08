void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;     // Pointer for the last valid element in nums1
    int p2 = n - 1;     // Pointer for the last element in nums2
    int p = m + n - 1;  // Pointer for the last position in nums1 array

    // While there are elements to compare in both nums1 and nums2
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p--] = nums1[p1--];
        } else {
            nums1[p--] = nums2[p2--];
        }
    }

    // If there are remaining elements in nums2, copy them over
    // (Remaining elements in nums1 are already in place)
    while (p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
}
