//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


long main(){

    CliInterface  interface = newCliInterface();
    interface.ask_color=CLI_RED;
    char *name = interface.ask_string(&interface,"type your name",CLI_TRIM);
    int k=interface.ask_integer(&interface,"type integer",0,10);


    return 0;
}