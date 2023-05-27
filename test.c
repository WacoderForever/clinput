//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"


int main(){

    CliInterface  interface = newCliInterface();
    char *result = interface.ask_string(&interface,"type something",CLI_TRIM);
    printf("r = (%s)",result);

    free(result);

    return 0;
}