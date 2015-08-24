#include "RB-tree.h"
#include <stdio.h>
#define OK 1
#define ERR 0


typedef enum{
	RED,
	BLACK
}ColorType;


typedef struct Node{
	int data;
	ColorType color;
	struct Node *pParent;
	struct Node *pLeft;
	struct Node *pRight;
}Node;



typedef struct RB_tree{
	Node *root;

}RB_tree;


RB_tree T;

int RB_Tree_InsertNode(RB_tree *pTree, int data)
{
	Node *tmpNode;
	Node *NodeIter = pTree->root;

	tmpNode = (Node *)malloc(sizof(Node));
	tmpNode->data = data;
	tmpNode->color = RED;
	tmpNode->pLeft = tmpNode->pRight = NULL;

	/* Find the position to insert */
	while(NodeIter != NULL) {
		if(data > NodeIter->data)
			NodeIter = NodeIter->pRight;
		else
			Node
	}


	/* Case 1: empty tree*/
	if(pTree->root == NULL)
		pTree->root = tmpNode;



}

int main(int argc, char **argv) {


	printf("hello world!\n");
}


