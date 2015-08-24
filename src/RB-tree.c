#include "RB-tree.h"
#include <stdio.h>
#define OK 1
#define ERR 0
#define NULL ((void *)0)

typedef enum
{
	RED, BLACK
} ColorType;

typedef struct Node
{
	int data;
	ColorType color;
	struct Node *pParent;
	struct Node *pLeft;
	struct Node *pRight;
} Node;

typedef struct RB_tree
{
	Node *root;

} RB_tree;

RB_tree T;

static inline void LEFT_ROTATE(RB_tree *T, Node *pNodeX)
{
	Node *pNodeY;

	if (pNodeX->pRight == NULL)
		return;

	pNodeY = pNodeX->pRight;
	pNodeX->pRight = pNodeY->pLeft;

	if (pNodeY->pLeft != NULL)
		pNodeY->pLeft->pParent = pNodeX;

	pNodeY->pParent = pNodeX->pParent;

	if (pNodeX->pParent == NULL)
		T->root = pNodeY;
	else if (pNodeX->pParent->pLeft == pNodeX)
		pNodeX->pParent->pLeft = pNodeY;
	else
		pNodeX->pParent->pRight = pNodeY;

	pNodeY->pLeft = pNodeX;
	pNodeX->pParent = pNodeY;
}

static inline void RIGHT_ROTATE(RB_tree *T, Node *pNodeY)
{
	Node *pNodeX;

	if (pNodeY->pLeft == NULL)
		return;

	pNodeX = pNodeY->pLeft;
	pNodeY->pLeft = pNodeX->pRight;

	if (pNodeX->pRight != NULL)
		pNodeX->pRight->pParent = pNodeY;

	pNodeX->pParent = pNodeY->pParent;

	if (pNodeY->pParent == NULL)
		T->root = pNodeX;
	else if (pNodeY->pParent->pLeft == pNodeY)
		pNodeY->pParent->pLeft = pNodeX;
	else
		pNodeY->pParent->pRight = pNodeX;

	pNodeX->pRight = pNodeY;
	pNodeY->pParent = pNodeX;
}

int RB_Tree_InsertNode(RB_tree *pTree, int data)
{
	Node *tmpNode;
	Node *NodeIter = pTree->root;

	tmpNode = (Node *) malloc(sizof(Node));
	tmpNode->data = data;
	tmpNode->color = RED;
	tmpNode->pLeft = tmpNode->pRight = tmpNode->pParent = NULL;

	/* Find the position to insert */
	while (NodeIter != NULL && NodeIter->pLeft != NULL
			&& NodeIter->pRight != NULL)
	{
#if 1
		if (data >= NodeIter->pRight->data)
			NodeIter = NodeIter->pRight;
		else if (data <= NodeIter->pLeft->data)
			NodeIter = NodeIter->pLeft;
		else
			break;
#endif
	}
	/* Now NodeIter should point to the right position to insert the node */

	/* Case 1: empty tree*/
	if (pTree->root == NULL)
	{
		tmpNode->color = BLACK;
		pTree->root = tmpNode;
	}

}

int main(int argc, char **argv)
{

	printf("hello world!\n");
}

