#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// declare struct students' information include name, age, ID, score
struct node 
{
    int age;
    int score1, score2, score3,ID;
    char nameSV[50];
    struct node *next;
};

struct node *top = NULL;
int count=0;
// declare functions used in this program
void display();
void push(int item, int item2, int item3, int item4, int item5, const char name[50]);
void pop();
char Capitalize_each_word(char chuoi[]);
void search(struct node* top, int x) ;
int bubbleSort(struct node** top, int count) ;
struct node* swap(struct node* ptr1, struct node* ptr2) ;
//main program
int main()
{
    int  ch, age, score1, score2, score3, ID, ID1;
    char name[50],chuoi;
    do
    {
        printf("\n\nStack Menu\n1. Push \n2. Pop\n3. Display\n4. Search ID in list\n5. Sorting ascending according to name(after inputting)\n0. Exit\n");
        do
		{
			printf("\nEnter Choice 0-4? : ");
            scanf("%d", &ch); 
			fflush(stdin);  // delete the cache
            if(!(ch>=0&&ch<=5))
                printf("please choose again from 0 to 4 !!!");
		}while(!(ch>=0&&ch<=5));  //check range for selection
		fflush(stdin); // delete the cache
        switch (ch)
        {
            case 1: // push
            	printf("\nEnter student 's name: ");
                fgets(name, sizeof(name), stdin);  // read string
                Capitalize_each_word(name);        // call fuction
                printf("\nEnter age: ");
                scanf("%d", &age);
                printf("\nEnter score1: ");
                scanf("%d", &score1);
                printf("\nEnter score2: ");
                scanf("%d", &score2);
                printf("\nEnter score3: ");
                scanf("%d", &score3);
                printf("\nEnter student ID: ");
                scanf("%d", &ID);
                push(age, score1, score2, score3, ID, name); // call fuction PUSH
                break;
            case 2: //pop
                pop();
                break;
            case 3:  // print out student list
                display();
                break;
            case 4:  // search student through ID
            	printf("input your ID you want to search: ");
                scanf("%d",&ID1);
            	search(top, ID1) ;
            	break;
            case 5:  // sort 
                bubbleSort(&top, count) ;
                display();
                break;
        }
    }while (ch != 0);
}

void push(int item, int item2, int item3, int item4, int item5, const char name[50])
{
    struct node *ptr = malloc(sizeof(struct node));
    strcpy(ptr->nameSV,name);
    ptr->age = item;
    ptr->score1 = item2;
    ptr->score2 = item3;
    ptr->score3 = item4;
    ptr->ID = item5;
    ptr->next = top;  // create new link
    top = ptr;
    count++;
}

void display()
{
	int i=1;
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
    	printf("------------------------------\n");
    	printf("Student %d:\n",i);
    	printf("Student name: %s\n",temp->nameSV);
        printf("Age: %d\n", temp->age);
        printf("Score 1: %d\n", temp->score1);
        printf("Score 2: %d\n", temp->score2);
        printf("Score 3: %d\n", temp->score3);
        printf("ID: %d\n", temp->ID);
        temp = temp->next;
        i++;
    }
    printf("There are %d students you inputted in the list.\n", count);
}

void pop()
{
    if (top == NULL)
    {
        printf("\n\nStack is empty ");
    }
    else
    {
        struct node *temp;
        temp = top;
        top = top->next;
        printf("\ninformation of student has ID: %d has deleted", temp->ID);
        free(temp);  // delete memory
        count--;     // node decrese
    }
}
// check and change name to standard format with capital letter of each word of name and no redundant blank of each word
char Capitalize_each_word(char chuoi[])
{
	int i,j,l = strlen(chuoi);
	// delete redundant blank
	for(i=0; i < l;i++)
	{
	    if (chuoi[i] == ' ' && chuoi[i+1] ==' ' )
	    {
	        for(j=i; j<l; j++)	
	            chuoi[j] = chuoi[j+1];
	        l--;   // the number of character in string decreses
	        i--;   // i increases as for loop, so we decrease i
		}
	}
	// first character to capital letter
	if (chuoi[0] >= 'a' && chuoi[0]<= 'z')
		chuoi[0]-=32;
	// capital letter of each word
	for (i=0; i < l;i++)
	{
		if (chuoi[i] == ' ' )
		    if (chuoi[i+1] >= 'a' && chuoi[i+1]<= 'z')
		        chuoi[i+1]-=32;
	}
	return chuoi[50];
}
// fuction to search student information through ID
void search(struct node* top, int x) 
{ 
    int item, item2,  item3, item4, item5, check=0; const char name[50];
    struct node* current = top;  // Initialize current 
    while (current != NULL) 
    { 
        if (current->ID == x) 
        {
        	printf("Student name: %s\n",current->nameSV);  // print student information
        	printf("Age: %d\n", current->age);
        	printf("Score 1: %d\n", current->score1);
        	printf("Score 2: %d\n", current->score2);
        	printf("Score 3: %d\n", current->score3);
        	printf("ID: %d\n", current->ID);
        	check+=1;
        	current = current->next; 
		} 
        else
			current = current->next; 
    }
    if (check == 0)
	    printf("This ID doesn't exist in list!");
} 
  
/* function to swap data of two nodes a and b*/
struct node* swap(struct node* ptr1, struct node* ptr2) 
{ 
    struct node* tmp = ptr2->next; 
    ptr2->next = ptr1; 
    ptr1->next = tmp; 
    return ptr2; 
} 
int bubbleSort(struct node** top, int count) 
{ 
    struct node** h; 
    int i, j, swapped; 
    for (i = 0; i <= count; i++) { 
  
        h = top; 
        swapped = 0; 
  
        for (j = 0; j < count - i - 1; j++) { 
  
            struct node* p1 = *h; 
            struct node* p2 = p1->next; 
  
            if (strcmp(p1->nameSV, p2->nameSV) > 0) { 
  
                /* update the link after swapping */
                *h = swap(p1, p2); 
                swapped = 1; 
            } 
  
            h = &(*h)->next; 
        } 
  
        /* break if the loop ended without any swap */
        if (swapped == 0) 
            break; 
    } 
} 
