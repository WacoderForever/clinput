//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


long main(){

   CliInterface  interface = newCliInterface();
   interface.invalid_long_menssage = "these its not an fucking integer";

    int result = interface.ask_long(&interface,"type an integer");

    printf("(%s) \n",result);

    return 0;
}