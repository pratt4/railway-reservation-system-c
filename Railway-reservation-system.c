#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"

typedef struct
{
        int n;
        char Name[50];
        int age;
        char g;
        char emailid[100];
} pd;

typedef struct newtrain
{
        int tnum;
        char tname[50];
        char tsrc[50];
        char tdes[50];
} newtrain;

newtrain nt[10];
pd passdetails[10];

int loginadmin();
void profilesettings();
void displayadmins();
void addadmin();
void del(char *arr);
int ran();
void railwaydatabase();
void addtrain();
void deltrain();

void reservation();
void classify_age(int);
void printticket(int, char Name[50], int, char g, char em[50]);
void cancel();

void train_details();
void train_details2();
float fare();
int random_number(int lower, int upper, int count);
void dtrain_details();

char username1[20] = "pratik", password1[15] = "pass1";
char username2[20] = "tulasi", password2[15] = "pass2";
char username3[20] = "tanmai", password3[15] = "pass3";
char username4[20] = {-1}, password4[15];
char username5[20] = {-1}, password5[15];
char username6[20] = {-1}, password6[15];


char newtrain1[10][100];
char newtrain2[10][100];

char name1[20], pass1[20];

int i, temp = 0;
char ch, choice1, choice2[10], choice3[10] = "y", choice5[10], choice4, choice7[10];
int choice6;

int trainnumb;
static int n;
float f;

int main()
{
        // system("color f2");

        printf("\n\n\n\n");
        printf("\n|----------------------------------------------------------------------------|\n");
        printf("|                                                                            |\n|");
        printf(RED);

        printf(BOLD "                   Welcome to Railway Reservation System                   ");
        printf(RESET " |\n");

        printf("|                                                                            |\n");
        printf("|                                                                            |\n");

        printf("|          o x o x o x o . . .                                               |\n");
        printf("|         o      _____            _______________ ___=====__T___             |\n");
        printf("|       .][__n_n_|DD[  ====_____  |    |.\\/.|   | |   |_|     |_             |\n");
        printf("|      >(________|__|_[_________]_|____|_/\\_|___|_|___________|_|            |\n");
        printf("|      _/oo OOOOO oo`  ooo   ooo   o^o       o^o   o^o     o^o               |\n");
        printf("|   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+      |\n");

        printf("|                                                                            |\n");
        printf("|                                                                            |\n");
        printf("|----------------------------------------------------------------------------|\n");
        printf("|                                                                            |\n");
        printf("|\tLog in as:                                                           |\n");
        printf("|                                                                            |\n");

        printf("|           1. ADMIN                                                         | \n");
        printf("|                                                                            |\n");
        printf("|           2. USER                                                          | \n");
        printf("|                                                                            |\n");
        printf("|           0. EXIT                                                          | \n");
        printf("|                                                                            |\n");

        printf("|                                                                            |\n");
        printf("|                                                                            |\n");

        ;
        printf("|----------------------------------------------------------------------------|\n");
        printf("|                                                                            |\n");
        printf("|----------------------------------------------------------------------------|\n");
        printf("\n\tChoice:\t\t");
        scanf("\t%d", &ch);

        switch (ch)
        {
        case 1:
                system("cls");

                printf("\n----------------------------------------------------------------------------\n");
                printf("                     Welcome ADMIN");
                printf("\n----------------------------------------------------------------------------\n");
                printf("                                                                           \n");

                if (loginadmin() == 0)
                {
                        printf(RED);
                        printf(BOLD);
                        printf("\n\n\n\t!! INVALID CREDENTIALS ...... Enter Correct Username And Password !!\n\n");
                        printf(RESET);
                }

                else
                {
                        printf("\n\nlogin succesful");

                        do
                        {
                                system("CLS");
                                printf("\n---------------------------------------------\n");
                                printf("                   Menu        (admin)              ");
                                printf("\n---------------------------------------------\n");
                                printf("\n\t1. Calculate Fare \n\t");
                                printf("2. Check availability\n\t3. Book ticket/s and Display of booked ticket/s ");
                                printf("\n\t4. Cancel ticket \n\t5. Profile Settings\n\t6. Railway database\n\t0. EXIT \n\n\t");
                                printf("Choice:\t");
                                scanf("%d", &choice1);

                                switch (choice1)
                                {
                                case 0:
                                        exit(0);
                                        break;
                                case 3:
                                        system("CLS");
                                        printf("\n----------------------------------------------------------------------------\n");
                                        printf("                     Ticket Booking");
                                        printf("\n----------------------------------------------------------------------------\n");
                                        reservation();

                                        break;

                                case 1:

                                        printf("\n----------------------------------------------------------------------------\n");
                                        printf("                              FARE DETAILS");
                                        printf("\n----------------------------------------------------------------------------\n");
                                        dtrain_details();
                                        int temptn, tp;
                                        printf("\n\n\nenter the train number : ");
                                        scanf("%d", &temptn);
                                        printf("\nenter number of passengers:");
                                        scanf("%d", &tp);

                                        f = fare(temptn, tp);
                                        printf(GREEN);
                                        printf("\n\nTotal amount that need to be paid is : %2.f Rs ", f);

                                        printf(RESET);
                                        break;

                                case 6:
                                        system("CLS");
                                        railwaydatabase();
                                        break;
                                case 2:
                                        system("CLS");
                                        dtrain_details();
                                        int r;
                                        printf("\n\nenter the train number\n\n ");
                                        scanf("%d", &r);

                                        int n2 = ran();
                                        if (n2 > 0 && n2 < 25)
                                        {
                                                printf(RED);
                                                printf("\nTHERE ARE NO SEATS AVAILABLE\n");
                                                printf(RESET);
                                        }
                                        else
                                        {
                                                printf(GREEN);
                                                printf("AVALABLE SEATS : %d", n2);
                                                printf(RESET);
                                        }
                                        break;

                                case 4:
                                        system("CLS");
                                        cancel();
                                        // printf("Your ticket has been canceled");
                                        break;
                                case 5:
                                        system("CLS");
                                        profilesettings();
                                        break;
                                }
                                printf("\n----------------------------------------------------------------------------\n");
                                printf("\n\tWant to Continue[Main Menu] (y/n):\t");
                                scanf("%s", &choice2);
                                if (choice2 == "n")
                                {
                                        exit(0);
                                }
                                strlwr(choice2);

                        } while ((strcmp(choice3, choice2)) == 0);
                }
                break;

        case 2:
                do
                {
                        system("CLS");

                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                     Welcome user");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                                                                           \n");
                        printf("\n---------------------------------------------\n");
                        printf("                   Menu                    ");
                        printf("\n---------------------------------------------\n");
                        printf("\n\t1. Book ticket/s and Display of booked ticket/s \n\t");
                        printf("2. Fare details\n\t");
                        printf("3. Check availability\n\t4. Cancel ticket\n\t0. EXIT \n\n\t");
                        printf("Choice:\t");
                        scanf("%d", &choice1);
                        switch (choice1)
                        {

                        case 1:
                                system("CLS");
                                printf("\n----------------------------------------------------------------------------\n");
                                printf("                     Ticket Booking and display booked ticket/s              ");
                                printf("\n----------------------------------------------------------------------------\n");
                                reservation();

                                break;

                        case 2:
                                system("CLS");
                                printf("\n----------------------------------------------------------------------------\n");
                                printf("                              FARE DETAILS");
                                printf("\n----------------------------------------------------------------------------\n");
                                dtrain_details();
                                int temptn, tp;
                                printf("\n\n\nenter the train number : ");
                                scanf("%d", &temptn);
                                printf("\nenter number of passengers:");
                                scanf("%d", &tp);

                                f = fare(temptn, tp);
                                printf(GREEN);

                                printf("\n\nTotal amount that need to be paid is : %2.f Rs ", f);
                                printf(RESET);
                                break;

                        case 3:
                                system("CLS");
                                dtrain_details();
                                int r;
                                printf("\n\nenter the train number\n\n ");
                                scanf("%d", &r);

                                int n2 = ran();
                                if (n2 > 0 && n2 < 25)
                                {
                                        printf(RED);
                                        printf("\nTHERE ARE NO SEATS AVAILABLE\n");
                                        printf(RESET);
                                }
                                else
                                {
                                        printf(GREEN);
                                        printf("AVALABLE SEATS : %d", n2);
                                        printf(RESET);
                                }

                                break;

                        case 4:
                                system("CLS");
                                cancel();
                                // printf("Your ticket has been canceled");
                                break;
                        case 0:
                                system("CLS");
                                exit(0);
                                break;
                        }
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("\n\tWant to Continue[Main Menu] (y/n):\t");
                        scanf("%s", &choice2);

                        strlwr(choice2);
                } while ((strcmp(choice3, choice2)) == 0);

        case 3:
                exit(0);
                break;

        default:
                printf(RED);
                printf("\t\t\tINVALID CHOICE");
                printf(RESET);
        }
        return 0;
}

int loginadmin()
{

        printf("\t\tEnter the user name : ");
        scanf("%s", name1);

        printf("\n\t\tenter password : ");

        char c;
        i = 0;
        while (i <= 20)
        {
                pass1[i] = getch();
                if (pass1[i] == 13)

                        break;
                else
                        printf("*");
                i++;
        }
        pass1[i] = '\0';

        if (strcmp(username1, name1) == 0 && strcmp(password1, pass1) == 0 || strcmp(username2, name1) == 0 && strcmp(password2, pass1) == 0 || strcmp(username3, name1) == 0 && strcmp(password3, pass1) == 0 || strcmp(username4, name1) == 0 && strcmp(password4, pass1) == 0 || strcmp(username5, name1) == 0 && strcmp(password5, pass1) == 0 || strcmp(username6, name1) == 0 && strcmp(password6, pass1) == 0)
        {
                temp = 1;
        }

        return temp;
        // return 1;
}

void profilesettings()
{
        do
        {
                system("CLS");
                printf("\n---------------------------------------------\n");
                printf("              PROFILE SETTINGS                   ");
                printf("\n---------------------------------------------\n");
                printf("\n\t1. Display Admins and Passwords \n\t");
                printf("2. Add Admins ");
                printf("\n\t3. Delete Admin\n\t0. EXIT \n\n\t");
                printf("Choice:\t");
                scanf("%d", &choice4);
                switch (choice4)
                {
                case 1:
                        system("CLS");
                        displayadmins();
                        break;
                case 2:
                        system("CLS");
                        addadmin();
                        displayadmins();
                        break;

                case 3:
                        system("CLS");
                        int n;
                        printf("Enter the admin number that you need to delete : ");
                        scanf("%d", &n);

                        if (n == 1)
                                del(username1);
                        if (n == 2)
                                del(username2);
                        if (n == 3)
                                del(username3);
                        if (n == 4)
                                del(username4);
                        if (n == 5)
                                del(username5);
                        if (n == 6)
                                del(username6);

                        displayadmins();
                        break;
                case 0:
                        system("CLS");
                        exit(0);
                        break;
                }
                printf("\n----------------------------------------------------------------------------\n");
                printf("\n\t Want to Continue[Profile Setting] (y/n):\t");
                scanf("%s", &choice5);
                if (choice5 == "n")
                {
                        exit(0);
                }
        } while ((strcmp(choice3, choice5)) == 0);
}

void displayadmins()
{
        int count = 0;
        printf(RED);
        printf("\nCURRENT ADMINS AND THIER PASSWORDS ARE :\n");

        printf(RESET);
        if (username1[0] != -1)
        {
                printf("\nADMIN NAME: %s\n", username1);
                printf("PASSWORD :%s\n", password1);
                printf("---------------\n\n");
                count++;
        }
        if (username2[0] != -1)
        {
                printf("ADMIN NAME: %s\n", username2);
                printf("PASSWORD :%s\n", password2);
                printf("---------------\n\n");
                count++;
        }
        if (username3[0] != -1)
        {
                printf("ADMIN NAME: %s\n", username3);
                printf("PASSWORD: %s\n", password3);
                printf("---------------\n\n");
                count++;
        }
        if (username4[0] != -1)
        {
                printf("ADMIN NAME: %s\n", username4);
                printf("PASSWORD: %s\n", password4);
                printf("---------------\n\n");
                count++;
        }
        if (username5[0] != -1)
        {
                printf("ADMIN NAME:%s\n", username5);
                printf("PASSWORD :%s\n", password5);
                printf("---------------\n\n");
                count++;
        }
        if (username6[0] != -1)
        {
                printf(" ADMIN NAME:%s\n", username6);
                printf("PASSWORD :%s\n", password6);
                printf("---------------\n\n");
                count++;
        }
        printf(GREEN);
        printf("\n\t\tNumber of admins is %d\n", count);
        printf(RESET);
        printf("-----------------------------------------------------------\n\n");
}

void addadmin()

{
        int i = 0;

        printf("\n Enter New Admin Name:\t");
        scanf("%s", username4);
        printf("\n Enter New Admin Password:\t");
        while (i <= 9)
        {
                password4[i] = getch();
                if (password4[i] == 13)
                        break;
                else
                        printf("*");
                i++;
        }
}

void del(char *arr)
{
        arr[0] = -1;
        printf("-------------------------------------------\n\n");
        printf(RED);
        printf("successfully deleted\n");
        printf(RESET);
        printf("--------------------------------------------\n\n");
}

void reservation()
{
        //     int n;
        int k;
        printf("Enter the number of passengers : ");
        scanf("%d", &n);

        train_details();
        printf(RED);
        printf("\n\n\nenter the train number :\n");
        printf(RESET);
        scanf("%d", &trainnumb);

        pd passdetails[10];
        pd passdetails1;

        for (k = 0; k < n; ++k)
        {
                passdetails[k].n = k + 1;
                printf("\n Passenger No. %d \n", passdetails[k].n);
                fflush(stdin);
                printf("Enter the name of the Passenger : ");
                gets(passdetails[k].Name);
                printf("Enter the age of the Passenger : ");
                scanf("%d", &passdetails[k].age);
                fflush(stdin);
                printf("Enter the gender ('F' for Female and 'M' for Male) : ");
                scanf("%c", &passdetails[k].g);
                fflush(stdin);
                printf("\n\n\n");
        }

        printf("Enter the valid Email ID : ");
        scanf("%s", &passdetails1.emailid);

        system("cls");

        for (i = 0; i < n; i++)
        {
                printticket(passdetails[i].n, passdetails[i].Name, passdetails[i].age, passdetails[i].g, passdetails1.emailid);
        }

        f = fare(trainnumb, n);

        printf("\n\nTotal amount that need to be paid is : %2.f Rs ", f);
}

void classify_age(int age)
{
        if (age <= 12)
        {
                printf("Child\n");
        }
        else
        {
                printf("Adult\n");
        }
}

void printticket(int n, char Name[50], int age, char g, char em[50])
{

        printf("\n\n Passenger No. %d \n", n);
        printf("-------------------\n");
        printf("\tTICKET\n");
        printf("-------------------\n\n");
        printf("\nName of the Passenger:\t%s", Name);
        printf("\nAge of the Passenger:\t%d\nChild/Adult:\t\t", age);
        classify_age(age);
        printf("Gender:\t\t\t%c", g);
        printf("\nEmail id : %s\n", em);
}

void cancel()
{

        system("cls");
        char Name[50];
        printf("-------------------------------------\n");
        printf("Enter the name of the passenger: \n");
        printf("---------------------------------------\n");
        // fflush(stdin);
        scanf("%s", &Name);
        printf("\n\nThe Booked Ticket is Cancelled");
        // getch();
}

void train_details()
{
        system("cls");
        printf("-------------------------------------------------------------------------------------------------------------------------------------");
        printf("\nTr.No\tName\t\t\tDestinations\t\t\tCharges\t\tTime\t\tNumber of seats\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------");
        printf("\n1.\tEmerald Express\t\tBangalore to Mumbai\t\tRs.700\t\t09:00\t\t%d", random_number(0, 100, 1));
        printf("\n2.\tEmerald Express\t\tMumbai to Bangalore\t\tRs.700\t\t12:00\t\t%d", random_number(0, 100, 2));
        printf("\n3.\tRuby Express\t\tBangalore to Lucknow\t\tRs.3500\t\t08:00\t\t%d", random_number(0, 100, 3));
        printf("\n4.\tRuby Express\t\tLucknow to Bangalore\t\tRs.3500\t\t11:00\t\t%d", random_number(0, 100, 4));
        printf("\n5.\tSapphire Express\tBangalore to Chennai\t\tRs.400\t\t07:00\t\t%d", random_number(0, 50, 2));
        printf("\n6.\tSapphire Express\tChennai to Bangalore\t\tRs.400\t\t09:30\t\t%d", random_number(25, 100, 7));
        printf("\n7.\tDiamond Express\t\tBangalore to Hyderabad\t\tRs.650\t\t13:00\t\t%d", random_number(9, 68, 1));
        printf("\n8.\tDiamond Express\t\tHyderabad to Bangalore\t\tRs.650\t\t16:00\t\t%d", random_number(2, 58, 3));
        printf("\n9.\tTopaz Express\t\tBangalore to New Delhi\t\tRs.5000\t\t15:35\t\t%d", random_number(19, 67, 5));
        printf("\n10.\tTopaz Express\t\tNew Delhi to Bangalore\t\tRs.5000\t\t16:15\t\t%d", random_number(0, 100, 1));
        getchar();
}

void train_details2()
{

        printf("-------------------------------------------------------------------------------------------------------------------------------------");
        printf("\nTr.No\tName\t\t\tDestinations\t\t\tCharges\t\tTime\t\tNumber of seats\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------");
        printf("\n1.\tEmerald Express\t\tBangalore to Mumbai\t\tRs.700\t\t09:00\t\t%d", random_number(0, 100, 1));
        printf("\n2.\tEmerald Express\t\tMumbai to Bangalore\t\tRs.700\t\t12:00\t\t%d", random_number(0, 100, 2));
        printf("\n3.\tRuby Express\t\tBangalore to Lucknow\t\tRs.3500\t\t08:00\t\t%d", random_number(0, 100, 3));
        printf("\n4.\tRuby Express\t\tLucknow to Bangalore\t\tRs.3500\t\t11:00\t\t%d", random_number(0, 100, 4));
        printf("\n5.\tSapphire Express\tBangalore to Chennai\t\tRs.400\t\t07:00\t\t%d", random_number(0, 50, 2));
        printf("\n6.\tSapphire Express\tChennai to Bangalore\t\tRs.400\t\t09:30\t\t%d", random_number(25, 100, 7));
        printf("\n7.\tDiamond Express\t\tBangalore to Hyderabad\t\tRs.650\t\t13:00\t\t%d", random_number(9, 68, 1));
        printf("\n8.\tDiamond Express\t\tHyderabad to Bangalore\t\tRs.650\t\t16:00\t\t%d", random_number(2, 58, 3));
        printf("\n9.\tTopaz Express\t\tBangalore to New Delhi\t\tRs.5000\t\t15:35\t\t%d", random_number(19, 67, 5));
        printf("\n10.\tTopaz Express\t\tNew Delhi to Bangalore\t\tRs.5000\t\t16:15\t\t%d", random_number(0, 100, 1));
}

int random_number(int lower, int upper, int count)
{
        int i, num;
        srand(time(0));
        for (i = 0; i < count; i++)
        {
                num = (rand() % (upper - lower + 1)) + lower;
        }
        return num;
}

float fare(int train_number, int passengers)
{
        //     int train_number, passengers;
        //         printf("\n\nEnter the number of passengers : ");
        //         scanf("%d", &passengers);
        // train:
        //          printf("Enter the chosen train number: ");
        //         scanf("%d", &train_number);
        switch (train_number)
        {
        case 1:
                return (700.0 * passengers);
        case 2:
                return (700.0 * passengers);
        case 3:
                return (3500.0 * passengers);
        case 4:
                return (3500.0 * passengers);
        case 5:
                return (400.0 * passengers);
        case 6:
                return (400.0 * passengers);
        case 7:
                return (650.0 * passengers);
        case 8:
                return (650.0 * passengers);
        case 9:
                return (5000.0 * passengers);
        case 10:
                return (5000.0 * passengers);
        default:
                printf(RED);
                printf("\n\n\t\tInvalid train number!\n\n");
                printf(RESET);
                return 0;
                //         goto train;
        }
}

void dtrain_details()
{
        system("cls");
        printf("-------------------------------------------------------------------------------------------------------------------------------------");
        printf("\nTr.No\tName\t\t\tDestinations\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------");
        printf("\n1.\tEmerald Express\t\tBangalore to Mumbai ");
        printf("\n2.\tEmerald Express\t\tMumbai to Bangalore");
        printf("\n3.\tRuby Express\t\tBangalore to Lucknow");
        printf("\n4.\tRuby Express\t\tLucknow to Bangalore");
        printf("\n5.\tSapphire Express\tBangalore to Chennai");
        printf("\n6.\tSapphire Express\tChennai to Bangalore");
        printf("\n7.\tDiamond Express\t\tBangalore to Hyderabad");
        printf("\n8.\tDiamond Express\t\tHyderabad to Bangalore");
        printf("\n9.\tTopaz Express\t\tBangalore to New Delhi");
        printf("\n10.\tTopaz Express\t\tNew Delhi to Bangalore");
        getchar();
}

int ran()
{
        int number;
        srand(time(0));
        number = rand() % 100 + 1;
        return number;
}

void railwaydatabase()
{
        do
        {
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                        MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. Display the trains \n");
                printf("\t2. Add trains\n");
                printf("\t3. Delete the added trains\n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d", &choice6);
                switch (choice6)
                {

                case 0:
                        exit(0);
                case 1:
                        system("CLS");
                        train_details();

                        printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n");
                        getch();
                        break;
                case 2:
                        system("CLS");
                        addtrain();
                        printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n");
                        getchar();
                        break;

                        printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n");
                        getch();

                        break;
                case 3:
                        system("CLS");
                        deltrain();
                        break;
                }
                printf("\n----------------------------------------------------------------------------\n");
                printf("\n\tWant to Continue[Main Menu] (y/n):\t");
                scanf("%s", &choice7);

        } while ((strcmp(choice3, choice7)) == 0);
}

void addtrain()
{
        int n;
        char buffer[30];

        printf("How many train you want to add : ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
                printf("\n\n\nenter new train %d \n", i + 1);
                printf("--------------------------------\n");
                printf("enter new train number : ");
                scanf("%d", &nt[i].tnum);

                printf("\nenter new train name : ");
                scanf("%s", buffer);
                strcpy(nt[i].tname, buffer);

                printf("\nenter new train source : ");
                scanf("%s", buffer);
                strcpy(nt[i].tsrc, buffer);

                printf("\nenter new train destination   : ");
                scanf("%s", buffer);
                strcpy(nt[i].tdes, buffer);
        }
        printf(GREEN);
        printf("\n\ntrain succesfully added\n\n");
        printf(RESET);
        train_details2();
        for (int i = 0; i < n; i++)
        {
                printf("\n%d ", nt[i].tnum);
                printf("\t%s\t\t\t", nt[i].tname);
                printf("%s to ", nt[i].tsrc);
                printf("%s", nt[i].tdes);
        }
}

void deltrain()
{       nt[0].tnum=-1;
        printf(GREEN);
        printf("\n\n\t\t\t NEWLY ADDED TRAIN DELETD SUCCESSFULLY \n");
        printf(RESET);
        train_details2();
}