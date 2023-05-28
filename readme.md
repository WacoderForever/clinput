# Description
The CLi input its an lib that allows you to get user informations in an beautfull way


### Instalation
Cli Input its made to be easy to install , just copy and paste **clinput.h** to your project 
~~~c
#include "clinput.h"

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
~~~

### Usage Functions 


### Configuring colors 


### Configuring errors mensags

