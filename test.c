//
// Created by jurandi on 27-05-2023.
//

#include "clinput.h"

long main(){


    CliInterface  interface = newCliInterface();
    //bool  option = interface.ask_option( &interface,"are you gay? ","yes | no");
   interface.warning(&interface,"this is not good");
    return 0;
}