//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


long main(){

   CliInterface  interface = newCliInterface();

   // char *name = interface.ask_string(&interface,"type your name",CLI_TRIM);
   // long k=interface.ask_long(&interface,"type integer");
   // double z=interface.ask_double(&interface,"type double");

   int chosed = interface.ask_option(&interface,"type the option",{"aaa","aaa","bbb"});

    return 0;
}