#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

/**Global variables**/
tabu tabuniv;                          //array of universities
tabe tabepreuve;                       //array of sport events
element tabjru[20][45];               //matrix of athletes
int maxuniv;                           //maximum size of tabunive
int maxepreuve;                         //maximum size of tabepruve
int num;                               //number of the athlete

                                             /**Abstract Machine**/

//=====================================================================================================================================================//

/**Function to allocate memory for an athlete cell and return its address in P**/

void ALLOCATE_CELL(athlete **P)
{
    *P = malloc(sizeof(athlete));
}

//=====================================================================================================================================================//

/**Free the node of address P**/

void FREE (athlete *P)
{
    free(P);
}

//=====================================================================================================================================================//

/**Access to the Address field of the node referenced by P**/

athlete* NEXT (athlete *P)
{
    return P->next;
}

//=====================================================================================================================================================//

/**Access to the name of the node referenced by P**/

char* CELL_NAME(athlete *P)
{
    return P->name;
}

//=====================================================================================================================================================//

/**Access to the last name of the node referenced by P**/

int CELL_NUMBER(athlete *P)
{
    return P->num;
}

//=====================================================================================================================================================//

/**Assign to the Address field of the node referenced by P, the address Q**/

void ASS_ADR (athlete *P,athlete *Q)
{
    P->next=Q;
}

//=====================================================================================================================================================//

/**Assign to the name field of the node referenced by P, the value name**/

void ASS_NAME(athlete *P,char name[])
{
    strcpy(P->name,name);
}

//=====================================================================================================================================================//

/**Assign to the first number field of the node referenced by P, the value num**/

void ASS_number(athlete *P,int num)
{
    P->num=num;
}

//=====================================================================================================================================================//

                                             /**Other Procedures**/

//=====================================================================================================================================================//

/**Function that generates a random number by an interval [min,max]**/

int random_number(int min,int max)
{
    int random;

    random=min+(rand()%max);     //compute the random number within the interval

    return random;
}

//=====================================================================================================================================================//

/**Function that generates a random name**/
void random_name(const char* names[], char name[]) //names: array of names, names: output
{
    int random_index;

    random_index=random_number(0,44);  //get random index
    strcpy(name, names[random_index]); //get random name using index
}


//=====================================================================================================================================================//

/**Procedure that fills one athlete cell**/

void fill_athlete(char name[], athlete **p, athlete **head, athlete **prec)
{
    ALLOCATE_CELL(&(*p));
    if (*p == NULL) {                  //Handle memory allocation failure
        printf(BOLD"\n%-30s\tERROR: Memory allocation failed.\n"RESET," ");
        exit(EXIT_FAILURE);
    }
    ASS_NAME(*p,name);                 //Allocate memory for the name and copy it
    ASS_number(*p,num);                //Associate name to athlete
    ASS_ADR(*p,NULL);                  //associate the cell to null
    if (*head == NULL) {
        *head = *p;                    //save head of the list
    } else {
        ASS_ADR(*prec,*p);             //link the prec to the pointer
    }
    *prec = *p;                        //update prec
    num++;                             //update the athlete's number
}

//=====================================================================================================================================================//

/**procedure that prints one athlete**/
void print_athlete(athlete **p)
{
    if (*p!=NULL){
        printf("%-5d: %-17s|",CELL_NUMBER(*p),CELL_NAME(*p));//print name + number of the athlete
        *p=NEXT(*p);
    }else{
        printf("%-24s|","");
    }
}

//=====================================================================================================================================================//

/**Procedure that returns if an event exists and its index**/

void event_exist (char event[], int *ne , bool *find1)
{
    int j;                             //for browsing through tabepreuve

    *find1= false;
    for (j = 0; j < maxepreuve; j++)   //browse tabepreuve
    {
        if (strcmp(strlwr(tabepreuve[j]), strlwr(event)) == 0)//check if the name of the event exists strcmp function
        {
            *ne = j;                          //get the index
            *find1 = true;                    //update the boolean
            break;
        }
    }

}

//=====================================================================================================================================================//

/**Procedure that returns if an institution exists and its index**/

void instit_exist (char instit[], int *nu , bool *find2)
{
    int j;                             //for browsing through tabuniv

    *find2 = false;
    for (j = 0; j < maxuniv; j++)      //browse tabuniv
    {
        if (strcmp(strlwr(tabuniv[j]), strlwr(instit)) == 0)//check if the name of the institution exists with strcmp function
        {
            *nu = j;                   //get the index
            *find2 = true;             //update the boolean
            break;
        }
    }

}

//=====================================================================================================================================================//

/**Function to insert a new cell at the beginning of the linked list**/

void addFirst(char name[],int nu,int ne)
 {
    athlete *new_cell;

    ALLOCATE_CELL(&new_cell);          //allocate memory for the new cell
    ASS_NAME(new_cell,name);           //fill the athlete name
    ASS_number(new_cell,num);          //fill the athlete number
    ASS_ADR(new_cell,tabjru[ne][nu].head);//associate to new_cell's next head

    tabjru[ne][nu].head = new_cell;    //update the head
    tabjru[ne][nu].athnum++;           //update the number of athletes in the lll
    num++;                             //update the athlete's number
}

//=====================================================================================================================================================//

/**Procedure that deletes institution from tabuniv**/

void delete_inst(int nu)
{
    int i;

    maxuniv--;                         //decrement maxuniv
    for (i=nu;i<maxuniv;i++)
    {
        strcpy(tabuniv[i],tabuniv[i+1]);//do the shifting
    }
    tabuniv[maxuniv][0]='\0';           //eliminate the string of the last column
}

//=====================================================================================================================================================//

/**Procedure that deletes event from tabepreuve**/

void delete_event(int ne)
{
    int i;

    maxepreuve--;                      //decrement maxepreuve
    for (i=ne;i<maxepreuve;i++)
    {
        strcpy(tabepreuve[i],tabepreuve[i+1]);//do the shifting
    }
    tabepreuve[maxepreuve][0]='\0';    //eliminate the string of the last line
}

//=====================================================================================================================================================//

/**Procedure that frees allocation space occupied by a list**/

void free_list(int nu,int ne)
{
    athlete *p,*q;

    p=tabjru[ne][nu].head;             //initialize the pointer to the head of the list

    while (p!=NULL)
    {
        q=NEXT(p);                     //get the next cell @
        FREE(p);                       //free cell
        p=q;                           //update the pointer
    }
    tabjru[ne][nu].head=NULL;          //reset the head to null
    tabjru[ne][nu].athnum=0;           //reset number of athletes in the list to null
}

//=====================================================================================================================================================//


                                             /**Printing, reading Procedures**/

//=====================================================================================================================================================//

/**Procedure for reading strings**/

void read_string(char string[],int strl)
{
    fgets(string,strl,stdin);            //get the string from standard input
    string[strlen(string)-1]='\0';     //remove new line character
}

//=====================================================================================================================================================//

/**Procedure for repeating operation message**/

void repeatop(char *repeat)
{
    printf("\n\t- Do you want to do the operation again? (click on 'y' to repeat / any other key to leave): ");//show repeat message
    scanf("%c",&(*repeat));
    *repeat=tolower(*repeat);          //tolower function from ctype library allows changing the letter to lowercase
    printf("\n");
}

//=====================================================================================================================================================//

/**Procedure that draws a line of characters**/

void draw_line(char character,int l)
{
    int r;

    for(r=0;r<l;r++)                   //repeat the character l times
    {
        printf("%c",character);
    }
    printf("\n");
}

//=====================================================================================================================================================//

/**Procedure that draws a line under a string**/

void draw_underline(char string [],char character)
{
    int r;

    for(r=0;r<strlen(string);r++)      //repeat the character till the end of the string
    {
        printf("%c",character);
    }
    printf("\n");
}

//=====================================================================================================================================================//

/**Procedure that prints welcome message**/

void welcome()
{
    printf("\n\n\n\n\n\n"BOLD CYAN);
    printf("%-35s**        ** ****** **      *****   ****    ***  ***  ******    ******   ****    \n"," ");
    printf("%-35s**   **   ** **     **     **     **    ** **  **  ** **          **   **    **  \n"," ");
    printf("%-35s**   **   ** ****** **     **     **    ** **      ** ******      **   **    **  \n"," ");
    printf("%-35s ** **** **  **     **     **     **    ** **      ** **          **   **    **  \n"," ");
    printf("%-35s  ***   **   ****** ******  *****   ****   **      ** ******      **     ****    \n"," ");
    printf(RESET"\n\n"BOLD RED);
    printf("%-32s****** **  ** ******    *****   ******  *****  ******   ****   ***   **   ***   **    \n"," ");
    printf("%-32s  **   **  ** **        **   *  **     **   **   **   **    ** ****  ** **   ** **    \n"," ");
    printf("%-32s  **   ****** ******    *****   ****** **        **   **    ** ** ** ** ******* **    \n"," ");
    printf("%-32s  **   **  ** **        **  **  **     **  ***   **   **    ** **  **** **   ** **    \n"," ");
    printf("%-32s  **   **  ** ******    **   ** ******  *****  ******   ****   **   *** **   ** ******\n"," ");
    printf(RESET"\n\n"BOLD CYAN);
    printf("%-40s**    ** ***   ** ****** **   ** ******  *****  ****** ****** **    **\n"," ");
    printf("%-40s**    ** ****  **   **   **   ** **     **        **     **    **  ** \n"," ");
    printf("%-40s**    ** ** ** **   **   **   ** ******  *****    **     **     ****  \n"," ");
    printf("%-40s**    ** **  ****   **    ** **  **          **   **     **      **   \n"," ");
    printf("%-40s  ****   **   *** ******   ***   ******  *****  ******   **      **   \n"," ");
    printf(RESET"\n\n"BOLD RED);
    printf("%-55s *****    ***    ***  ***  ******  *****  \n"," ");
    printf("%-55s**   ** **   ** **  **  ** **     **      \n"," ");
    printf("%-55s**      ******* **      ** ******  *****  \n"," ");
    printf("%-55s**  *** **   ** **      ** **          ** \n"," ");
    printf("%-55s *****  **   ** **      ** ******  *****  \n"," ");
    printf(RESET);
}

//=====================================================================================================================================================//

/**procedure that displays the note**/

void realised_by()
{
    printf(BOLD);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%-53s", " ");
    draw_line('-', 57);
    printf("%-53s|%-55s|\n", " ", " ");
    printf("%-53s|%-7sTHIS TP IS REALIZED BY:%-25s|\n", " ", " ", " ");
    printf("%-53s|%-55s|\n%-53s|%4s- Seba Sonia Bouchra%-31s|\n", " ", " ", " ", " ", " ");
    printf("%-53s|%4s- Lamri Meriem%-37s|\n ", " ", " ");
    printf("%-52s|%4s- 1st year computer science, section C, group 11   |\n", " ", " ");
    printf("%-53s|%-55s|\n", " ", " ");
    printf("%-53s", " ");
    draw_line('-', 57);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf(RESET);
}

//=====================================================================================================================================================//

/**procedure that displays the note**/

void note()
{
    printf(RED"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%-57sIMPORTANT NOTE: \n"RESET," ");
    printf(BOLD);
    printf("\n%-54s- Expend the window for better display.\n"," ");
    printf("%-54s- Do not go above the range of characters for strings:\n"," ");
    printf("%-54sNames: 25 characters\n"," ");
    printf("%-54sInstitutions: 100 characters\n"," ");
    printf("%-54sEvents: 30 characters\n"," ");
    printf(RESET"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

//=====================================================================================================================================================//

/**Procedure that prints the menu**/

void menu()
{

        printf("\n\t- Please select the operation to be done from the following Menu:\n\n");

        printf(BOLD BLUE"%-33s========================================{ MENU }======================================\n"RESET," ");
        printf(BOLD BLUE"%-33s=                                                                                    =\n"RESET," ");
        printf(BOLD BLUE"%-33s="RESET," ");
        printf(BOLD"        + insert a new athlete: ......................................'1'           "RESET);
        printf(BOLD BLUE"=\n"RESET);
        printf(BOLD BLUE"%-33s="RESET," ");
        printf(BOLD"        + List the athletes of an institution: .......................'2'           "RESET);
        printf(BOLD BLUE"=\n"RESET);
        printf(BOLD BLUE"%-33s="RESET," ");
        printf(BOLD"        + Check if no athlete participates in an event: ..............'3'           "RESET);
        printf(BOLD BLUE"=\n"RESET);
        printf(BOLD BLUE"%-33s="RESET," ");
        printf(BOLD"        + Display the athletes table (event/university): .............'4'           "RESET);
        printf(BOLD BLUE"=\n"RESET);
        printf(BOLD BLUE"%-33s="RESET," ");
        printf(BOLD"        + Delete institution: ........................................'5'           "RESET);
        printf(BOLD BLUE"=\n"RESET);
        printf(BOLD BLUE"%-33s="RESET," ");
        printf(BOLD"        + Delete athlete: ............................................'6'           "RESET);
        printf(BOLD BLUE"=\n"RESET);
        printf(BOLD BLUE"%-33s="RESET," ");
        printf(BOLD"        + Delete event: ..............................................'7'           "RESET);
        printf(BOLD BLUE"=\n"RESET);
        printf(BOLD BLUE"%-33s="RESET," ");
        printf(BOLD"        + Quit program: ..............................................'8'           "RESET);
        printf(BOLD BLUE"=\n"RESET);
        printf(BOLD BLUE"%-33s=                                                                                    =\n"RESET," ");
        printf(BOLD BLUE"%-33s======================================================================================\n"RESET," ");

}

//=====================================================================================================================================================//

/**Function that returns the choice of the user**/

int get_choice()
{
    int c;

    do{
        printf("\n\t- Please enter the number of the corresponding operation: ");//read choice
        scanf("%d",&c);
        if (c!=1 && c!=2 && c!=3 && c!=4 && c!=5 && c!=6 && c!=7 && c!=8)
        {
            printf(BOLD"\n%-30s\tERROR: the number entered does not appear in the Menu!\n"RESET," ");
        }
    }while (c!=1 && c!=2 && c!=3 && c!=4 && c!=5 && c!=6 && c!=7 && c!=8);

    return c;
}

//=====================================================================================================================================================//

