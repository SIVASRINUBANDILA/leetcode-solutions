int missingInteger(int* nums, int numsSize) {
    int total = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            total += nums[i];
        } else {
            break;
        }
    }

    bool found = true;

    while (found) {
        found = false;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == total) {
                found = true;
                total += 1;
                break;
            }
        }
    }

    return total;
}
