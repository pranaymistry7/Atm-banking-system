#include<stdio.h>
#include<windows.h>
#include<time.h>

int main()
{ 
    system("color 8F");
    int pin=2001,option,enteredPin,count = 0,amount = 1;
    float balance = 5000;
    int contTransc = 1;

    system("cls");
    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t                      %s",ctime(&now));
    printf("\n\t\t\t-------------------------->'Welcome to Pranay's Sarcastic ATM'<--------------------------");
    
    while(pin != enteredPin){
        printf("\n Please enter your PIN :\n");
        scanf("%d",&enteredPin);
        if(enteredPin != pin){
            Beep(610,500);
            printf("Invalid Pin!!!.. Please try again..");
        }
        count++;
        if(count == 3 && pin!= enteredPin){
            printf("\n\nYour PIN entering attempts reached !!!.. Please Try again later.. ");
            exit(0);
        }
    }
    while(contTransc != 0){
            printf("\n\t\t\t-------------------->*Available Transactions*<--------------------");
    printf("\n\n\t\t1.Withdrawl");
    printf("\n\t\t2.Deposit");
    printf("\n\t\t3.Check Balance");
    printf("\n\n\t\tPlease Select one option from these: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        while(amount % 100 || amount < 100){
            printf("\n\t\tEnter the amount : ");
            scanf("%d",&amount);
            if( amount < 100)
            printf("\n\t The amount should be more than 100 bucks");
            else if(amount % 100)
            printf("\n\t The amount should be multiple of 100 ");
            
        }
        if(balance < amount) {
            printf("\n\t  Insufficient Fund !!!!...gareeb manus");
            amount = 1;
            break ;
        }
        else {
            balance -= amount;
            printf("\n\t\tYou have withdrawn Rs. %d...\n\t\t Your Current balance is %.2f",amount,balance);
        printf("\n\n\t\t\t\t---------------------->Thank you for using Pranays sarcastic ATM<----------------------");
            amount = 1;
            break;
        }
        
        case 2:
        printf("\n\t\t Please Enter the amount to deposit :");
        scanf("%d",&amount);
        balance += amount;
        printf("\n\t\t You have deposited Rs.%d in your account...\n\t\t Current balance = %.2f",amount,balance);
        printf("\n\n\t\t\t\t---------------------->Thank you for using Pranays sarcastic ATM<----------------------");

        amount = 1;
        break;

        case 3:
        printf("Current Balance = %.2f",balance);
        break;
    
    default:
        
        Beep(610,500);
        printf("Invalid option!!!!!!!!!!!!");
        break;
        }
    printf("\n\n\t\t\t\t Do you wish to perform another transaction \n Press 1[yes] or 2[no]:");
    scanf("%d",&contTransc);
        if(contTransc == 1){
            contTransc != 0;
        }
        else if(contTransc == 2){
        printf("\n\n\t\t\t\t---------------------->Thank you for using Pranays sarcastic ATM<----------------------");
            exit(0);
        }
    }

    return 0;
}