void copySubArray(int *src, int *dst, int end) {
	int i;

	i = 0;
	while (i < end) {
		dst[i] = src[i];
		i++;
	}
}

void merge(int *nums, int numsSize) {
	int k;
	int a[(numsSize / 2)], b[numsSize - (numsSize / 2)];

	copySubArray(nums, a, numsSize / 2);
	copySubArray(nums + numsSize / 2, b, numsSize - (numsSize / 2));

	int i = 0;
	int j = 0;
	for (k = 0; k < numsSize; k++) {
		if (j >= numsSize - (numsSize / 2) || i >= numsSize / 2) break;
		if (a[i] < b[j]) {
			nums[k] = a[i];
			i++;
		} else {
			nums[k] = b[j];
			j++;
		}
	}
	while (i < numsSize / 2) {
        nums[k] = a[i];
        i++;
        k++;
    }

    while (j < numsSize - (numsSize / 2)) {
        nums[k] = b[j];
        j++;
        k++;
    }

}

void mergeSort(int *nums, int numsSize) {
	if (numsSize - 1 > 0) {
    	int m = numsSize / 2;

		mergeSort(nums, m);
		mergeSort(nums + m, numsSize - m);

		merge(nums, numsSize);
	}
}
