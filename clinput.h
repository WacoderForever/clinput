/*
MIT License

Copyright (c) 2023 WacoderForever

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef CLI_INPUT
#define CLI_INPUT


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

#define CLI_TRIM true
#define CLI_NOT_TRIM false
#define CLI_RED     "\x1b[31m"
#define CLI_GREEN   "\x1b[32m"
#define CLI_YELLOW  "\x1b[33m"
#define CLI_BLUE    "\x1b[34m"
#define CLI_MAGENTA "\x1b[35m"
#define CLI_CYAN    "\x1b[36m"
#define CLI_WHITE   "\x1b[0m"


typedef struct CliInterface{

    //colors
    char * warning_color;
    char * error_color;
    char * normal_color;
    char * ask_color;
    char * response_color;
    char * sucess_color;


    //warnings mensage
    char * invalid_long_menssage;
    char * invalid_double_menssage;
    char * wrong_option_menssage;


    char   *(*ask_string)(struct CliInterface *self,const char *mensage,bool trim);


    long  (*ask_long)(struct CliInterface *self,const char *mensage);

    double (*ask_double)(struct CliInterface *self,const char *mensage);
    int (*ask_option)(struct CliInterface *self,const  char *mensage,char *options[]);





}CliInterface;


//constructor method
CliInterface newCliInterface();


char * CliInterface_ask_string(struct  CliInterface *self,const char *mensage,bool trim);
long   CliInterface_ask_long(struct CliInterface *self,const char *mensage);
double CliInterface_ask_double(struct CliInterface *self,const char *mensage);
int CliInterface_ask_option(struct CliInterface *self, const  char *mensage,char *options[]);



CliInterface newCliInterface(){
    CliInterface self;

    self.warning_color = CLI_YELLOW;
    self.error_color = CLI_RED;
    self.normal_color = CLI_WHITE;

    self.ask_color = CLI_GREEN;
    self.response_color =CLI_MAGENTA;
    self.sucess_color = CLI_BLUE;

    self.invalid_long_menssage = "The value its not an Integer";
    self.invalid_double_menssage = "The value its not a double";
    self.wrong_option_menssage = "The value should be betwen #options#";

    //methods
    self.ask_string = CliInterface_ask_string;

    self.ask_long= CliInterface_ask_long;
    self.ask_double= CliInterface_ask_double;
    self.ask_option = CliInterface_ask_option;
    return self;

}



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
long CliInterface_ask_long(struct CliInterface *self,const char *mensage){
   while(true){
     char *value=self->ask_string(self,mensage,CLI_TRIM);
    long converted;
     int result =  sscanf(value,"%li",&converted);
     free(value);
     //means its an error

     if(result == 0){
         printf("%s %s\n",self->error_color,self->invalid_long_menssage);
         printf("%s",self->normal_color);

     }
     else{
         return converted;
     }

   }

}


double CliInterface_ask_double(struct CliInterface *self,const char *mensage){
     while(true){
     char *value=self->ask_string(self,mensage,CLI_TRIM);
     double converted;
     int result =  sscanf(value,"%lf",&converted);
     free(value);
     //means its an error

     if(result == 0){
         printf("%s %s\n",self->error_color,self->invalid_double_menssage);
         printf("%s",self->normal_color);

     }
     else{
         return converted;
     }

   }
}

int CliInterface_ask_option(struct CliInterface *self,const  char *mensage,char *options[]){
    /*
    int options_size = sizeof(options)  / sizeof(options[0]);

    char formated_mensage[3000];
    sprintf(formated_mensage,"%s: (",mensage);

    for(int i = 0; i < options_size; i++){
        strcat(formated_mensage,options[i]);
        strcat(formated_mensage," ");
    }
    strcat(formated_mensage,")");


    char *result = self->ask_string(self,formated_mensage,CLI_TRIM);
    */
}
#endif