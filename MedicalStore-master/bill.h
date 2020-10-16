#include<string.h>
#include<time.h>
#define KBLU  "\x1B[34m"
struct customer
{
    char name[20];
    int cqnt[10];
    char mob[12];
    char time[30];
    float rate[10];
    float total;
}cus;
struct medici
{
    int qnt;
    float price;
    char name[20];
    char dis[20];
}med1;

char cmed[10][20];
int checkmed(char nm[],int i)
{
      FILE *fpm;int t=200;
      fpm=fopen("medic.txt","r+");
      if(fpm==NULL)
         printf("\nError in opening medical File.");
      else
      {
          cus.total=0;
           while( (fread(&med1,sizeof(med1),1,fpm)==1) ) 
           {
	  	  	  	if(strcmp(nm,med1.name)==0 && med1.qnt==0 )
	  	  	  	     return 0;
            else	if(strcmp(nm,med1.name)==0 && med1.qnt>0 )
                   {
                       char c;
                       cus.rate[i]=med1.price;
                       printf("\nEnter Quantity: ") ;
                       scanf("%d",&cus.cqnt[i]);
                       if(med1.qnt>=cus.cqnt[i] )
                       {
                         med1.qnt-=cus.cqnt[i];
                         if(med1.qnt<3)
                         {
                             while(t--)
                               {
                                 system("clear");
                                 fprintf(stdout, "\aALERT! Only %d is left\n",med1.qnt );
                              }
                         }
                         cus.total+=cus.cqnt[i]*cus.rate[i];
                         fseek(fpm,-sizeof(med1),1);
                         fwrite(&med1,sizeof(med1),1,fpm);
                         break;
                       }
                      else
                       {
                          printf("\nOnly %d medicines left",med1.qnt);
	  	  	  	             
                       }
                   }
           }
                  fclose(fpm);
                   return 1;
      }
}

void display( time_t t,int m)
{
    int i,j;
    char c;
    float gstotal=0,gst,total,dis;
    system("clear");
printf("\t\t*********************************************************************************************************\n");
 printf("\t\t*\t\t\t\t\t Medical Invoice\t\t\t\t\t\t*  \n");
 printf("\t\t*\t\t\t\t\t\t\t\t\t %s \t\t*\n",ctime(&t));
 printf("\t\t*\t-------------------------------------------------------------------------------------------\t*\n");
 printf("\t\t*\t  Customer Name: %15s\t\t\t\t\t\t\t\t*\n",cus.name);
 printf("\t\t*\t  Mobile       : %15s\t\t\t\t\t\t\t\t*\n\t\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*\n\t\t*\n",cus.mob);
 printf("\t\t*\t\t  Serial No\tParticulars\t\tQuantity\tRate\t\tPrice\t\t*");
 for(i=0;i<m;i++)
    {
     printf("\n\t\t*\t\t  %d\t\t%11s\t\t%d\t\t%.2f\t\t%.2f\t\t*\n\t\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*",i+1,cmed[i],cus.cqnt[i],cus.rate[i],cus.cqnt[i]*cus.rate[i]);
      gstotal+=cus.cqnt[i]*cus.rate[i];
    }
    gst=18*gstotal/100;
    dis=2*gstotal/100;
    total=gstotal+gst-dis;
     printf("\n\t\t*\t-------------------------------------------------------------------------------------------\t*\n\t\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*");
    printf("\n\t\t*\t\t\t\t\t\t\t\t\tGross Total     = %.2f\t\t*",gstotal);
    printf("\n\t\t*\t\t\t\t\t\t\t\t\tGST \t\t= %.2f\t\t*",gst);
    printf("\n\t\t*\t\t\t\t\t\t\t\t\tDiscount \t= %.2f\t\t*",dis);
    printf("\n\t\t*\t\t\t\t\t\t\t\t\tTotal \t\t= %.2f\t\t*\n\t\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*",total);
     printf("\n\t\t*\t-------------------------------------------------------------------------------------------\t*\n\t\t*\t\t\t\t\t\t\t\t\t\t\t\t\t*");
     printf("\n\t\t*********************************************************************************************************\n");
     printf("\nPress any key to continue\n");
     scanf("%c",&c);
        scanf("%c",&c);
}

void generate_bill()
{
      FILE *fpc;
       time_t t;
       time(&t);
      int i=0,j=0;
      system("clear");
      fpc=fopen("cust.txt","a");
      printf(KBLU);
      if(fpc==NULL)
        printf("\nError in opening customer File.");
      else
      {
         char c;
         printf("\nEnter customer name: ");
         scanf("%c",&c);
         scanf("%[^\n]s",cus.name) ; 
         while(1)
         {
            printf("\nEnter medicine name(Press 1 for Stop): ");
            scanf("%c",&c);
            scanf("%[^\n]s",cmed[i]) ; 
            if( strcmp  ((cmed[i]), "1")== 0 )  
              break;
            if(checkmed(cmed[i],i)==0)
              printf("\nEntered medicine is currently unavailable");
              i++;
         }  
        // scanf("%c",&c);
         printf("\nEnter Customer Mobile no: ") ;
         scanf("%c",&c);
         scanf("%s",cus.mob);
         strcpy(cus.time,ctime(&t));
         fwrite(&cus,sizeof(cus),1,fpc);
         display(t,i);
      }
      fclose(fpc);
}
void customer_trans()
{
      FILE *fpc;
      int i=0,j;
      char nm[20],c;
      float price;
      system("clear");
      fpc=fopen("cust.txt","r");
      if(fpc==NULL)
         printf("\nError in opening customer File.");
      else
      {
         /*  printf("\nEnter customer name: ");
           scanf("%c",&c);
           scanf("%[^\n]s",nm);*/

           while( (fread(&cus,sizeof(cus),1,fpc)==1) ) 
           {
                //if(strcmp(nm,cus.name)==0)
                 // {
                      printf("\nName : %s",cus.name);
                      printf("\nDate of purchase: %s ",cus.time);
                      printf("\n Mobile no: %s",cus.mob);
                      printf("\nTotal amount: %f",cus.total);
                     // break;
                  //}
           }
           printf("\nEnter any key to continue..");
                  scanf("%c",&c);
                  scanf("%c",&c);
                  fclose(fpc);
      }
}
void sales()
{
   FILE *fp;
   int qnt=0;
   float totalamt=0;
   char c;
   system("clear");
   fp=fopen("cust.txt","r");
   if(fp==NULL)
   {
      printf("\nError in opening file.\n");
   }
   else{
      printf("\nSALES DESCRIPTION\n");
      while(fread(&cus,sizeof(cus),1,fp)==1)
      {
           totalamt+=cus.total; 
      }
      printf("\nTotal Sales= %f",totalamt);
      printf("\nEnter any key to continnue...");
      scanf("%c",&c);
      scanf("%c",&c);
   }

}