//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"

long main(){
   CliInterface interface=newCliInterface();
    interface.success_color=CLI_MAGENTA;
    long age=interface.ask_long(&interface,"what is your age");
    printf("age %li\n",age);
    return 0;
   
}