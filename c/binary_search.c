#include <stdio.h>

/*C90

 Time complexity: O(logn)
 Space complexity: O(1)
*/

int solution(int numbers[], int target, int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (numbers[mid] < target)
        {
            left = mid + 1;
        }
        else if (numbers[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

void main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", solution(arr, 7, size));
}
