#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int len=0;
typedef struct LinkedList LinkedList;
struct LinkedList{
    
    int data;
    LinkedList *next;
};
LinkedList* head; 

LinkedList* createLinkedList(int data)
{
    len++;
    LinkedList* node= malloc(sizeof(LinkedList));
    
    node->data=data;
    node->next=NULL;
    
    return node;
}

void insertAtBeginning(int value);
void display();
void insertAtEnd(int data);
void insertAtPosition(int position, int value);
void updateAtPosition(int position, int newValue);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
int main()
{
    head= ( LinkedList*)malloc(sizeof(LinkedList));
    head=NULL;
    
    // insertAtBeginning(  4);
    // insertAtBeginning( 3);
    // insertAtEnd(5);
    // insertAtPosition(4,6);
    // updateAtPosition(2,2 );
    // deleteAtBeginning();
    // deleteAtEnd();
    // deleteAtPosition(2);
    
    
    // printf("%d",head->data);
    // display();
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int choice;
        scanf("%d",&choice);
        
        switch(choice){
            case 1: int x;
                    scanf("%d",&x);
                    insertAtEnd(x);
                    
            break;
            
            case 2: int y;
                    scanf("%d",&y);
                    insertAtBeginning(y);
                    
            break;
            
            case 3: int pos1,z;
                    scanf("%d%d",&pos1,&z);
                    if(len==0 && pos1 != 1)
                    {
                        printf("Invalid Position\n");
                        return 0;
                    }
                    else if(pos1>=1 && pos1<=len+1){
                     
                    insertAtPosition(pos1,z);}
                    else
                    {
                        printf("Invalid Position\n");
                        return 0;
                    }
                    
                    
            break;
            
            case 4: if(len==0)
                    {
                        printf("List is Empty\n");
                        return 0;
                    }
                    else
                   display();
            break;
            
            case 5: int pos2,x2;
                    scanf("%d%d",&pos2,&x2);
                    if(pos2>=1 && pos2<=len){
                     
                    updateAtPosition(pos2,x2);}
                    else
                    {
                        printf("Invalid Position");
                        return 0;
                    }
                    
            break;
            
            case 6:  deleteAtBeginning();
                    
            break;
            
            case 7: deleteAtEnd();
            break;
            
            case 8: int pos3;
                    scanf("%d",&pos3);
                    if(pos3>=1 && pos3<=len){
                    deleteAtPosition(pos3);
                    len--;
                    }
                    else
                    {
                        printf("Invalid Position");
                        return 0;
                        
                    }
                    
            break;
            
            default:printf("Invalid Operation\n");
                    return 0;
            break;
            
        }
    }
    
    return 0;
}

void display()
{
    LinkedList* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}

void insertAtBeginning(int value)
{
    
    
    if(head==NULL){
    LinkedList* node=createLinkedList(value);
    head=node;
     
    }
    
    else
    {
         LinkedList* temp=head;
         LinkedList* node=createLinkedList(value);
         node->next=head;
         head=node;
         
        
    }
    
    
    
}


void insertAtEnd(int value)
{
     if(head==NULL){
    LinkedList* node=createLinkedList(value);
    head=node;
     
    }
    else
    {
         LinkedList* temp=head;
         while(temp->next != NULL)
         {
             temp=temp->next;
         }
         LinkedList* node=createLinkedList(value);
         temp->next=node;
        
    }
}

void insertAtPosition(int position, int value)
{
    int pos=0;
     if(head==NULL){
    LinkedList* node=createLinkedList(value);
    head=node;
     
    }
    else
    {
        if(position==1)
        {
            insertAtBeginning(value);
            return;
        }
        else
        {
             LinkedList* temp=head;
             while(temp->next != NULL)
             {
                 pos++;
              
             if(pos==position-1)
             {
                  LinkedList* node=createLinkedList(value);
                  node->next=temp->next;
                  temp->next=node;
                  return;
                 
             }
             
              temp=temp->next;
             }
             //check for invalid position
             insertAtEnd(value);
             

        }
    }
}

void updateAtPosition(int position, int newValue)

{
    int pos=0;
    LinkedList *temp=head;
    while(temp->next != NULL)
    {
        pos++;
        if(pos==position)
        {
            temp->data=newValue;
            return;
        }
        temp=temp->next;
    }
}

void deleteAtBeginning()
{
    if(len==0)
    printf("Nothing to delete\n");
    else{
    LinkedList *temp=head;
    temp=head->next;
    head->next=NULL;
    head=temp;
    len--;
    }
    
}

void deleteAtEnd()
{
     if(len==0)
    printf("Nothing to delete\n");
    else{
    LinkedList *temp=head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    len--;
    }
}

void deleteAtPosition(int position)
{
            if(position==1)
            {
                deleteAtBeginning();
                
                
            }
            else{
              
             int pos=0;
             LinkedList* temp=head;
             while(temp->next != NULL)
             {
                 pos++;
              
             if(pos==position-1)
             {
                  LinkedList* t=temp->next->next;
                  
                  
                  temp->next=temp->next->next;
                  t=NULL;
                  return;
                 
             }
             temp=temp->next;
             
              
             }
             len--;}
    
}