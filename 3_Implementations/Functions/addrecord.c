#include "Diary.h"

void addrecord( )

{

    system("cls");

    FILE *fp ;

    char another = 'Y' ,time[10];

    struct record e ;

    char filename[15];

    int choice;

    printf("\n\n\t\t*****************************\n");

    printf("\t\t* WELCOME TO THE ADD WINDOW *");

    printf("\n\t\t*****************************\n\n");

    printf("\n\n\tENTER DATE OF YOUR RECORD:[dd-mm-yyyy]:");

    fflush(stdin);

    gets(filename);

    fp = fopen (filename, "ab+" ) ;

    if ( fp == NULL )

    {

        fp=fopen(filename,"wb+");

        if(fp==NULL)

        {

            printf("\nSYSTEM ERROR...");

            printf("\nPRESS ANY KEY TO EXIT");

            getch();

            return ;

        }

    }

    // To add a record on respective date with an different time.//

    while ( another == 'Y'|| another=='y' )

    {

        choice=0;

        fflush(stdin);

        printf ( "\n\tENTER TIME:[hh:mm]:");

        scanf("%s",time);

        rewind(fp);

        while(fread(&e,sizeof(e),1,fp)==1)

        {

            if(strcmp(e.time,time)==0)

            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                choice=1;

            }

        }

        if(choice==0)

        {

            strcpy(e.time,time);

            printf("\tENTER NAME:");

            fflush(stdin);

            gets(e.name);

            fflush(stdin);

            printf("\tENTER PLACE:");

            gets(e.place);

            fflush(stdin);

            printf("\tENTER DURATION:");

            gets(e.duration);

            fflush(stdin);

            printf("\tNOTE:");

            gets(e.note);

            fwrite ( &e, sizeof ( e ), 1, fp ) ;

            printf("\nYOUR RECORD IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) " ) ;

        fflush ( stdin ) ;

        another = getchar( ) ;

    }

    fclose ( fp ) ;

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();

}

