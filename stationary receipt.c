#include<stdio.h>
#include<time.h>

void header();
void fheader();
void getdata();

char books[100][100];
int price[100];

int ch=10;
int sum = 0;

void main()
{
    header();

    getdata();

    fheader();

}

void header()
{


    srand(time(NULL));
    time_t timer = time(NULL);
    int billno=rand()%200;


    printf("\n********************************\n\n");
    printf("**Library exchange system**\n");
    printf("\nDivesh Stationers & Book Seller\n");
    printf("All types of Educational Book Seller\n");
    printf("\n********************************\n\n");

    printf("NO %d",billno);
    printf("\tDate: %s\n",ctime(&timer));
    printf("\tBooks on Library System\n");
    printf("60 %% amount Adjustable to the fulfillment \n\tof conditionas overleaf.\n\n\n");
    printf("----------------------------------------\n\n");


}

void fheader()
{


    srand(time(NULL));
    time_t timer = time(NULL);
    int billno=rand()%200;


    FILE *ifp;
    ifp = fopen("bill.txt","w+");

    if(ifp == NULL)
    {
        printf("file cant be opened\n");
    }

    else
    {
        fprintf(ifp,"\n********************************\n\n");
        fprintf(ifp,"**Library exchange system**\n");
        fprintf(ifp,"\nDivesh Stationers & Book Seller\n");
        fprintf(ifp,"All types of Educational Book Seller\n");
        fprintf(ifp,"\n********************************\n\n");
        
        fprintf(ifp,"NO %d",billno);
        fprintf(ifp,"\tDate: %s\n",ctime(&timer));
        fprintf(ifp,"\tBooks on Library System\n");
        fprintf(ifp,"60 %% amount Adjustable to the fulfillment \n\tof conditionas overleaf.\n\n\n");
        fprintf(ifp,"----------------------------------------\n\n");

        fprintf(ifp,"sr \tbook name\tprice\n");

        for(size_t i = 0; i < ch; i++)
        {
            fprintf(ifp,"%d\t%s\t\t\t",i+1,books[i]);
            fprintf(ifp,"%d\n",price[i]);
            sum=sum+price[i];
        }

        fprintf(ifp,"\n\nTotal price: %d",sum);
    }

    fflush(ifp);
    fclose(ifp);
}

void getdata()
{


    printf("enter total number of items ");
    scanf("%d",&ch);
    printf("enter book name and book price ");

    for(size_t i=0;i<ch;i++)
    {
        scanf("%s",&books[i]);
        scanf("%d",&price[i]);
        sum=sum+price[i];
    }

    printf("\nsr \tbook name\t\tprice\n");

    for (size_t i = 0; i < ch; i++)
    {
        printf("%d\t%s\t\t\t",i+1,books[i]);
        printf("%d\n",price[i]);

    }
    
    printf("\ntotal price: %d",sum);

    printf("\n\n\nget proper receit from bill.txt file \n\n\n\n");
}
