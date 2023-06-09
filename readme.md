# Description
The CLi input its an lib that allows you to get user informations in an beautfull way


### Installation
Cli Input its made to be easy to install , just copy and paste **clinput.h** to your project.
~~~c
#include "clinput.h"

int main(){

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

int main(){

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
#### Generating warnings
~~~c
#include "clinput.h"
int main(){


    CliInterface  interface = newCliInterface();
    //bool  option = interface.ask_option( &interface,"are you religious? ","yes | no");
   interface.warning(&interface,"this is not good");
    return 0;
}
~~~
### Configuring colors 
The CLI_[COLOR_NAME] gives definition of color to be used on an aspect
#### Setting warning colours
The warning text color is set to red.The code segement sets the warning message "You are not old enough to access this site" to red.
~~~c
#include "clinput.h"
 int main(){
    CliInterface interface=newCliInterface();
    interface.warning_color=CLI_RED;
    long age=interface.ask_long(&interface,"what is your age");
    printf("age %li\n",age);
    if(age<18){
        interface.warning(&interface,"You are not old enough to access this site");
        return 1;
    }
    return 0;

 }
~~~
#### Setting error colours
The error color is set to green.
~~~c
#include "clinput.h"
 int main(){
    CliInterface interface=newCliInterface();
    interface.error_color=CLI_YELLOW;
    long age=interface.ask_long(&interface,"what is your age");
    printf("age %li\n",age);
    return 0;

 }
~~~
#### Setting normal colour
The normal color is set to blue.
~~~c
#include "clinput.h"
 int main(){
    CliInterface interface=newCliInterface();
    interface.normal_color=CLI_BLUE;
    long age=interface.ask_long(&interface,"what is your age");
    printf("age %li\n",age);
    return 0;

 }
~~~
#### Setting ask colour
The ask color is set to blue.
~~~c
#include "clinput.h"
 int main(){
    CliInterface interface=newCliInterface();
    interface.ask_color=CLI_BLUE;
    long age=interface.ask_long(&interface,"what is your age");
    printf("age %li\n",age);
    return 0;

 }
 ~~~
 #### Setting response colour
 The response color is set to red.
~~~c
#include "clinput.h"
 int main(){
    CliInterface interface=newCliInterface();
    interface.response_color=CLI_RED;
    long age=interface.ask_long(&interface,"what is your age");
    printf("age %li\n",age);
    return 0;

 }
 ~~~

### Options page
This page allows selection of options provide and returns the index of the selected option
~~~c
#include "clinput.h"


long main(){

   CliInterface  interface = newCliInterface();
   interface.wrong_option_menssage="Come on don't panic...you are either one of those";
    int chosed = interface.ask_option(&interface,"Are you religious" ,"yes | no");

    printf("%i\n",chosed);
    return 0;
}
~~~
### Printing texts with color
This code segment sets the output in printf() to the color white
~~~c
    #include "clinput.h"


long main(){


    CliInterface  interface = newCliInterface();
    interface.print_color=CLI_WHITE;
    interface.print(&interface,"aaaaa %c  %s aaa",'a',"cxxx");
    printf("\nnormal denovo\n");

    return 0;
}
~~~

### Configuring errors mensags
#### Integer errors
Error messages are generated when invalid characters are produced,when a value other than an integer is entered, in the code segment below a default error message "The value its not a long Integer" is generated.
~~~c
    #include "clinput.h"


int main(){

   CliInterface  interface = newCliInterface();
   interface.invalid_long_menssage = "The value its not an Integer";
   long age=interface.ask_long(&interface,"what is your age");
   printf("age %li\n",age);
    return 0;
}
~~~
#### Double errors 
Error messages are generated when invalid characters are produced,when a value that is not is not a double in the code segment below a default error message "The value its not a double" is generated.
~~~c
    #include "clinput/clinput.h"


int main(){

   CliInterface  interface = newCliInterface();
   interface.invalid_long_menssage = "The value its not a double";
   long age=interface.ask_long(&interface,"what is your weight");
   printf("weight: %f\n",weight);
    return 0;
}
~~~
#### Option errors 
Error messages are generated when invalid option is selected,when a value that is not is not in the options, the error message "The option does not exist" is generated.
~~~c
    #include "clinput/clinput.h"


int main(){

   CliInterface  interface = newCliInterface();
   interface.wrong_option_menssage="The option does not exist ";
    int chosed = interface.ask_option(&interface,"Are you religious?:" ,"yes | no");
    printf("%i\n",chosed);
    return 0;
}
~~~

