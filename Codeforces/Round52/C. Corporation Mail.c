#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct treenode
{
	char name[15];
	struct treenode *left, *right;
};

char input[1001];
int res;

// input name
void inputName(char name[], int *pos)
{
	int pp = 0;
	while(input[*pos] >= 'A' && input[*pos] <= 'Z')
	{
		name[pp++] = input[*pos];
		(*pos)++;
	}
	name[pp] = '\0';
}

// create a node
struct treenode *createTreeNode(char name[])
{
	struct treenode *root = (struct treenode *)malloc(sizeof(struct treenode));
	strcpy(root->name, name);
	root->left = root->right = NULL;
	return root;
}

// input struct
struct treenode* createTree(int *pos)
{
	char name[15];
	char c;
	struct treenode *temp, *subTree, *root; 
	inputName(name, pos);
	root = createTreeNode(name);
//	printf("root%s\n", name);
	c = input[(*pos)++];
	if (c == ':')
	{
		subTree = root->left = createTree(pos);
		c = input[(*pos)++];
		while(c == ',')
		{
			temp = createTree(pos);
			subTree->right = temp;
			subTree = temp;
			c = input[(*pos)++];
		}
	}

	return root;
}

void search(struct treenode *root, char name[])
{
	struct treenode *temp;
	temp = root->left;
	while(temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
			res++;
		search(temp, name);
		temp = temp->right;
	}

}

void walk(struct treenode *root)
{
	struct treenode *temp;
//	printf("ccc%s\n", root->name);
	search(root, root->name);
	temp = root->left;
	while(temp != NULL)
	{
		walk(temp);
		temp = temp->right;
	}
}

int main()
{
	struct treenode* root;
	int pos = 0;
	scanf("%s", input);
	root = createTree(&pos);
	walk(root);
	printf("%d\n", res);
	return 0;
}
