# Description
The CLi input its an lib that allows you to get user informations in an beautfull way


### Installation
Cli Input its made to be easy to install , just copy and paste **clinput.h** to your project CLI_TRIM 
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
CLi input gives extensive coverage of functions that improve visuals when using the command line
#### Dealing with string
The method "ask_string" is used to pass the string
~~~c
    #include "clinput.h"

long main(){

   CliInterface  interface = newCliInterface();

   char *name = interface.ask_string(&interface,"type your name",CLI_TRIM);
    printf("name: %s\n",name);
    free(name);
    return 0;
}
~~~
#### Dealing with double
The method "ask_double" is used to pass the double value
~~~c
    #include "clinput.h"


long main(){

   CliInterface  interface = newCliInterface();

  
   double weight=interface.ask_double(&interface,"what your weight");
    printf("weight %lf\n",weight);

    return 0;
}
~~~
#### Dealing with integers
ask_long method passes the long integer 
~~~c
    #include "clinput.h"


int main(){

   CliInterface  interface = newCliInterface();
   long age=interface.ask_long(&interface,"what is your age");
   printf("age %li\n",age);
    return 0;
}
~~~
### Configuring colors 
The CLI_[COLOR_NAME] gives definition of color to be used on an aspect
~~~c
    #include "clinput.h"
    self.warning_color = CLI_YELLOW; //sets warning color to yellow
    self.error_color = CLI_RED; //sets error color to red
    self.normal_color = CLI_WHITE; //sets normal color to white
~~~
### Options page
This page allows selection of options provide and returns the index of the selected option
~~~c
#include "clinput/clinput.h"


long main(){

   CliInterface  interface = newCliInterface();
    int chosed = interface.ask_option(&interface,"type the option" ,"aaa | aaa | bbb | lll");

    printf("%i\n",chosed);
    return 0;
}
~~~

### Configuring errors mensags
#### Integer errors
Error messages are generated when invalid characters are produced,when a value other than an integer is entered, in the code segment below a default error message "The value its not an Integer" is generated.
~~~c
    #include "clinput.h"


int main(){

   CliInterface  interface = newCliInterface();
   invalid_long_menssage = "The value its not an Integer";
   long age=interface.ask_long(&interface,"what is your age");
   printf("age %li\n",age);
    return 0;
}
~~~
#### Double errors 
Error messages are generated when invalid characters are produced,when a value that is not is not a double in the code segment below a default error message "The value its not an Integer" is generated.
~~~c
    #include "clinput.h"


int main(){

   CliInterface  interface = newCliInterface();
   invalid_long_menssage = "The value its not a double";
   long age=interface.ask_long(&interface,"what is your weight");
   printf("age %f\n",weight);
    return 0;
}
~~~
#### Option errors 
Error messages are generated when invalid option is selected,when a value that is not is not in the options, the error message "The value its not among the options" is generated.
~~~c
    #include "clinput.h"


int main(){

   CliInterface  interface = newCliInterface();
   invalid_long_menssage = "The value its not among the options";
   int chosed = interface.ask_option(&interface,"type the option" ,"aaa | aaa | bbb | lll");
    printf("%i\n",chosed);
    return 0;
}
~~~

