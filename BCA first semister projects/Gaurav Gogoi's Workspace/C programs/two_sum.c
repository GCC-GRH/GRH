#include <stdio.h>

int main() {
    int nums[4] = {10, 12, 16, 20};
    int target, i, j;
    int arraySize = sizeof(nums) / sizeof(nums[0]);

    printf("Please enter your target value: ");
    scanf("%d", &target);

    for (i = 0; i < arraySize; i++) {
        for (j = i + 1; j < arraySize; j++) { // start from i+1 to avoid repeat and same index
            if (nums[i] + nums[j] == target) {
                printf("\nTarget value %d is found at indices [ %d, %d ]\n", target, i, j);
                return 0; // Exit once found
            }
        }
    }

    printf("\nTarget not found in the array.\n");
    return 0;
}
