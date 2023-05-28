//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


long main(){

   CliInterface  interface = newCliInterface();
    interface.ask_color=CLI_YELLOW;


    // long k=interface.ask_long(&interface,"type integer");
   // double z=interface.ask_double(&interface,"type double");
  interface.wrong_option_menssage="thats wrong";
    int chosed = interface.ask_option(&interface,"type the option" ,"aaa | aaa | bbb | lll");
  
    printf("%i\n",chosed);
    return 0;
}