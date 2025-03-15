#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100 // Define a constant SIZE with a value of 100

/********************************************************************/
                   //Implementation of Stack of Char
/********************************************************************/
typedef struct nodeChar* NodeChar;
typedef struct nodeChar* StackChar;
struct nodeChar { // Implementation of  char Node
    char Data ;
    NodeChar Next ; //points to the next Node
};

StackChar MakeStackChar (){  //Creat a new Stack of character
    StackChar Head = (StackChar) malloc(sizeof (struct nodeChar)); // Allocate memory for the stack
    Head->Next = NULL ; // Set the next pointer of the stack to NULL
    return Head ; // Return the created head
}

void pushChar (char x , StackChar stack){ // Function to Push Data to the Stack
    NodeChar newNode = (NodeChar) malloc(sizeof (struct nodeChar));  // Allocate memory for a new node of type NodeChar
    newNode->Next = stack->Next;  // Set the Next pointer of the new node to the current top of the stack
    stack->Next = newNode; // Set the Next pointer of the stack to the new node, making it the new top of the stack
    newNode->Data = x;  // Assign the value x to the Data member of the new node
}

char popChar (StackChar stack){ //Function to return and delete the most recently added element
    char x = '\0'; // Initializing x with the null character
    if (stack->Next != NULL){
        NodeChar ptr = stack->Next;
        stack->Next = ptr->Next;
        x = ptr->Data;//Assign the value x to the Data member of the ptr Node
        free(ptr); // Free the memory allocated for the ptr node
    }
    return x ;
}

char peekChar (StackChar stack){ //Function to returns the most recently added element
    char x = '\0'; // Initializing x with the null character
    if (stack->Next != NULL)   // If the stack is not empty assign the value of the first element to x.
        x = stack->Next->Data;
    return x ; // Return the value of x
}

/********************************************************************/
               //Implementation of Stack of Integer
/********************************************************************/
typedef struct nodeInteger* NodeInteger;
typedef struct nodeInteger* StackInteger;
struct nodeInteger { // Implementation of  char Node
    int Data ;
    NodeInteger Next ; //points to the next Node
};

StackInteger MakeStackInteger (){ //Creat a new Stack of integer
    StackInteger Head = (StackInteger) malloc(sizeof (struct nodeInteger)); // Allocate memory for the stack
    Head->Next = NULL ; // Set the next pointer of the stack to NULL
    return Head ; // Return the created head
}

void pushInteger (int x , StackInteger stack){ // Function to Push Data to the Stack
    NodeInteger newNode = (NodeInteger) malloc(sizeof (struct nodeInteger)); // Allocate memory for a new node of type NodeInteger
    newNode->Next = stack->Next; // Set the Next pointer of the new node to the current top of the stack
    stack->Next = newNode; // Set the Next pointer of the stack to the new node, making it the new top of the stack
    newNode->Data = x; // Assign the value x to the Data member of the new node
}

int popInteger (StackInteger stack){ //Function to return and delete the most recently added element
    int x = -1; // Initializing x with -1.
    if (stack->Next != NULL){  // Check if the stack is not empty.
        NodeInteger ptr = stack->Next; // Create a  pointer ptr and set it to point to the top element of the stack
        stack->Next = ptr->Next;  // Update the Next pointer of the stack to skip the top element and point to the next element.
        x = ptr->Data; // Retrieve the value of the top element and assign it to x.
        free(ptr); // Deallocate memory for the top element.
    }
    return x ;  // Return the value of x.
}

int peekInteger (StackInteger stack){ //Function to returns the most recently added element
    int x = '\0';
    if (stack->Next != NULL)   // If the stack is not empty assign the value of the first element to x.
        x = stack->Next->Data;
    return x ; //return the value of x
}

/********************************************************************/
                    //Implementation of Linked List
/********************************************************************/
typedef struct nodeList* NodeList; //creat a new name for the nodeList* Called NodeList.
typedef struct nodeList* LinkedList; //creat a new name for the nodeList* Called LinkedList.
struct nodeList{ //Defines a struct called nodeList which has two fileds.
    char Array[SIZE];
    NodeList Next ; //points to the next Node
};

LinkedList MakeList (){ //Function to creat a list
    LinkedList Head = (LinkedList) malloc(sizeof (struct nodeList)); // Allocate memory for the list
    Head->Next = NULL ; // Set the next pointer of the list to NULL
    return Head ; // Return the created list
}

void Insert (char Array[] , LinkedList List){ //Function to insert a new Node
    NodeList newNode = (NodeList) malloc(sizeof (struct nodeList)); // Allocate memory for a new node
    newNode->Next=NULL; // Set the next pointer of the list to NULL
    strcpy(newNode->Array,Array); //Save array to the node
    NodeList ptr = List ;

    while (ptr->Next != NULL)
        ptr = ptr->Next;  //Move to the next node

    ptr->Next = newNode;
}

/********************************************************************/

/********************************************************************/

LinkedList ReadFile(){ //function to Read From a file
    char name [20]; //define array to save the file name
    printf("please enter the name of file:\n");
    scanf("%s",name);
    FILE* input = fopen(name,"r"); // Open the file for reading
    if (input == NULL){
        printf("the file doesn't exit\n");
        return NULL;
    }
    LinkedList List = MakeList(); //Creat linked list

    int x = getc(input); // Read the next character
    while (x != EOF){
        while (x == '\n')
            x = getc(input);

        char Array [SIZE];
        int count = 0 ;
        while (x != '\n' && x != EOF){
            if (x != ' ') {
                if (x=='-' && Array[count-1]=='-' ){
                    Array[count-1] = (char) '+';
                }
                else if (x=='-' && Array[count-1]=='+'){
                    Array[count-1] = (char) '-';
                }
                else{
                    Array[count] = (char) x;
                    count++;
                }
            }
            x = getc(input);
        }
        Array[count]='\0';
        Insert(Array,List);
    }

    fclose(input);
    return List ;
}

int IsValid (char Array[]){
    StackChar S = MakeStackChar();
    int i =0 ;

    if (Array[i]=='+' || Array[i]=='*' || Array[i]=='/' || Array[i]=='-')
        return 9;

    for (i=0 ;Array[i] != '\0';i++){
        if (Array[i]=='(' || Array[i]=='[')
            pushChar(Array[i],S);
        else if (Array[i]==')'){
            if (peekChar(S)=='[')
                return 2;
            else if (peekChar(S)=='\0')
                return 3;
            popChar(S);
        }
        else if (Array[i]==']'){
            if (peekChar(S)=='(')
                return 4;
            else if (peekChar(S)=='\0')
                return 5;
            popChar(S);
        }

        if ((Array[i]=='(' || Array[i]=='[') && Array[i-1]>=48 && Array[i-1]<=57)
            return 6;
        else if ((Array[i]==')' || Array[i]==']') && Array[i+1]>=48 && Array[i+1]<=57)
            return 7;

        if(Array[i]=='+' || Array[i]=='*' || Array[i]=='/' || Array[i]=='-')
            if (Array[i+1]=='+' || Array[i+1]=='*' || Array[i+1]=='/' || Array[i+1]=='-')
                return 8;

    }

    if (peekChar(S) != '\0'){
        if (popChar(S)=='(')
            return 4 ;
        else
            return 2 ;
    }

    if (Array[i-1]=='+' || Array[i-1]=='*' || Array[i-1]=='/' || Array[i-1]=='-')
        return 10;

    return 1;
}

void PrintReason (int x){
    if (x==2)
        printf("[ is not close\n");
    else if (x==3)
        printf(") is not open\n");
    else if (x==4)
        printf("( is not close\n");
    else if (x==5)
        printf("] is not open\n");
    else if (x==6)
        printf("there is no operator before brackets\n");
    else if (x==7)
        printf("there is no operator after brackets\n");
    else if (x==8)
        printf("there is tow consecutive operator\n");
    else if (x==9)
        printf("there is operator at beginning\n");
    else if (x==10)
        printf("there is operator at end\n");
}

void Reverse (char RevArray[] ,char array[]){
    int size = strlen(array) ,i,j;

    for (i=size-1,j=0 ;i>=0;i--,j++){
        if(array[i]=='(')
            RevArray[j]=')';
        else if(array[i]==')')
            RevArray[j]='(';
        else if(array[i]=='[')
            RevArray[j]=']';
        else if(array[i]==']')
            RevArray[j]='[';
        else
            RevArray[j]=array[i];
    }
    RevArray[size]='\0';
}

int Priority (char c){ //Function to to check priority
    switch (c) {
        case '+':
        case '-':   return 1;
        case '*':
        case '/':   return 2;
        case '^':   return 3;
        default :   return 0;
    }
}

void convertToPrefix (char prefix[],char infix[]){
    char array [SIZE];
    Reverse(array,infix);
    StackChar S = MakeStackChar();
    int i ,j ;

    for (i=0 , j=0; array[i] !='\0' ; i++){
        if (array[i]=='(' || array[i]=='['){
            pushChar(array[i],S);
        }
        else if (array[i] == ')' || array[i] == ']') {
            while (peekChar(S) != '(' && peekChar(S) != '[' ) {
                prefix[j++] = ' ';
                prefix[j++] = popChar(S);
            }
            popChar(S);
        }
        else if (array[i]>='0' && array[i]<= '9'){
            prefix[j++]=array[i];
        }
        else{
            while (Priority(array[i]) < Priority(peekChar(S)) && peekChar(S) != '\0') {
                prefix[j++]=' ';
                prefix[j++] = popChar(S);
            }
            pushChar(array[i],S);
            prefix[j++]=' ';
        }
    }

    prefix[j++] = ' ';
    while (peekChar(S) != '\0') {
        prefix[j++] = popChar(S);
        prefix[j++] = ' ';
    }

    prefix[j++] = '\0';
    char temp [SIZE];
    Reverse(temp,prefix);
    strcpy(prefix,temp);
}


/********************************************************************/

/********************************************************************/
int main (){


    return 0;
}

