//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


long main(){


    CliInterface  interface = newCliInterface();
    //bool  option = interface.ask_option( &interface,"are you gay? ","yes | no");
    interface.print(&interface,"aaaaa %c  %s aaa",'a',"cxxx");
    printf("\nnormal denovo\n");

    return 0;
}