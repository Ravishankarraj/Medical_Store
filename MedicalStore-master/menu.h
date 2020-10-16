#define KRED  "\x1B[31m"
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
void menu()
{

 while(1)
        {
            int choice;
            printf(KRED);
            system("clear");
            printf("\n\n\n\t\t\t\t\t\t\t......................................................\n");
            printf("\n\n\t\t\t\t\t\t\t\tWELCOME IN MEDICAL STORE MANAGEMENT SYSTEM\n");
            printf("\t\t\t\t\t\t\t......................................................\n");
            printf("\n\n\n\n\t\t\t\t\t\t\t-----------------------------------------------------------------");
            printf("\n\t\t\t\t\t\t\t\t\t\tMAIN MENU");
            printf("\n\t\t\t\t\t\t\t-----------------------------------------------------------------");
            printf("\n\t\t\t\t\t\t\t|\t\t\t1. MEDICAL STORE\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t2. HELP\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t3. ABOUT\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t4. EXIT\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t-----------------------------------------------------------------");
            printf("\n\n\n\n\t\t\t\t\t\t\tEnter Your choice: ");
            scanf("%d",&choice);
            if(choice==4)
                break;
            switch(choice)
            {

              case 1:
                    system("clear");
                    medical_store();
                    break;
              case 2:
                   help();
                   break;
              case 3:
                   about();
                   break;
              default:
                    printf("\nWrong choice");
            }


        }
}