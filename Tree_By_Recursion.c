                               // A complete implementation of BST
                               //Insert ,Delete or Printing the tree
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct root
{
    int data;
    struct root *left,*right;
};
typedef struct root NODE;     //Here we can change the name of structure to ->NODE
NODE *Delete(NODE*,int);      //Function deceleration
NODE *findMIN(NODE*);         //Function deceleration
void insertNode(int);         //Function deceleration

NODE *root,*P,*temp,*current;         //Variable Deceleration   //"P" is use for pointing a parent node of targeted node in insert function.                                                                //"current" is use for point the targeted node in insert function.
int more = 1;                        //Variable Deceleration
int data;                            //Variable Deceleration    //"Data" is use for insert new data in Tree.
int delElement;                      //Variable Deceleration


 void main()
 {
     int choice;
     while(1)
     {
    printf("\n---------Welcome to tree Program------------\n");
    printf("1: For Insert node In Tree:\n");
    printf("2: Delete A node\n");
    printf("3: Display The Tree\n");
    printf("4: Exit The Program\n");

    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:

          while(more == 1)
         {
         printf("Enter the data:");
         scanf("%d",&data);
         insert(data);
         printf("\nDo you want to insert more nodes (Type 1): ");
         scanf("%d",&more);
         }
         break;
    case 2:                      //Insert nodes in tree

         printf("Enter the delete element:");
         scanf("%d",&delElement);
         root = Delete(root,delElement);
         break;
    case 3:                     //Display all nodes of tree

        printf("\t\t**********************************Print  by Inorder Traversing: ");
        Display_Inorder(root);
        printf("\n\t\t**********************************Print by Preorder Traversing: ");
        Display_Preorder(root);
        printf("\n\t\t**********************************Print by Postorder Traversing: ");
        Display_Postorder(root);
        break;
    case 4:                   //To exit the program
        exit(0);
    }
     }
 }
    void insert(int d)  //Create Insert Function to inset element in tree.
    {
        temp = (NODE*)malloc(sizeof(NODE));
        temp->data = d;
        temp->left = NULL;
        temp->right = NULL;
        P = root;
        if(root == NULL)
        {
            root = temp;
            temp->data = d;
        }
        else
        {
            current = root;
            while(current)
            {
                P = current;
                if(temp->data > current->data)
                 {
                  current = current->right;
                  }
                else
                {
                    current = current->left;
                }
            }
               if(P->data < temp->data)
          {
              P->right = temp;
          }
          else
          {
              P->left = temp;
          }

        }

    }
void Display_Inorder(NODE *root)
{
    if(root == NULL)
        return;
        Display_Inorder(root->left);
        printf("%d=>",root->data);
        Display_Inorder(root->right);

}
   void Display_Postorder(NODE *root)
    {
        if(root == NULL)
        return;
        Display_Postorder(root->left);
        Display_Postorder(root->right);
        printf("%d=>",root->data);

    }
   void  Display_Preorder(NODE *root)
    {
        if(root == NULL)
        return;
        printf("%d=>",root->data);
        Display_Preorder(root->left);
        Display_Preorder(root->right);
    }

    NODE *Delete(NODE *root,int data)   //Here Create Delete Function
    {

        if(root == NULL)
          {
            printf("Element is not found in the Tree:");
            return;
          }
            if(data < root->data)
           {
            root->left = Delete(root->left,data);
            }
        else
            if(data > root->data)
        {
            root->right = Delete(root->right,data);

        }
        //Case 1:Delete a node which have One or No child
        else
            if(root->left == NULL || root->right == NULL)
        {
            temp = root;
           if(root->left == NULL)
           {
            root = root->right;
           }
            else
                if(root->right == NULL)
                {
                  root = root->left;
                }

           free(temp);
        }
        //Case 2: Delete a node which having two child nodes
        else
            {
             if(root->right && root->left)
             {
                 temp = findMIN(root->right);
                 root->data = temp->data;
                 root->right = Delete(root->right,temp->data);
             }
            }
        return root;
    }
NODE *findMIN(NODE *root)    // Create a Function to find Minimum. It return the Minimum value of Right sub Tree.
{
    if(root->left == NULL)
    {
        return root;
    }
    else
    if(root->right == NULL)
    {
   return findMIN(root->left);
    }
}

