#include<stdio.h>
#include<stdlib.h>
struct node
{
int id;
int age;
float gpa;
char name[100];
struct node *next;
};
struct node *head=NULL;

void add_student(struct node **head);
void print_student(struct node *head,int id);
void update_student(struct node **head,int id);
int Get_Length(struct node *head);
void Display_All_Nodes(struct node *head);
void delete_node(struct node **head,int id);
int average_gpa(struct node *head);



int main()
{
int UserChoice = 0;
int length=0;
    int avg = 0;

    printf("-> Hello to Student Managemnt app\n");
    while(1){
        int id=0;

        printf("\n");
        printf("===============================\n");
        printf("-> 1) add_student \n");
        printf("-> 2) print_student\n");
        printf("-> 3) update_student \n");
        printf("-> 4) Get_Length \n");
        printf("-> 5) delete_node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) average_gpa \n");
        printf("-> 8) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
               add_student(&head);
            break;
            case 2:
                printf("Enter the id \n");
                scanf("%i",&id);
                print_student(head,id);
            break;
            case 3:
                scanf("%i",&id);
                update_student(&head,id);
            break;
            case 4:
               length= Get_Length(head);
               printf("length : << %i >> Nodes\n", length);
            break;
            case 5:
                scanf("%i",&id);
                delete_node(&head,id);
            break;
            case 6:
                Display_All_Nodes(head);
            break;
            case 7:
                avg = average_gpa(head);
                printf("avg : << %i >> Nodes\n", avg);
            break;
            case 8:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;

}
void add_student(struct node **head)
{
struct node *temp =NULL;
struct node *last =NULL;
temp= (struct node *)malloc(sizeof(struct node ));
if(temp==NULL)
{
printf("error\n");
}
else
{
    printf("Enter id and age and GPA\n");
    scanf("%i %i %f",&temp->id,&temp->age,&temp->gpa);
    fflush(stdin);
    printf("Enter name\n");
    gets(temp->name);
if(*head==NULL)
{
*head=temp;
temp->next=NULL;
}
else
{
    last=*head;
while(last->next!=NULL)
{
   last=last->next;
}
last->next=temp;
temp->next=NULL;
}

}


}
void print_student(struct node *head,int id)
{
struct node *current=head;
int is_exist=0;

while(current!=NULL)
{
    if(current->id==id){
        is_exist=1;
        break;}
    else {
current=current->next;
}
}if(is_exist){
printf("%i\t%i\t%f\t%s",current->id,current->age,current->gpa,current->name);
}
else
    {
        printf("not found \n");
    }

}

void update_student(struct node **head,int id)
{
struct node *current=*head;
int is_exist=0;
if(*head==NULL)
{
printf("error\n");
}
else
{
while(current->next!=NULL)
{
    if(current->id==id){
        is_exist=1;
        break;}
    else {
current=current->next;
}
}
if(is_exist){
printf("Enter new id and age and gpa\n");
    scanf("%i %i %f",&current->id,&current->age,&current->gpa);
    fflush(stdin);
    printf("Enter new name\n");
    gets(current->name);}
    else {}
}


}
int Get_Length(struct node *head){
    struct node *TempNode = head;
    int NodeCount = 0;

    while(TempNode != NULL){
        NodeCount++;
        TempNode = TempNode->next;
    }

    return NodeCount;
}
void Display_All_Nodes(struct node *head){
    struct node *current = head;

    if(NULL == current){
        printf("List is empty !! \n");
    }
    else{
        while(current != NULL){
           printf("name : %s\nId: %i\nage: %i\ngpa: %f\n",current->name,current->id,current->age,current->gpa);
            current = current->next;
            printf("==========================================\n");
        }
        if(NULL == current){
            printf("NULL \n");
        }
    }
}
void delete_node(struct node **head, int id) {
    struct node *current = *head;
    struct node *prev = NULL;

    // If the list is empty
    if (*head == NULL) {
        return;
    }

    // Check if the head node itself holds the id to be deleted
    if (current->id == id) {
        *head = current->next; // Change head
        free(current);         // Free old head
        return;
    }

    // Search for the node to be deleted, keep track of the previous node
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    // If id was not present in linked list
    if (current == NULL) {
        return;
    }

    // Unlink the node from linked list
    prev->next = current->next;

    free(current); // Free memory
}
int average_gpa(struct node *head)
{ int count=0; float sum=0.0;
struct node *current=head;
while(current!=NULL)
    {
    sum=sum+current->gpa;
    count++;
    current=current->next;
    }
    float avg=sum/count;
    return avg;
}
