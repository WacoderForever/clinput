//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


long main(){

    CliInterface  interface = newCliInterface();
    bool  option = interface.ask_option( &interface,"are you religious? ","yes | no");
    printf("%i",option);

    return 0;
}