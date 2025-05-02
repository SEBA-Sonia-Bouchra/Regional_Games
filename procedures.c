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
element tabjru[20][45];               //matrix of athletes
int maxuniv;                           //maximum size of tabunive
int maxepreuve;                         //maximum size of tabepruve
int num;                               //number of the athlete

                                       /**Main Procedures**/

//=====================================================================================================================================================//

/**Procedure that creates the array of institution "tabuniv" and the array of events "tabepreuve" **/

void create_tabuniv_tabepreuve()
{
    /*Definition of tabuniv*/
    strcpy(tabuniv[0], "Centre universitaire d'Aflou");
    strcpy(tabuniv[1], "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar");
    strcpy(tabuniv[2], "Centre universitaire de Tipaza-Abdallah Morsli");
    strcpy(tabuniv[3], "Ecole des hautes etudes lcommerciales");
    strcpy(tabuniv[4], "Ecole Nationale Polytechnique");
    strcpy(tabuniv[5], "Ecole nationale superieure agronomique - Khalef Abdellah alias Kasdi Merbah");
    strcpy(tabuniv[6], "Ecole nationale superieure d'hydraulique - Arbaoui Abdellah");
    strcpy(tabuniv[7], "Ecole nationale superieure d'informatique");
    strcpy(tabuniv[8], "Ecole nationale superieure de journalisme et des sciences de l'information");
    strcpy(tabuniv[9], "Ecole nationale superieure de management");
    strcpy(tabuniv[10], "Ecole Nationale Superieure de Technologie");
    strcpy(tabuniv[11], "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral");
    strcpy(tabuniv[12], "Ecole Nationale Superieure des sciences politiques");
    strcpy(tabuniv[13], "Ecole Nationale Superieure des Technologies Avancees");
    strcpy(tabuniv[14], "Ecole nationale superieure des travaux publics - Francis Jeanson");
    strcpy(tabuniv[15], "Ecole Nationale Superieure en Mathematique");
    strcpy(tabuniv[16], "Ecole nationale superieure en statistique et en economie appliquee");
    strcpy(tabuniv[17], "Ecole Nationale Superieure en Intelligence Artificielle");
    strcpy(tabuniv[18], "Ecole nationale superieure veterinaire - Rabie Bouchama");
    strcpy(tabuniv[19], "Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili");
    strcpy(tabuniv[20], "Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi");
    strcpy(tabuniv[21], "Ecole normale superieure de Laghouat - Taleb Abderrahmane");
    strcpy(tabuniv[22], "Ecole Polytechnique d'architecture et d'Urbanisme - Hocine Ait Ahmed");
    strcpy(tabuniv[23], "Ecole Superieure de Commerce - Mouloud Kacem Nait Belkacem");
    strcpy(tabuniv[24], "Ecole Superieure de Gestion et d'Economie Numerique");
    strcpy(tabuniv[25], "Ecole Superieure des Sciences appliquees d'Alger");
    strcpy(tabuniv[26], "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger");
    strcpy(tabuniv[27], "Ecole Superieure en Sciences et Technologies de l'Informatique et du Numerique de Bejaia");
    strcpy(tabuniv[28], "Universite d'Alger 1 - Benyoucef Benkhedda");
    strcpy(tabuniv[29], "Universite d'Alger 2 - Abou el Kacem Saadallah");
    strcpy(tabuniv[30], "Universite d'Alger 3 - Brahim Soltane Chaibout");
    strcpy(tabuniv[31], "Universite de Bejaia - Abderrahmane Mira");
    strcpy(tabuniv[32], "Universite de Blida 2 - Lounici Ali");
    strcpy(tabuniv[33], "Universite de Ghardaia");
    strcpy(tabuniv[34], "Universite de la Formation Continue");
    strcpy(tabuniv[35], "Universite de Tamenghasset");
    strcpy(tabuniv[36], "Universite de Tizi Ouzou - Mouloud Maameri");
    strcpy(tabuniv[37], "Universite des sciences et de la technologie d'Alger, Houari Boumediene");
    strcpy(tabuniv[38], "Universite Blida 1 - Saad Dahlab");
    strcpy(tabuniv[39], "Universite de Bouira - Akli Mohand Oulhadj");
    strcpy(tabuniv[40], "Universite de Boumerdes - M'hamed Bougara");
    strcpy(tabuniv[41], "Universite de Djelfa - Ziane Achour");
    strcpy(tabuniv[42], "Universite de Khemis Miliana - Djilali Bounaama");
    strcpy(tabuniv[43], "Universite de Laghouat - Amar Telidji");
    strcpy(tabuniv[44], "Universite Medea - Yahia Fares");

    /*Definition tabepreuve*/
    strcpy(tabepreuve[0], "Aviron");
    strcpy(tabepreuve[1], "Athletisme");
    strcpy(tabepreuve[2], "Badminton");
    strcpy(tabepreuve[3], "Basketball");
    strcpy(tabepreuve[4], "Boxe");
    strcpy(tabepreuve[5], "Cyclisme");
    strcpy(tabepreuve[6], "Echecs");
    strcpy(tabepreuve[7], "Escrime");
    strcpy(tabepreuve[8], "Football");
    strcpy(tabepreuve[9], "Gymnastique");
    strcpy(tabepreuve[10], "Halterophilie");
    strcpy(tabepreuve[11], "Handball");
    strcpy(tabepreuve[12], "Judo");
    strcpy(tabepreuve[13], "Karate");
    strcpy(tabepreuve[14], "Natation");
    strcpy(tabepreuve[15], "Taekwondo");
    strcpy(tabepreuve[16], "Tennis");
    strcpy(tabepreuve[17], "Tennis de table");
    strcpy(tabepreuve[18], "Tir a l'arc");
    strcpy(tabepreuve[19], "Volleyball");
}

//=====================================================================================================================================================//

/**1- Procedure that creates the matrix of athletes lists "tabjru" **/

void create_tabjru()
{
    /*Local variables*/
    int i,j;                           //browse rows and lines of tabjru
    int k;                             //number of data of the LLL
    int athnum;                        //number of athletes for each institution in each event
    char name[25];                     //first name of athlete
    athlete *head,*p,*prec;            // pointers for creating the LLL

    create_tabuniv_tabepreuve();       //initialize the array of institutions and array of events

    /*Definition of names array*/
    const char* names[44] = {"Omar Hassani","Fatima Ali Said","Youssef Mahmoud","Layla Khalid","Amir Farid","Nour Ibrahimi","Zainab Saleh","Kareem Hamza",
    "Leila Mansour","Samir Abadi","Yasmin Nasser","Tariq Said","Rania Khalil","Malik Fawzi","Salma Mustafa","Karim Al-Masri","Dalia Rami","Jamal Saad",
    "Layla Hadi","Rami Naji","Nadia Hisham","Youssef Adnan","Amina Kamal","Kareem Nabil","Leila Raed","Samir Abadi","Yasmin Nasser","Tariq Said",
    "Rania Khalil","Malik Fawzi","Salma Mustafa","Karim Al-Masri","Dalia Rami","Jamal Saad","Lina Hadi","Rashid Aziz","Amira Jamal","Khaled Adel",
    "Nada Karim","Hadiya Sami","Ziad Tarek","Sanaa Farah","Raed Mansour","Layla Khoury",};
    /*creation of tabjru*/
    for (i=0;i<maxuniv;i++){           //browse institutions
        for (j=0;j<maxepreuve;j++){    //browse sport events
            athnum=random_number(0,16);//generate a random [0,15] number of athletes for each university in one event
            head=NULL;                 //initialize head for each LLL
            p=head;                    //initialize the other pointers
            prec=NULL;
            for (k=0;k<athnum;k++){    //browse through the the LLL
                random_name(names,name);//get a random name from the names array
                fill_athlete(name,&p,&head,&prec);//fill one athlete structure
            }
            tabjru[j][i].head=head;    //save the head of the list in tabjru element
            tabjru[j][i].athnum=athnum;//save the number of athletes in tabjru element
        }
    }

    for (i=0;i<maxuniv;i++){           //browse institutions for Halterophilie event (make an empty line)
            tabjru[10][i].head=NULL;
            tabjru[10][i].athnum=0;
    }
}

//=====================================================================================================================================================//

/**2- Procedure that adds an athlete to the lll of a given institution and event**/

void inserath(char institution[],char event[],char name[])
{
    int ne;                            //index of event
    int nu;                            //index of institution
    bool find1;                        //boolean for checking if event exists
    bool find2;                        //boolean for checking if institution exists

    event_exist (event , &ne , &find1);//get the index of event + existance state
    instit_exist (institution , &nu , &find2);//get the index of event + existance state

    if (find1 == true && find2 == true )//check if event and institution exist
    {
        if ( tabjru[ne][nu] .athnum == 15 )//check if number of athletes in the event reached maximum
        {
            printf(BOLD"\n%-30S\tERROR: Number of athletes has reached 15. Unable to add athlete!!\n"RESET," ");// there exist 15 athletes already
        }else{
            addFirst( name,nu,ne);    //update the head of the lll
            printf(YELLOW"\n\t\t--> Athlete %s added successfully for institution %s in the event of %s\n"RESET,name,institution,event);
            // success operation message
        }
    }
    else
    {
        if (find2 == false)              // if the instit does not exist
        {
            printf(BOLD"\n%-30s\tERROR: the institution name does not exist!!\n"RESET," ");
        }
        if (find1 == false )             // if the event does not exist
        {
            printf(BOLD"\n%-30s\tERROR: the event name does not exist!!\n"RESET," ");
        }
    }
}

//=====================================================================================================================================================//

/**3- Procedure that lists the athletes of an institution**/

void listath (char* institution )
{
    int nu;
    bool find2;
    int j,l;
    athlete *p0,*p1,*p2,*p3,*p4;


    instit_exist(institution , &nu , &find2);
    if ( find2 == true )               //check the existence of the instit
    {
        printf(YELLOW);printf("\n%-10s%s\n"," ",tabuniv[nu]);   //print institution name
        printf("%-10s"," ");
        draw_underline(tabuniv[nu],'-');printf(RESET);//draw a line under institution name
        printf("\n");
        printf("%-10s"," ");
        draw_line('-',137);                //beginning line of the table
        for (l=0;l<maxepreuve;l+=5){
            printf("%-10s|%-10s|%-24s|%-24s|%-24s|%-24s|%-24s|\n"," ","Event",
                   tabepreuve[l],tabepreuve[l+1],tabepreuve[l+2],tabepreuve[l+3],tabepreuve[l+4]);
            printf("%-10s"," ");
            draw_line('-',137);
            p0=tabjru[l][nu].head;
            p1=tabjru[l+1][nu].head;
            p2=tabjru[l+2][nu].head;
            p3=tabjru[l+3][nu].head;
            p4=tabjru[l+4][nu].head;

            for(j=0;j<15;j++)
            {
                printf("%-10s|%-10s|"," "," ");
                print_athlete(&p0);
                print_athlete(&p1);
                print_athlete(&p2);
                print_athlete(&p3);
                print_athlete(&p4);
                printf("\n");
            }
            printf("%-10s"," ");            //end line of table
            draw_line('-',137);
        }
        printf("\n");
    }else{
        printf(BOLD"\n%-30s\tERROR: The institution name does not exist!!\n"RESET," ");
    }
}

//=====================================================================================================================================================//

/**4- Function that returns a true (1) if no athlete is participating in an event**/

bool sanath (int ne)                   //ne: index of a given event
{
    /*Declarations*/
    bool find;
    int i;

    i=0;                               //initialize the index of institutions
    find = true;                       //initialize the boolean to true
    while ((i!=maxuniv) && (find==true))//loop for browsing tabjru until finding at least one athlete in the event
    {
        if ((tabjru[ne][i].head)!=NULL)  //not empty list
        {
            find=false;
        }else{
            i++;                       //next institution
        }
    }
    return find;
}

//=====================================================================================================================================================//

/**5- Procedure that displays the content of tabjru**/

void print_tabjru()
{
    /*Declarations*/
    int i,j,l;                         //used for browsing the tabjru
    athlete *p0,*p1,*p2,*p3,*p4;       //used for displaying 5 elements a time


    for (i=0;i<maxuniv;i++)
    {
        printf(YELLOW);printf("\n%-10s%s\n"," ",tabuniv[i]);   //print institution name
        printf("%-10s"," ");draw_underline(tabuniv[i],'-');printf(RESET);//draw a line under institution name
        printf("\n");
        draw_line('-',133);                //beginning line of the table
        for (l=0;l<maxepreuve;l+=5){
            printf("%-7s|%-24s|%-24s|%-24s|%-24s|%-24s|\n","Event",
                   tabepreuve[l],tabepreuve[l+1],tabepreuve[l+2],tabepreuve[l+3],tabepreuve[l+4]);
            draw_line('-',133);
            p0=tabjru[l][i].head;
            p1=tabjru[l+1][i].head;
            p2=tabjru[l+2][i].head;
            p3=tabjru[l+3][i].head;
            p4=tabjru[l+4][i].head;

            for(j=0;j<15;j++)
            {
                printf("%-7s|"," ");
                print_athlete(&p0);
                print_athlete(&p1);
                print_athlete(&p2);
                print_athlete(&p3);
                print_athlete(&p4);
                printf("\n");
            }
            draw_line('-',133);//end line of table

        }
        printf("\n");
        system("pause > nul");
        system("cls");
    }
}
//=====================================================================================================================================================//

/**6- Procedure that deletes an institution and frees occupied space**/

void delet(char institution[])
{
    /*local variables*/
    int nu;                            //index of institution
    bool find;                         //set to true if institution name is found
    int i,j;                           //used to parcourate arrays

    instit_exist(institution,&nu,&find);//test if institution exist and get its index

    if (find==false)                   //institution not found
    {
        printf(BOLD"\n%-30s\tERROR: Wrong institution name!!\n"RESET," ");//print error message
    } else {

        for (i=0;i<maxepreuve;i++)     //free space of the column representing the institution
        {
            free_list(nu,i);
        }
        //do shifting process
        for (i=0;i<maxepreuve;i++)     //browse through events (lines)
        {
            for ( j = nu; j < maxuniv-1; j++)//browse through institution (columns)
            {
                tabjru[i][j]=tabjru[i][j+1];//shift next element to left
            }
        }

        for (i=0;i<maxepreuve;i++)     //free space of the column representing the last institution (repeated)
        {
            free_list(maxuniv-1,i);
        }

        delete_inst(nu);               //delete institution of index nu from tabuniv + decrementing maxuniv

        printf(YELLOW"\n\t\t--> Institution deleted successfully\n"RESET);//print success message
    }
}

//=====================================================================================================================================================//

/**7- Procedure that deletes an athlete**/

void supath(int nu,int ne,int athnum)
{
    bool find;
    athlete *temp,*p,*prec;

    // Check if the athlete exists
    if (tabjru[ne][nu].head == NULL) // the list is empty
        {
        printf(BOLD"\n%-30\tERROR: There is no athlete in this list!!\n"RESET," ");// failed operation message
    }else{
        find=false;

        // Delete the athlete by name here we check the head
        p= tabjru[ne][nu].head;
        if (CELL_NUMBER(p)==athnum)
        {
            find=true;
            tabjru[ne][nu].head = NEXT(p);
            FREE(p);
            printf(YELLOW"\n\t\t--> The athlete of number %d has been deleted successfully.\n"RESET, athnum);// succeed operation message
        }else{

        // Search for the athlete with the given name
            prec=p;
            p=NEXT(p);
            while (p != NULL && find!=true)
            {
                if (CELL_NUMBER(p)==athnum)
                {
                    find=true;
                    ASS_ADR(prec,NEXT(p));
                    FREE(p);
                    printf(YELLOW"\n\t\t--> The athlete of number %d has been deleted successfully.\n"RESET, athnum);
                    tabjru[ne][nu].athnum--;
                    break;
                }else{
                    prec=p;
                    p =NEXT(p);
                }
            }
        }

        // If the athlete was not found, print an error message
        if (find==false)
        {
            printf(BOLD"\n%-30s\tError: The athlete number is wrong!!\n"RESET," ");
        }
    }
}


//=====================================================================================================================================================//

/**8- Procedure that deletes an empty event (line)**/

void supligne()
{
    int t,j,k;
    bool trouve;

    trouve = false;                    //initialize the boolean to false

    for (t=0;t<maxepreuve;t++)
    {
        if (sanath(t)==1)
        {
            trouve =true;

            for (k=0;k<maxuniv;k++)     //browse through events (lines)
            {
                for ( j = t; j < maxepreuve-1; j++)//browse through institution (columns)
                {
                    tabjru[j][k]=tabjru[j+1][k];//shift next element to left
                }
            }

            for (j=0;j<maxuniv;j++)     //free space of the column representing the last institution (repeated)
            {
                free_list(j,maxepreuve-1);
            }

            printf(YELLOW"\n\t\t--> event %s deleted successfully\n"RESET,tabepreuve[t]);
            delete_event(t);
        }
    }

    if (trouve==false)
        {
            printf(BOLD"\n%-30s\tError: There is no empty event\n"RESET," ");
        }
}

//=====================================================================================================================================================//




