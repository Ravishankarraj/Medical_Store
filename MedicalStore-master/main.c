#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "bill.h"
#include "medicine.h"
#include "medical_store.h"
#include "menu.h"

#define KNRM  "\x1B[0m"
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
void main()
{
    char usr[20],pas[20],ch,c;
    char usrnm[]={"IamUser"};
    char pass[]={"project"};
    int f=0,i;
    printf(KNRM);
   
    do
    {
        system("clear");
        i=0;
        printf("\n\t\t\t\t\t\t\t\t\tMEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("\t\t\t\t\t\t\t......................................................\n");
        printf("\n\n\t\t\t\t\t\t\t\tUSER NAME : ");
        scanf("%s",usr);
        printf("\n\t\t\t\t\t\t\t\tPASSWORD : ");
        scanf("%c",&c);
        while(1)
        {
            ch=getch();
            if(ch==10)
              break;
            printf("*");
            pas[i]=ch;
            i++;
        }
        pas[i]='\0';
        printf("\n\t\t\t\t\t\t\t......................................................\n");
        if(!(strcmp(usr,usrnm)==0 && strcmp(pass,pas)==0))
             {  
                printf("Invalid Username and password.");
                   system("clear");
             }
        else
        {
            menu();
            f=1;
        }
    }while(f!=1);

}