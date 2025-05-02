#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "library.h"
#include "procedures.h"

/**Global variables**/
tabu tabuniv;                          //array of universities
tabe tabepreuve;                       //array of sport events
element tabjru[20][45];                //matrix of athletes
int maxuniv;                           //maximum size of tabunive
int maxepreuve;                        //maximum size of tabepruve
int num;                               //number of the athlete

                                       /**main program**/

int main()
{

    /**Variables**/
    int choice;                        //choice of operation
    char repeat;                       //used to know if the user wants to repeat operation
    char event[30];                    //name of event
    char institution[100];             //name of institution
    char name[25];                     //name of athlete
    int ne;                            //index of event
    int nu;                            //index of institution
    int find;                          //receives the sanath function results {1=true, 0=false}
    bool find1, find2;                 //used to check if institution or event exists
    int athnum;                        //number of the athlete

    /**initialization**/
    maxuniv=45;                        //initialize the number of universities
    maxepreuve=20;                     //initialize the number of events
    num=1;                             //initialize the number of athlete
    srand(time(0));                    //generate a seed for random functions

    /**Welcome heading**/
    welcome();
    system("pause > nul");
    system("cls");

    realised_by();
    system("pause > nul");
    system("cls");

    /**Display important note**/
    note();
    system("pause > nul");
    system("cls");

    create_tabjru();                   //create the matrix of linked lists
    printf("\n\t- Creation of athletes matrix accomplished successfully.\n");

    do{

        /**Introducing Menu**/
        menu();

        /**Introduce Choice**/
        choice = get_choice();


        /**study each case of choice**/
        switch (choice)
        {
        case 1:
            do{
                printf("\n%-30s\t- Enter athlete's name: "," ");//get athlete's name
                getchar();             // Consume the newline character left in the buffer
                read_string(name,25);  //read the name of the athlete

                printf("%-30s\t- Enter institution name: "," ");//get institution name
                read_string(institution,100);//read the name of institution

                printf("%-30s\t- Enter event name: "," ");//get events name
                read_string(event,30); //read the name of event

                inserath(institution,event,name);//add the athlete

                repeatop(&repeat);

            }while(repeat=='y');       //stop operation if repeat <> y

            printf("\n"BOLD BLUE);draw_line('=',156);printf(RESET);//draw a separating line
            system("cls");

            break;

        case 2:                        /**list the athletes of an institution**/
            do{
                printf("\n%-30s\t- Enter institution name: "," ");//get institution name
                getchar();
                read_string(institution,100);//read the name of institution

                listath(institution);  //list the athletes of institution

                repeatop(&repeat);

            }while(repeat=='y');

            printf("\n"BOLD BLUE);draw_line('=',156);printf(RESET);//draw a separating line
            system("cls");

            break;

        case 3:                        /**check if no athlete participates in an event**/

            do{
                printf("\n%-30s\t- Give the name of the event: "," ");//get event name
                getchar();
                read_string(event,30); //read the name of event

                event_exist(event,&ne,&find1);//check if the event exists + get its index
                if (find1==true)
                {
                    find=sanath(ne);
                    //message to display
                    if (find==1){
                        printf(YELLOW"\n\t\t--> There are no participants in this event\n"RESET);
                    }else{
                        printf(YELLOW"\n\t\t--> There are participants in this event\n"RESET);
                    }
                }else{//handle the case if event entered was not found
                            printf(BOLD"\n%-30s\tERROR: This event was not found!!\n"RESET," ");
                }

                repeatop(&repeat);

            }while(repeat=='y');

            printf("\n"BOLD BLUE);draw_line('=',156);printf(RESET);//draw a separating line
            system("cls");

            break;

        case 4:                        /**display tabjru content**/

            print_tabjru();

            printf("\n"BOLD BLUE);draw_line('=',156);printf(RESET);//draw a separating line
            system("cls");

            break;

        case 5:                        /**delete institution**/

            do {
                printf("\n%-30s\t- Enter institution name: "," ");
                getchar();
                read_string(institution,100);//read the name of institution

                delet(institution);    //delete the institution

                repeatop(&repeat);

            }while(repeat=='y');

            printf("\n"BOLD BLUE);draw_line('=',156);printf(RESET);//draw a separating line
            system("cls");

            break;

        case 6:                        /**delete athlete**/

            do {
                printf("\n%-30s\t- Enter institution name: "," ");
                getchar();
                read_string(institution,100);//read the name of institution

                printf("%-30s\t- Enter event name: "," ");
                read_string(event,30); //read the name of event

                printf("%-30s\t- Enter athlete's number: "," ");
                scanf("%d",&athnum);   //read the number of athlete

                instit_exist(institution, &nu, &find1);// Check if the institution exists
                if (find1 == false)
                {
                    printf(BOLD"\n%-30s\tERROR: The institution name does not exist!!\n"RESET," ");// institution doesn't exist
                }

                event_exist(event, &ne, &find2);// Check if the event exists
                if (find2 == false)
                {
                    printf(BOLD"\n%-30s\tERROR: The event name does not exist!!\n"RESET," "); //event doesn't exist
                }

                if(find1==true && find2==true)
                {
                    supath(nu,ne,athnum);
                }

                getchar();
                repeatop(&repeat);

            }while(repeat=='y');

            system("pause > nul");
            printf("\n"BOLD BLUE);draw_line('=',156);printf(RESET);//draw a separating line
            system("cls");

            break;

        case 7:                        /**delete events that have no participants**/

            supligne();

            system("pause > nul");
            printf("\n"BOLD BLUE);draw_line('=',156);printf(RESET);//draw a separating line
            system("cls");

            break;

        case 8:                        /**end program**/

            printf(BOLD BLUE"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%-20s--------------------------------------------------{End of Program}--------------------------------------------------\n"RESET," ");

            break;
        }

    }while(choice!=8);

    return 0;
}


