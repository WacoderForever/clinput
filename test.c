//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


int main(){

    CliInterface  interface = newCliInterface();
    char *name = interface.ask_string(&interface,"type your name",CLI_TRIM);



    return 0;
}