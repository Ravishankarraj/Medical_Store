void medical_store()
{
          int choice;
          while(1)
          {
                system("clear");
           printf("\n\n\n\n\t\t\t\t\t\t\t*****************************************************************");
            printf("\n\t\t\t\t\t\t\t\t\t\tMEDICAL STORE MENU");
            printf("\n\t\t\t\t\t\t\t*****************************************************************");
            printf("\n\t\t\t\t\t\t\t|\t\t\t1. MEDICINES\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t2. DISPLAY STOCK\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t3. Generate BILL\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t4. CUSTOMER TRANSACTION\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t5. SALES\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t6. GOTO MAIN MENU\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t|\t\t\t7. EXIT\t\t\t\t\t|");
            printf("\n\t\t\t\t\t\t\t*****************************************************************");
            printf("\n\n\n\n\t\t\t\t\t\t\tEnter Your choice: ");
            scanf("%d",&choice);
            if(choice==6)
                break;
           switch(choice)
            {

              case 1:
                   system("clear");
                    medicines();
                    break;
              case 2:
                   stock();
                   break;
             case 3:
                   generate_bill();
                   break;
              case 4:
                   customer_trans();
                   break;
             case 5:
                    sales();
                    break;
            case 7: exit(1);
              default:
                    printf("\nWrong choice");
            }
       }
 }
 