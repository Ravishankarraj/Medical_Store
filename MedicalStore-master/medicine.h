 #include<stdlib.h>
 #include<string.h>
 #define KGRN  "\x1B[32m"
  #define KCYN  "\x1B[36m"
 #define SIZE 100
int mInc=0;// medicine Increment.
struct medicine
{
    int qnt;
    float price;
    char name[20];
    char dis[20];
}med;

void update()
{
      FILE *fp;
      char nm[30];
      fp=fopen("medic.txt","r+");
      if(fp==NULL)
         printf("\nError in opening File.");
      
      else
      {
         char c;
         printf("\nEnter medicine name: ");
         scanf("%c",&c);
         scanf("%[^\n]s",nm) ; 
        // scanf("%c",&c);
        while( (fread(&med,sizeof(med),1,fp)==1) ) 
           {
              if(strcmp(med.name,nm)==0)
              {
                printf("\nEnter new price: ") ;
                scanf("%f",&med.price);
                printf("\nEnter new Quantity: ") ;
                 scanf("%d",&med.qnt);
                 fseek(fp,-sizeof(med1),1);
                  fwrite(&med,sizeof(med),1,fp);
                  break;
              }
           }
      }
      fclose(fp);
}
void searchmed()
{
	  char ch,e;
	  char nm[20]={'\0'};
	  int i,j=0;
        system("clear"); 
        FILE *fp;
        fp=fopen("medic.txt","r");
        if(fp==NULL)
          printf("Error in Opening file.");
	  else
        {	  
	        printf("\nEnter name of medicine: %s",nm);
	  	  scanf("%c",&e);
	  	  scanf("%[^\n]s",nm);
            printf("\n--------------------------------------------------------------------------------------------------------\n");
            printf("\n\tName \t\t\t Price \t\t\tQuantity \t\tDisease\n");
            printf("--------------------------------------------------------------------------------------------------------\n\n");
	  	while( (fread(&med,sizeof(med),1,fp)==1) ) 
	  	  	  {
	  	  	  	if( strcmp ( nm,med.name )  ==0  )
	  	  	  	     printf("\n\t%s\t\t\t%.2f\t\t%d\t\t%s\n",med.name,med.price,med.qnt,med.dis);
				  }

                  fclose(fp);
    }
}
void displaymed()
{
      FILE *fp;
      char c;
      fp=fopen("medic.txt","r");
      system("clear");
      printf("\n--------------------------------------------------------------------------------------------------------\n");
      printf("\n\tName \t\t\t Price \t\t\tQuantity \t\tDisease\n");
      printf("--------------------------------------------------------------------------------------------------------\n\n");
     while( (fread(&med,sizeof(med),1,fp)==1) )
     {
           printf("\t%15s\t\t",med.name);
           printf("%.2f\t\t\t",med.price);
           printf("%d\t\t\t",med.qnt);
           printf("%s\n",med.dis);
           printf("\t________________________________________________________________________________________________\n");
     }
     printf("\npress any key for continue...");
     scanf("%c%c",&c,&c);
     fclose(fp);
}
void stock()
{
	  int i,j=0;
        char c;
        system("clear"); 
        FILE *fp;
        fp=fopen("medic.txt","r");
       
        printf(KCYN);
        if(fp==NULL)
          printf("Error in Opening file.");
	  else
        {	  printf("\nDetails of medicines whose quantity is less than 5\n");
              printf("\n--------------------------------------------------------------------------------------------------------\n");
              printf("\n\tName \t\t\t Price \t\t\tQuantity \t\tDisease\n");
              printf("--------------------------------------------------------------------------------------------------------\n");
	  	    while( (fread(&med,sizeof(med),1,fp)==1) ) 
	  	  	  	if( med.qnt<=5 )
	  	  	  	     printf("\n%12s\t\t%.2f\t\t%d\t\t%12s\n",med.name,med.price,med.qnt,med.dis);

                  fclose(fp);
        }
        printf("\nPress any key to continue\n");
        scanf("%c",&c);
        scanf("%c",&c);
}
void addmed()
{
      FILE *fp;
      fp=fopen("medic.txt","a");
      if(fp==NULL)
         printf("\nError in opening File.");
      
      else
      {
         char c;
         printf("\nEnter medicine name: ");
         scanf("%c",&c);
         scanf("%[^\n]s",med.name) ; 
        // scanf("%c",&c);
         printf("\nEnter price: ") ;
         scanf("%f",&med.price);
         printf("\nEnter Quantity: ") ;
         scanf("%d",&med.qnt);
         printf("Enter Disease: ");
         scanf("%c",&c);
         scanf("%[^\n]s",med.dis);

         fwrite(&med,sizeof(med),1,fp);
            
      }
      fclose(fp);
}
void medicines()
{
          int choice;
          while(1)
          {
            printf(KGRN);
            printf("\n\n\n\n\t\t\t\t\t\t\t*****************************************************************");
            printf("\n\t\t\t\t\t\t\t\t\t\tMEDICINES MENU");
            printf("\n\t\t\t\t\t\t\t*****************************************************************");
            printf("\n\t\t\t\t\t\t\t|\t\t\t1. ADD MEDICINES\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t2. DISPLAY \t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t3. SEARCH MEDICINES\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t4. Update MEDICINES\t\t\t|");
             printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t5. GOTO PREVIOUS MENU\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t6. EXIT\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t*****************************************************************");
            printf("\n\n\n\n\t\t\t\t\t\t\tEnter Your choice: ");
            scanf("%d",&choice);
           if(choice==5)
              break;
           switch(choice)
            {

              case 1:
                    system("clear");
                    addmed();
                    break;
              case 2:
                   displaymed();
                   break;
              case 3:
                   searchmed();
                   break;
               case 4:
                    update();
                    break;
              case 6:
                    exit(1);
              default:
                    printf("\nWrong choice");
            }
          }
}
