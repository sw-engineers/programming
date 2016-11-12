#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Binary search
 * Parameters:
 *   left, right: indices, inclusive
 * Return value:
 *   0 or positive: if found
 *   negtive: not found
 */
int binary_search(int nums[], int left, int right, int target)
{
	while (left <= right) {
		int mid = (left + right) / 2;
		if (target == nums[mid])
			return mid;
		else if (target < nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

bool test_full(void)
{
	const int test_size = 1024;
	int nums[test_size];
	int i, idx_in_array;
	int val = 0;
	int failed = 0;

	/* Created a sorted integer array */
	for (i = 0; i < test_size; ++i) {
		val += ((int) random()) & 0x0f;
		val += 1;
		nums[i] = val;
	}

	/* verify */
	for (i = -1, idx_in_array = 0; i < val + 10; ++i) {
		int expected = -1;
		int result;

		if (idx_in_array < test_size) {
			if (nums[idx_in_array] == i) {
				expected = idx_in_array;
				++idx_in_array;
			}
		}

		result = binary_search(nums, 0, test_size - 1, i);
		if (expected < 0 && result < 0)
			;
		else if (expected != result) {
			printf("Failed with %d: Got %d Expecting %d\n", i, result, expected);
			++failed;
		}
	}

	return failed == 0;
}

int main(void)
{
	test_full();

	return 0;
}
