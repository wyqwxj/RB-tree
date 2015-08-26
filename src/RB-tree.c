#include "RB-tree.h"
#include <stdio.h>
#include <stdlib.h>



#define OK ((bool)1)
#define ERR ((bool)0)
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

static void RB_Tree_InsertFixup(RB_tree *pTree, Node *pNode)
{
	Node *pUncleNode = NULL;

	while (pNode->pParent->color == RED)/* Grandparent node must exist and it's color must be BLACK */
	{
		/* If parent node is grandparent's left child */
		if (pNode->pParent->pParent->pLeft == pNode->pParent)
		{
			pUncleNode = pNode->pParent->pParent->pRight;
			if (pUncleNode->color == RED) /* Case 1: uncle is red */
			{
				pNode->pParent->pParent->color = RED;
				pUncleNode->color = BLACK;
				pNode->pParent->color = BLACK;
				pNode = pNode->pParent->pParent;
				/* Fix-up is not end */
			}
			else
			{
				if (pNode == pNode->pParent->pRight)/* Case 2: uncle is black, Node is parent's right child */
				{
					pNode = pNode->pParent;
					LEFT_ROTATE(pTree, pNode);
				}
				/* Case 3: uncle is black, Node is parent's left child */
				pNode->pParent->pParent->color = RED;
				pNode->pParent->color = BLACK;
				pNode = pNode->pParent->pParent;
				RIGHT_ROTATE(pTree, pNode);
				/* Fix up should end */
			}
		}
		else
		{
			pUncleNode = pNode->pParent->pParent->pLeft;
			if (pUncleNode->color == RED) /* Case 1': uncle is red */
			{
				pNode->pParent->pParent->color = RED;
				pUncleNode->color = BLACK;
				pNode->pParent->color = BLACK;
				pNode = pNode->pParent->pParent;
				/* Fix-up is not end */
			}
			else
			{
				if (pNode == pNode->pParent->pLeft)/* Case 2': uncle is black, Node is parent's left child */
				{
					pNode = pNode->pParent;
					RIGHT_ROTATE(pTree, pNode);
				}
				/* Case 3': uncle is black, Node is parent's right child */
				pNode->pParent->pParent->color = RED;
				pNode->pParent->color = BLACK;
				pNode = pNode->pParent->pParent;
				LEFT_ROTATE(pTree, pNode);
			}
		}
		pTree->root->color = BLACK;
	}	//while
}

void RB_Tree_InsertNode(RB_tree *pTree, int data)
{
	Node *tmpNode;
	Node *NodeIter = pTree->root;
	Node *NodeIterPre = NULL;

	tmpNode = (Node *) malloc(sizeof(Node));
	tmpNode->data = data;
	tmpNode->color = RED;
	tmpNode->pLeft = tmpNode->pRight = tmpNode->pParent = NULL;
	/* Fix-up is not end */
	/* Find the position to insert */
	while (NodeIter != NULL)
	{
		NodeIterPre = NodeIter;
		NodeIter = NodeIter->data < data ? NodeIter->pLeft : NodeIter->pRight;
	}
	/* Now NodeIter should point to the right position to insert the node */

	if (pTree->root == NULL)
	{ /* empty tree */
		tmpNode->color = BLACK;
		pTree->root = tmpNode;
	}
	else if (data < NodeIterPre->data)
	{
		NodeIter->pLeft = tmpNode;
		tmpNode->pParent = NodeIterPre;
	}
	else
	{
		NodeIter->pRight = tmpNode;
		tmpNode->pParent = NodeIterPre;
	}

	/* After insertion, fix up the tree to conform to the five rules*/
	RB_Tree_InsertFixup(pTree, tmpNode);
}

int main(int argc, char **argv)
{

	printf("hello world!\n");
	return 0;
}

