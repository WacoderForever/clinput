# Description
The CLi input its an lib that allows you to get user informations in an beautfull way


### Installation
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
CLi input gives extensive coverage of functions that improve visuals when using the command line
##### Dealing with string
~~~~~c
char * CliInterface_ask_string(struct CliInterface *self,const char *mensage,bool trim){

    if(mensage[strlen(mensage)-1] != '\n'){
        printf("%s %s: ",self->ask_color,mensage);
    }
    else{
        printf("%s %s",self->ask_color,mensage);
    }
    printf("%s",self->response_color);

    fflush(stdin);
    char value[3000];
    int value_size;

    for(value_size =0; value_size < 1000;value_size++){
        char ch;
        ch = getchar();
        if(ch == '\n'){
            break;
        }
        value[value_size] = ch;
    }
    printf("%s",self->normal_color);


    char *formated_value = (char*)malloc(value_size + 2);
    strcpy(formated_value,"\0");

    if (trim == CLI_NOT_TRIM){
        strcpy(formated_value,value);
        formated_value[value_size]= '\0';
        return formated_value;
    }

    //implementing the trim system

    bool finded_start = false;
    int text_size = 0;


    for(int i = 0; i < value_size;i++){
        char current_char = value[i];

        if(current_char != ' '){
            finded_start = true;
        }
        if(finded_start){
            formated_value[text_size] = current_char;
            text_size+=1;
        }
    }


    formated_value[text_size] = '\0';

    for(int i = text_size; i > 0; i--){
        char current_char = formated_value[i];

        if(current_char != ' ' && current_char != '\n' && current_char!= '\0'){
            formated_value[i+1] = '\0';
            break;
        }
    }

    return formated_value;


}
~~~~~


### Configuring colors 


### Configuring errors mensags

