//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


int main(){

    CliInterface  interface = newCliInterface();
    char *result = interface.ask_string(&interface,"type something");
    printf("%s",result);

    free(result);

    return 0;
}