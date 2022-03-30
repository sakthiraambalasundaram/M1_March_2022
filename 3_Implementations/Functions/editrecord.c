#include "Diary.h"
void editrecord()

{

    system("cls");

    FILE *fpte ;

    struct record user ;

    char time[10],choice,filename[20];

    int num,count=0;

    printf("\n\n\t\t*********************************\n");

    printf("\t\t* WELCOME TO THE EDITING WINDOW *");

    printf("\n\t\t*********************************\n\n");

    choice=password();

    if(choice!=0)

    {

        return ;

    }

    do

    {

        printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[dd-mm-yyyy]:");

        fflush(stdin);

        gets(filename);

        printf("\n\tENTER TIME:[hh:mm]:");

        gets(time);

        fpte = fopen ( filename, "rb+" ) ;

        if ( fpte == NULL )

        {

            printf( "\nRECORD DOES NOT EXISTS:" ) ;

            printf("\nPRESS ANY KEY TO GO BACK");

            getch();

            return;

        }

        while ( fread ( &user, sizeof ( user ), 1, fpte ) == 1 )

        {

            if(strcmp(user.time,time)==0)

            {

                printf("\nYOUR OLD RECORD WAS AS:");

                printf("\nTIME: %s",user.time);

                printf("\nMEETING WITH: %s",user.name);

                printf("\nMEETING AT: %s",user.place);

                printf("\nDURATION: %s",user.duration);

                printf("\nNOTE: %s",user.note);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                printf("\n1.TIME.");

                printf("\n2.MEETING PERSON.");

                printf("\n3.MEETING PLACE.");

                printf("\n4.DURATION.");

                printf("\n5.NOTE.");

                printf("\n6.WHOLE RECORD.");

                printf("\n7.GO BACK TO MAIN MENU.");

                do

                {

                    printf("\n\tENTER YOUR CHOICE:");

                    fflush(stdin);

                    scanf("%d",&num);

                    fflush(stdin);

                    switch(num)

                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(user.time);

                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PERSON:");

                        gets(user.name);

                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PLACE:");

                        gets(user.place);

                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nDURATION:");

                        gets(user.duration);

                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");

                        printf("\nNOTE:");

                        gets(user.note);

                        break;

                    case 6:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(user.time);

                        printf("\nNEW MEETING PERSON:");

                        gets(user.name);

                        printf("\nNEW MEETING PLACE:");

                        gets(user.place);

                        printf("\nDURATION:");

                        gets(user.duration);

                        printf("\nNOTE:");

                        gets(user.note);

                        break;

                    case 7:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");

                        getch();

                        return ;

                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");

                        break;

                    }

                }
                while(num<1||num>8);

                fseek(fpte,-sizeof(user),SEEK_CUR);

                fwrite(&user,sizeof(user),1,fpte);

                fseek(fpte,-sizeof(user),SEEK_CUR);

                fread(&user,sizeof(user),1,fpte);

                choice=5;

                break;

            }

        }

        if(choice==5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("--------------------\n");

            printf("THE NEW RECORD IS:\n");

            printf("--------------------\n");

            printf("\nTIME: %s",user.time);

            printf("\nMEETING WITH: %s",user.name);

            printf("\nMEETING AT: %s",user.place);

            printf("\nDURATION: %s",user.duration);

            printf("\nNOTE: %s",user.note);

            fclose(fpte);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");

            scanf("%c",&choice);

            count++;

        }

        else

        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");

            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

            scanf("%c",&choice);

        }

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    if(count==1)

        printf("\n%d FILE IS EDITED...\n",count);

    else if(count>1)

        printf("\n%d FILES ARE EDITED..\n",count);

    else

        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");

    getch();

}

