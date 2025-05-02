#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdbool.h>

/** Define color escape sequences**/
#define RESET   "\033[0m"
#define BOLD    "\033[3;1m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"


                                        /**General Declarations**/

/**types**/
typedef struct athlete                 //structure for one athlete that compose the LLL
{
    int num;                           //number of the athlete
    char name[25];                     //name of the athlete
    struct athlete *next;              //pointer on the next node
}athlete;

typedef struct element                 //structure for tabjru element
{
    athlete *head;                     //head of the lll
    int athnum;                        //number of athletes in the lll
}element;

typedef char tabu[45][100];            //type for tabuniv

typedef char tabe[20][30];             //type for tabepreuve


/**Abstract machine**/
void ALLOCATE_CELL(athlete **P);
void FREE (athlete *P);
athlete* NEXT (athlete *P);
char* CELL_NAME(athlete *P);
int CELL_NUMBER(athlete *P);
void ASS_ADR (athlete *P,athlete *Q);
void ASS_NAME(athlete *P,char name[]);
void ASS_number(athlete *P,int num);

/**Other procedures**/
int random_number(int min,int max);
void random_name(const char* names[], char name[]);
void fill_athlete(char name[], athlete **p, athlete **head, athlete **prec) ;
void print_athlete(athlete **p);
void event_exist (char event[], int *ne , bool *find1);
void instit_exist (char instit[], int *nu , bool *find2);
void addFirst(char name[],int nu,int ne);
void delete_inst(int nu);
void free_list(int nu,int ne);

/**User Interface Procedures**/
void read_string(char string[],int strl);
void repeatop(char *repeat);
void draw_line(char character,int l);
void draw_underline(char string[],char character);
void menu();
void welcome();
void realised_by();
int get_choice();



#endif // LIBRARY_H

