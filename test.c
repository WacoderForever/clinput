//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"

long main(){
    CliInterface  interface = newCliInterface();
    int result = interface.ask_option(&interface,"aaaa","red | green | blue");


    return 0;
   
}