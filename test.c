//
// Created by jurandi on 27-05-2023.
//

#include "clinput/clinput.h"

long main(){
  CliInterface  interface = newCliInterface();

   char *name = interface.ask_string(&interface,"type your name",CLI_TRIM);
   long age=interface.ask_long(&interface,"what is your age");
   double weight=interface.ask_double(&interface,"what your weight");

    printf("name: %s\n",name);
    printf("age %li\n",age);
    printf("weight %lf\n",weight);

    return 0;
   
}