#include <stdio.h>

/*C90

 Time complexity: O(logn)
 Space complexity: O(1)
*/

int solution(int *nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = (left + right) / 2;

    if (numsSize == 1)
    {
        return nums[0];
    }

    if (nums[left] < nums[right])
    {
        return nums[left];
    }

    if (nums[mid] > nums[mid + 1])
    {
        return nums[mid + 1];
    }
    else if (nums[mid] > nums[mid - 1])
    {
        if (nums[mid - 1] > nums[numsSize - 1])
        {
            left = mid - 1;
        }
        else
        {
            right = mid + 1;
        }
    }
    else
    {
        return nums[mid];
    }

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int num = nums[mid];
        if (num == nums[0])
        {
            if (num < nums[mid + 1])
            {
                return num;
            }
            else
            {
                return nums[mid + 1];
            }
        }

        if (num < nums[mid - 1])
        {
            return num;
        }
        else if (num > nums[mid - 1])
        {
            if (nums[mid - 1] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            return num;
        }
    }

    return 0;
}

void main()
{
    int arr[] = {2, 3, 4, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", solution(arr, size));
}
