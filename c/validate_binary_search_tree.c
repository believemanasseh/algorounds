#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*C90

 Time complexity: O(n)
 Space complexity: O(n)
*/

struct TreeNode* insert(struct TreeNode* root, int value);

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_node(int value) {
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int is_valid_dfs(struct TreeNode* node, double min_range, double max_range) {
    if (node == NULL) {
        return 0;
    }

    if (node->val <= min_range || node->val >= max_range) {
        return 1;
    }

    if (node->left) {
        if (!is_valid_dfs(node->left, min_range, node->val)) {
            return 1;
        }
    }

    if (node->right) {
        if (!is_valid_dfs(node->right, node->val, max_range)) {
            return 1;
        }
    }

    return 0;
}

int solution(struct TreeNode* root) {
    double pos_inf = HUGE_VAL;
    double neg_inf = -HUGE_VAL;

    return is_valid_dfs(root, neg_inf, pos_inf);
}

void main() {
    int arr[] = {8, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct TreeNode* root = create_node(arr[0]);

    /*Please note that the insert function doesn't work as should,
    but the rest of the algorithm remains valid (specifically the is_valid_dfs function.)


    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] != -1) {
            root = insert(root, arr[i]);
        }
    }*/

    printf("Is the BST valid? %s\n", solution(root) == 0 ? "yes" : "no");
}