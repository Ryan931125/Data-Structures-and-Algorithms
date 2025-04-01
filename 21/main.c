#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

typedef struct node{
    struct node *left, *right, *parent;
    int data;
    bool is_black;
}Node;

// A Stack has array of Nodes, capacity, and top
typedef struct Stack{
	int top;
	int capacity;
	Node* *array;
} Stack;

Node* newNode( int data, bool is_black){
	Node* temp = (Node *)malloc(sizeof( Node));
	temp->data = data;
	temp->left = temp->right = NULL;
    temp->is_black = (is_black? true:false );
	return temp;
}

Stack* createStack( int capacity ){
	Stack* stack = (Stack *)malloc( sizeof( Stack ) );
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (Node **)malloc( stack->capacity * sizeof( Node* ) );
	return stack;
}

Node* peek( Stack* stack ){
	return stack->array[ stack->top ];
}

int isFull( Stack* stack ){
	return stack->top == stack->capacity - 1;
}

int isEmpty( Stack* stack ){
	return stack->top == -1;
}

Node* pop( Stack* stack ){
	if( isEmpty(stack) )  return NULL;
	return stack->array[ stack->top-- ];
}

void push( Stack* stack, Node* item ){
	if( isFull(stack) )   return;
	stack->array[ ++stack->top ] = item;
}

//creates bst from 0-based array
Node* constructTree ( int pre[], bool is_black[], int size )
{
	// Create a stack of capacity equal to size
	Stack* stack = createStack( size );

	// The first element of pre[] is always root
	Node* root = newNode( pre[0], is_black[0]);
    root->parent=NULL;
	// Push root
	push( stack, root );

	int i;
	Node* temp;

	// Iterate through rest of the size-1 items of given preorder array
	for ( i = 1; i < size; ++i )
	{
		temp = NULL;

		/* Keep on popping while the next value is greater than
		stack's top value. */
		while ( !isEmpty( stack ) && pre[i] > peek( stack )->data ){
			temp = pop( stack );
        }

		// Make this greater value as the right child
		// and push it to the stack
		if ( temp != NULL)
		{
			temp->right = newNode( pre[i], is_black[i]);
            temp->right->parent=temp;
			push( stack, temp->right );
		}

		// If the next value is less than the stack's top 
		// value, make this value as the left child of the
		// stack's top node. Push the new node to stack
		else
		{
			peek( stack )->left = newNode( pre[i], is_black[i] );
            peek( stack )->left->parent = peek ( stack );
			push( stack, peek( stack )->left );
		}
	}

	return root;
}

void printInorder (Node* node){
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d %d\n", node->data, node->is_black);
	printInorder(node->right);
}

Node *left_rotate(Node *root, int key){
    Node *x=root;
    while (x->data!=key){
        if (key > x->data)
            x=x->right;
        else
            x=x->left;
    }//found the one to rotate -> x

    Node *y=x->right;//y=4
    x->right=y->left;   
    if (y->left!=NULL)
        y->left->parent=x;
    y->parent=x->parent;
    if (x->parent==NULL)            root=y;
    else if (x==x->parent->left)    x->parent->left=y;
    else                            x->parent->right=y;
    y->left=x;
    x->parent=y;
    return root;
}

Node *right_rotate(Node *root, int key){
    Node *y=root;
    while (y->data!=key){
        if (key > y->data)
            y=y->right;
        else
            y=y->left;
    }//found the one to rotate -> y

    Node* x = y->left; // Set x
    y->left = x->right; // Turn x's right subtree into y's left subtree
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent; // Link y's parent to x
    if (y->parent == NULL) {
        root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y; // Put y on x's right
    y->parent = x;
    return root;
}

void print_info(Node *root, int key){
    Node *x=root;
    int depth=0, black_depth=0;
    while (x->data!=key){
        depth++;
        if (x->is_black)    black_depth++;
        if (key > x->data)
            x=x->right;
        else
            x=x->left;
    }
    int lk=(x->left? x->left->data: -1), rk=(x->right? x->right->data: -1);
    printf("%d %d %d %d\n", lk, rk, black_depth, depth);
}

int main(){
    int n;
    scanf("%d",&n);
    int pre[n];
    char color, line_break;
    bool is_black[n];
    scanf("%c", &line_break);
    for (int i=0;i<n;i++){
        scanf("%c%d%c", &color, &pre[i], &line_break);
        is_black[i]=(color=='B'? true: false);
    }
    Node *root = constructTree(pre,is_black,n);

    int m, key;
    scanf("%d%c", &m, &line_break);
    char ope;
    for (int i=0;i<m;i++){
        scanf("%c%d%c", &ope, &key, &line_break);
        if (ope=='L')
            root=left_rotate(root, key);
        else if (ope=='R')
            root=right_rotate(root, key);
        else
            print_info(root, key);
    }
    



    // for (int i=0;i<n;i++)
    //     printf("\n%d", pre[i]);
    // printf("Inorder traversal of the constructed tree: \n");
	// printInorder(root);



    return 0;
}

