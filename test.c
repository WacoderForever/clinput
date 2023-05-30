//
// Created by jurandi on 27-05-2023.
//

#include "clinput.h"

int main(){

    CliInterface  interface = newCliInterface();
    int result = interface.ask_option(&interface,"aaa","aaa | wwww|  dddd");

    return 0;
   
}