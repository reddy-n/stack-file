#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int push(char x[20]);
void display();
void peek();
void pop();

typedef struct node
{
    char data[20];
    struct node *link;
}Node;

FILE *fptr;
int max_num=0;

Node *top=0;
int main()
{
    extern FILE *fptr;
    int choice,status=0;
    char ch,num[20],temp_choice[1],path[50];
    printf("\nEnter the text path: "); //asks path
    scanf(" %50[^\n]",path);
    fptr=fopen(path,"r");
    if(fptr==NULL)
    {
        printf("\nError opening the file..");
        return -1;
    }
do{
    printf("\nChoose the option to perform stack function (stack size is 5)\n");
    printf("\n\t1)PUSH\t2)POP\n\t3)PEEK\t4)DISPLAY\t5)EXIT\n\n");
    do{
        printf("\nYour choice please: ");
        scanf("%s",temp_choice);
      }while(temp_choice[0]<='1' && temp_choice[0]>='5'); //iterates while choice is wrong
       choice=atoi(temp_choice);


    switch(choice)
    {
    case 1:

          do{
                fscanf(fptr,"%s",num);
                if((num[0]>='a' && num[0]<='z') || (num[0]>='A' && num[0]<='Z') || (num[0]>='0' && num[0]<='9'))
                {
                    status=push(num);
                }
                else
                    continue;
                if(status==1)
                break;
                printf("\nDo you want to add more(y or n)?: ");
                scanf(" %c",&ch);
           }while(ch!='n'); //takes elements till we choose no
           break;

   case 2:
        pop();
        break;

   case 3:
        peek();
        break;

   case 4:
        display();
        break;

   case 5:
       fclose(fptr);
        break;

   default:
       printf("\nPlease Choose the correct option");
       break;

    }
}while(choice!=5); //goto main menu unless we choose exit
    return 0;
}

int push(char x[20])
{
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL)
       {
        printf("\nMemory is not allocated");
        return 1;
        EXIT_FAILURE;
       }
       else if(max_num>=5)
       {
           printf("\nStack overflow can't push element");
           return 1;
           EXIT_FAILURE;
       }
    else
    {
    strcpy(newnode->data,x);
    newnode->link=top;
    top=newnode;
    printf("\nPushed %d element ie., %s",max_num+1,x);
    ++max_num;
    }
return 0;
}

void display()
{
    Node *temp;
    temp=top;
    if(temp==NULL)
    {
        printf("\nStack is empty to display\n");
                EXIT_FAILURE;
    }
    else
    {
        printf("\nDisplaying Data: ");
        while(temp!='\0')
        {
            printf("\n|%s|\n",temp->data);
            temp=temp->link;
        }
    }
}

void peek()
{
    if(top==NULL)
    {
        printf("\nThere are no elements to display\n");
        EXIT_FAILURE;
    }
    else
        printf("\n\nThe top element in the list is : %s",top->data);
}

void pop()
{
    Node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("\nPop operation is unsuccessful, because stack is underflow!\n");
        EXIT_FAILURE;
    }
    else
    {
        printf("\n\nPoped element is %s",top->data);
        top=top->link;
        free(temp);
        --max_num;
    }
}
