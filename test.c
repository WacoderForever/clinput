//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


long main(){

    CliInterface  interface = newCliInterface();

    char *name = interface.ask_string(&interface,"type your name",CLI_TRIM);
    long k=interface.ask_long(&interface,"type integer");



    return 0;
}