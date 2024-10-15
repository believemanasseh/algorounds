/*C90

 Time complexity: O(n^2)
 Space complexity: O(1)
*/
#include <stdio.h>
#include <stdlib.h>

void solution(int arr[], int size) {
    int i = 0;

    while (i < size - 1) {
        int curr_val = arr[i];
        int next_val = arr[i + 1];
        int abs_val1 = abs(curr_val);
        int abs_val2 = abs(next_val);

        if (abs_val1 > abs_val2) {
            arr[i] = next_val;
            arr[i + 1] = curr_val;
        } else if (abs_val1 == abs_val2 && curr_val > 0) {
            arr[i] = next_val;
            arr[i + 1] = curr_val;
        }

        if (i == size - 2) {
            i = 0;
            size--;
        } else {
            i++;
        }
    }
}

int main() {
    /* Current implementation uses bubble sort algorithm.
    Future commits would include optimised version.*/

    int arr[] = {18, 17, 3, -2, 5, 21, 0, 3, 23, 34};
    int size = sizeof(arr) / sizeof(arr[0]);

    solution(arr, size);

    int i;
    printf("{");
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}
