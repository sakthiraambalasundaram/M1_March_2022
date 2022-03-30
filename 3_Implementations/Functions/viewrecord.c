#include "Diary.h"

void viewrecord( )

{

    FILE *fpte ;

    system("cls");

    struct record user ;

    char time[6],choice,filename[14];

    int ch;

    printf("\n\n\t\t*********************************\n");

    printf("\t\t* HERE IS THE VIEWING Window *");

    printf("\n\t\t*********************************\n\n");

    choice=password();

    if(choice!=0)

    {

        return ;

    }

    do

    //To view an Record of an particular day.//

    {

        printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED:[dd-mm-yyy]:");

        fflush(stdin);

        gets(filename);

        fpte = fopen ( filename, "rb" ) ;

        if ( fpte == NULL )

        {

            puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;

            printf("PRESS ANY KEY TO EXIT...");

            getch();

            return ;

        }

        //Menu of viewing a Record of an day.//

        system("cls");

        printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");

        printf("\n\t1.Entire Record of an Day.");

        printf("\n\t2.RECORD OF a Particular TIME.");

        printf("\n\t\tENTER YOUR CHOICE:");

        scanf("%d",&ch);

        switch(ch)

        {

        case 1:

            printf("\nTHE WHOLE RECORD FOR %s IS:",filename);

            while ( fread ( &user, sizeof ( user ), 1, fpte ) == 1 )

            {

                printf("\n");

                printf("\nTIME: %s",user.time);

                printf("\nMEETING WITH: %s",user.name);

                printf("\nMEETING AT: %s",user.place);

                printf("\nDURATION: %s",user.duration);

                printf("\nNOTE: %s",user.note);

                printf("\n");

            }

            break;

        case 2:

            fflush(stdin);

            printf("\nENTER TIME:[hh:mm]:");

            gets(time);

            while ( fread ( &user, sizeof ( user ), 1, fpte ) == 1 )

            {

                if(strcmp(user.time,time)==0)

                {

                    printf("\nYOUR RECORD IS:");

                    printf("\nTIME: %s",user.time);

                    printf("\nMEETING WITH: %s",user.name);

                    printf("\nMEETING AT: %s",user.place);

                    printf("\nDUARATION: %s",user.duration);

                    printf("\nNOTE: %s",user.note);

                }

            }

            break;

        default:
            printf("\nYOU TYPED SOMETHING ELSE...\n");

            break;

        }

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");

        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    return ;

}
