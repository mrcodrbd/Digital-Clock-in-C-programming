#include <stdio.h>
#include <windows.h>
#include <time.h>
void main()
{
    int hh,mm,ss;
    time_t t;
    t = time(NULL);
    struct tm tm;
    tm = *localtime(&t);

    printf("Setting Your Time\n");
    int chooes;
    do
    {

        printf("Press 1 to auto setting time.\n");
        printf("Press 2 to manually setting time\n");
        printf("Enter: ");
        scanf("%d",&chooes);
    }
    while(chooes==1?0:chooes==2?0:1);
    if(chooes==1)
    {
        hh=tm.tm_hour;
        mm=tm.tm_min;
        ss=tm.tm_sec;
    }
    else if(chooes==2)
    {
        int count=0;
        do
        {
            if(count){
                    system("cls");
               printf("\nInvalid Time! Try aging.\n") ;
            }
            count++;
            printf("Enter HH MM SS \n");
            scanf("%d %d %d",&hh,&mm,&ss);
        }
        while(hh<0 || mm<0 || ss<0);
    }
    for(; hh>0; hh++)
    {
        if(hh>12)
        {
            hh%=12;
        }
        for(; mm<60; mm++)
        {
            for(; ss<60; ss++)
            {
                Sleep(1000);
                system("cls");
                if(ss==59)
                {
                    ss=0;
                    printf("HH: %d MM: %d SS: %d",hh,mm,ss);
                    break;
                }
                printf("HH: %d MM: %d SS: %d",hh,mm,ss);
            }
            if(mm==59)
            {
                mm=0;
                break;
            }
        }

    }
}
