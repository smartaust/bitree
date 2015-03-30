#include <stdio.h>
#include <stdlib.h>
typedef struct _binary_tree_t
{
	int data;
	struct _binary_tree_t *lchild;
	struct _binary_tree_t *rchild;
}binary_tree_t;

int binarytree_init(binary_tree_t ** proot ,int data);
int addleaf(binary_tree_t *proot , int data);
void treelist_first(binary_tree_t *proot);
void treelist_middle(binary_tree_t * ptreeroot);
void treelist_back(binary_tree_t * ptreeroot);

int main()
{
	int i;
     	int array[10] = {6,21,31,3,4,6,7,0,5,8};
	binary_tree_t *ptreeroot = NULL;
	if(ptreeroot == NULL)
	{
		binarytree_init(&ptreeroot,array[0]);	
	}
	for(i = 1;i < 10;i ++)
	{
		addleaf(ptreeroot,array[i]);
	}
	printf("proorder traversal:\n");
	treelist_first(ptreeroot);
       	printf("\n");
	
	printf("inorder traversal:\n");
        treelist_middle(ptreeroot);
	printf("\n");

	printf("postorder traversal:\n");
     	treelist_back(ptreeroot);
	printf("\n");
	
}

int binarytree_init(binary_tree_t ** pproot ,int data)
{
	if(*pproot == NULL)
	{
		*pproot = (binary_tree_t *)calloc(1,sizeof(binary_tree_t));
		if(*pproot == NULL)
		return -1;
	}

	(*pproot)->data = data;
	(*pproot)->lchild = NULL; 
	(*pproot)->rchild = NULL;
		return 0;
}

int addleaf(binary_tree_t *proot , int data)
{
	binary_tree_t * ptemp;
	if(data > proot->data)
	{
		if((proot->lchild))
		{
			addleaf(proot->lchild,data);
		}

		else
		{
			ptemp =(binary_tree_t *)calloc(1,sizeof(binary_tree_t));
			ptemp->data = data;
			proot->lchild = ptemp;
			ptemp->lchild = NULL;
			ptemp->rchild = NULL;
		}
			
	}
	else
	{
					
		if((proot->rchild))
		{
			addleaf(proot->rchild,data);
		}
		else
		{
			ptemp =(binary_tree_t *)calloc(1,sizeof(binary_tree_t));
			ptemp->data = data;
		 	proot->rchild = ptemp;
			ptemp->lchild = NULL;
			ptemp->rchild = NULL;
		}	
	}
}

void treelist_first(binary_tree_t * proot)
{
		if(proot == NULL)
		{
			printf("NULL tree\n");
			return ;
		}
		else
		{
			   
			if(proot->lchild == NULL&&proot->rchild == NULL)
                        printf("%d ",proot->data);

			else
			{ 
				printf("%d ",proot->data);
				if(proot->lchild != NULL)
				{
					treelist_first(proot->lchild);
				}
				
				if(proot->rchild != NULL)
				{
					treelist_first(proot->rchild);
				}
			}
		}

}

void treelist_middle(binary_tree_t * proot)//中序遍历
{
		if(proot == NULL)
		{
			printf("NULL tree\n");
			return ;
		}
		else
		{
			if(proot->lchild == NULL&&proot->rchild == NULL)
				printf("%d ",proot->data);
			else
			{
				if(proot->lchild != NULL)
				{
					treelist_middle(proot->lchild);
				}
				printf("%d ",proot->data);
				if(proot->rchild != NULL)
				{
					treelist_middle(proot->rchild);
				}
			}
		}

}

void treelist_back(binary_tree_t * proot)//后序遍历
{
		if(proot == NULL)
		{
			printf("NULL tree\n");
			return ;
		}
		else
		{
			if(proot->lchild == NULL&&proot->rchild == NULL)
				printf("%d ",proot->data);
			else
			{
				if(proot->lchild != NULL)
				{
					treelist_back(proot->lchild);
				}
						
				if(proot->rchild != NULL)
				{
					treelist_back(proot->rchild);
				}
				printf("%d ",proot->data);
			}
               
		}

}
