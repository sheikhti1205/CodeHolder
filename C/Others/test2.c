#include <stdio.h>
#include <math.h>
int main()
{
    int DepTime[] = {480, 583, 679, 767, 840, 1025, 1200, 1385};
    int ArrivTime[] = {616, 712, 811, 900, 968, 1155, 1400, 1438};
    char deptime[] = {"8:00 am", "9:43 am", "11:19 am", "12:47 pm", "2:00 pm", "3:45 pm", "7:00 pm", "9:45 pm"};
    char arrivtime[] = {"10:16 am", "11:52 am", "1:31 pm", "3:00 pm", "4:08 pm", "5:55 pm", "9:20 pm", "11:58 pm"};
    int dephour, depminute, leave;
    int i;

    printf("Enter your deparature time:\n");
    scanf("%d:%d", &dephour, &depminute);
    
    leave = (dephour*60) + depminute;

    printf("%d\n", leave);

    for(i=0; i<=8; i++)
    {
        if(leave<DepTime[i])
        {
            printf("Deparature Time is: %s", deptime[i]);
            printf("Arrival Time is: %s", arrivtime[i]);
            break;
        }
    }

    return 0;
}