#include<stdio.h>
#include<stdlib.h>
#define KYEL  "\x1B[33m"
#define KMAG  "\x1B[35m"
void help()
{
    char c;
    system("clear");
    printf(KYEL);
    printf("\nFor any Querey please contact us\n" );
    printf("\n We are here to help You!");
    printf("\Email id: rajeevjha275@gmail.com\niampulak.ps@gmail.com");
    printf("\nYou can also contact us through whatsapp and facebook");
    printf("\nIf you want it please mail us.");
    printf("\nPress any key for continue...");
    scanf("%c",&c);
    scanf("%c",&c);
}
void about()
{
    char c;
    system("clear");
    printf(KMAG);
    printf("\nThis project is based on c.\n");
    printf("\nWe have used\n Structure\n Function \n Headerfile\n File handling\n and various other topics.");
    printf("\nThis project is developed in the guidlines of Miss DEEPTHI\n\n");
    printf("\nProject is developed By: -\n");
    printf("\nPulak Sadhukhan\n Mohit Pandey\nRavi Shankar\n Atif saif\n Rajeev Jha\n");
}