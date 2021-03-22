#include<stdio.h>
#include<stdbool.h>
#include "init_head.h"

int main()
{
   bool run=true;

   int event;
   printf("Enter the total number of events\n");
   scanf("%d",&tot_event);

   module_execute(tot_event);
   printf("\nEnter the event to be executed \nIf you terminate the process enter -1\n");
   while (run)
       {
        scanf("%d",&event);
	if (event != -1)
         {
              if ((event>0)&&(event<=tot_event))
                   {
                     event_execute(event);
                    }
              else {
                    printf("Not found this event\n");
                    }
          }
         else
         {
             freeup();
             run=false;
          }
        }
           

return 0;


}
