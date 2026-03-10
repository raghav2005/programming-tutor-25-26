#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode *root;
} BinaryTree;


static TreeNode *create_node(int value);
static TreeNode *insert_node(TreeNode *node, int value);
static TreeNode *delete_node(TreeNode *node, int value);
static TreeNode *find_node(TreeNode *node, int value);
static TreeNode *find_min(TreeNode *node);
static void free_nodes(TreeNode *node);

static void print_inorder_node(TreeNode *node);
static void print_preorder_node(TreeNode *node);
static void print_postorder_node(TreeNode *node);


void bt_init(BinaryTree *tree) {
    if (tree == NULL) {
        return;
    }
    tree->root = NULL;
}

void bt_init_list(BinaryTree *tree, int *arr, int size) {
    if (tree == NULL || arr == NULL || size <= 0) {
        return;
    }

    tree->root = NULL;

    for (int i = 0; i < size; i++) {
        tree->root = insert_node(tree->root, arr[i]);
    }
}

void bt_insert(BinaryTree *tree, int value) {
    if (tree == NULL) {
        return;
    }
    tree->root = insert_node(tree->root, value);
}

void bt_delete(BinaryTree *tree, int value) {
    if (tree == NULL) {
        return;
    }
    tree->root = delete_node(tree->root, value);
}

bool bt_find(BinaryTree *tree, int value) {
    if (tree == NULL) {
        return false;
    }
    return find_node(tree->root, value) != NULL;
}

void bt_print_inorder(BinaryTree *tree) {
    if (tree == NULL) {
        return;
    }
    print_inorder_node(tree->root);
    printf("\n");
}

void bt_print_preorder(BinaryTree *tree) {
    if (tree == NULL) {
        return;
    }
    print_preorder_node(tree->root);
    printf("\n");
}

void bt_print_postorder(BinaryTree *tree) {
    if (tree == NULL) {
        return;
    }
    print_postorder_node(tree->root);
    printf("\n");
}

void bt_free(BinaryTree *tree) {
    if (tree == NULL) {
        return;
    }
    free_nodes(tree->root);
    tree->root = NULL;
}


static TreeNode *create_node(int value) {
    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));

    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

static TreeNode *insert_node(TreeNode *node, int value) {
    if (node == NULL) {
        return create_node(value);
    }

    if (value < node->value) {
        node->left = insert_node(node->left, value);
    } else if (value > node->value) {
        node->right = insert_node(node->right, value);
    }

    return node;
}

static TreeNode *find_node(TreeNode *node, int value) {
    if (node == NULL) {
        return NULL;
    }

    if (value == node->value) {
        return node;
    } else if (value < node->value) {
        return find_node(node->left, value);
    } else {
        return find_node(node->right, value);
    }
}

static TreeNode *find_min(TreeNode *node) {
    if (node == NULL) {
        return NULL;
    }

    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

static TreeNode *delete_node(TreeNode *node, int value) {
    if (node == NULL) {
        return NULL;
    }

    if (value < node->value) {
        node->left = delete_node(node->left, value);
    } else if (value > node->value) {
        node->right = delete_node(node->right, value);
    } else {
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }

        if (node->left == NULL) {
            TreeNode *temp = node->right;
            free(node);
            return temp;
        }

        if (node->right == NULL) {
            TreeNode *temp = node->left;
            free(node);
            return temp;
        }

        TreeNode *successor = find_min(node->right);
        node->value = successor->value;
        node->right = delete_node(node->right, successor->value);
    }

    return node;
}

static void free_nodes(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    free_nodes(node->left);
    free_nodes(node->right);
    free(node);
}

static void print_inorder_node(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    print_inorder_node(node->left);
    printf("%d ", node->value);
    print_inorder_node(node->right);
}

static void print_preorder_node(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->value);
    print_preorder_node(node->left);
    print_preorder_node(node->right);
}

static void print_postorder_node(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    print_postorder_node(node->left);
    print_postorder_node(node->right);
    printf("%d ", node->value);
}


int main(void) {
    BinaryTree tree;
    /* int values[] = {10, 5, 15, 3, 7, 12, 18}; */
    /* int values[] = {3, 5, 7, 10, 12, 15, 18}; // pre-order output */
    /* int values[] = {3, 7, 5, 12, 18, 15, 10}; // post-order output */
    int values[] = {10, 5, 3, 7, 15, 12, 18}; // in-order output
    int size = sizeof(values) / sizeof(values[0]);
    
    bt_init_list(&tree, values, size);

    printf("Inorder:   ");
    bt_print_inorder(&tree);

    printf("Preorder:  ");
    bt_print_preorder(&tree);

    printf("Postorder: ");
    bt_print_postorder(&tree);

    bt_free(&tree);
    return 0;
}
