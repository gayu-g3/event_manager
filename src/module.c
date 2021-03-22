#include<stdio.h>
#include<stdlib.h>
#include"init_head.h"

int (*func[5])() = {module1, module2, module3, module4, module5 };

int module1(int event){
   printf(" event %d is interested in module 1\n",event);
return 0;
}
int module2(int event){
   printf(" event %d is interested in module 2\n",event);
   return 0;
}
int module3(int event){
   printf(" event %d is interested in module 3\n",event);
   return 0;
}
int module4(int event){
   printf(" event %d is interested in module 4\n",event);
   return 0;
}
int module5(int event){
   printf(" event %d is interested in module 5\n",event);
   return 0;
}

int module_execute(int tot_event){
    int bit=0,evnt=0,mod_no;
    //callback cb;
    for(mod_no=1;mod_no<=5;mod_no++){
        printf("Enter the events this is interested with module %d \nenter 0 when done\n",mod_no);
        scanf("%d",&evnt);
        while(evnt>0 && evnt<=tot_event){ 
            bit|=1<<(evnt-1);
             scanf("%d",&evnt);
         }
       
       register_the_event(mod_no,bit,func[mod_no]);
       bit=0;

    }
return 0;

}

