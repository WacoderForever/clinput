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


char *cli_trim_string(const char *value);


typedef struct CliInterface{

    //colors

    char * error_color;
    char * normal_color;
    char * warning_color;
    char * ask_color;
    char * print_color;
    char * response_color;


    //warnings mensage
    char * invalid_long_menssage;
    char * invalid_double_menssage;
    char * wrong_option_menssage;
    char *empty_response_menssage;

    char   *(*ask_string)(struct CliInterface *self,const char *mensage,bool trim);
    long  (*ask_long)(struct CliInterface *self,const char *mensage);
    double (*ask_double)(struct CliInterface *self,const char *mensage);
    int (*ask_option)(struct CliInterface *self,const  char *mensage,const char *options);
    void (*print)(struct CliInterface *self,const  char *format,...);
    void (*warning)(struct CliInterface *self,const  char *format,...);



}CliInterface;


//constructor method
CliInterface newCliInterface();

char * CliInterface_ask_string(struct  CliInterface *self,const char *mensage,bool trim);
long   CliInterface_ask_long(struct CliInterface *self,const char *mensage);
double CliInterface_ask_double(struct CliInterface *self,const char *mensage);
int CliInterface_ask_option(struct CliInterface *self,const  char *mensage,const char *options);
void CliInterface_print(struct CliInterface *self,const  char *format,...);
void CliInterface_warning(struct CliInterface *self,const  char *format,...);



char *cli_trim_string(const char *value){
    //implementing the trim system

    long value_size = strlen(value);
    if(value_size == 0){
        return NULL;
    }

    char *formated_value = (char*)malloc(value_size + 2);
    bool finded_start = false;
    int text_size = 0;

    for(int i = 0; i < value_size;i++){

        char current_char = value[i];

        if( current_char != ' '){
            finded_start = true;
        }

        if(finded_start){
            formated_value[text_size] = current_char;
            text_size++;
        }
    }


    if(text_size == 0){
        free(formated_value);
        return NULL;
    }

    for(int i = text_size; i >= 0;i--){
        char current_char = formated_value[i -1];
        if(current_char !=  ' '){
            formated_value[i] = '\0';
            break;
        }

    }


    return formated_value;

}
CliInterface newCliInterface(){
    CliInterface self;


    self.error_color = CLI_RED;
    self.normal_color = CLI_WHITE;
    self.print_color = CLI_BLUE;
    self.warning_color=CLI_YELLOW;
    self.ask_color = CLI_GREEN;
    self.response_color =CLI_MAGENTA;

    self.invalid_long_menssage = "The value its not an Integer";
    self.invalid_double_menssage = "The value its not a double";
    self.wrong_option_menssage = "These option is not in the list";
    self.empty_response_menssage = "Empty Response are not allowed";

    //methods
    self.ask_string = CliInterface_ask_string;

    self.ask_long= CliInterface_ask_long;
    self.ask_double= CliInterface_ask_double;
    self.ask_option = CliInterface_ask_option;
    self.warning=CliInterface_warning;
    self.print = CliInterface_print;
    return self;

}



char * CliInterface_ask_string(struct CliInterface *self,const char *mensage,bool trim){

    while(true){
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

        value[value_size]= '\0';

        if (trim == CLI_NOT_TRIM){
            char *formated_value = (char*)malloc(value_size + 2);
            strcpy(formated_value,value);
            if(strlen(formated_value) == 0){
                printf("%s %s\n",self->error_color,self->empty_response_menssage);
                printf("%s",self->normal_color);
                free(formated_value);
                continue;
            }
            return formated_value;
        }

        else{
            char *result =  cli_trim_string(value);
            if(!result){
                printf("%s %s\n",self->error_color,self->empty_response_menssage);
                printf("%s",self->normal_color);
                continue;
            }
            return result;
        }
    }



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

int CliInterface_ask_option(struct CliInterface *self,const  char *mensage,const char *options){
    char *structured_options[30];
    int total_options = 0;

    long options_text_size = strlen(options);
    char buffer[100] = {0};
    int buffer_size = 0;

    for(int i =0; i < options_text_size; i++){
        char current_char = options[i];
        //the scape char
        if(current_char == '\\'){
            i++;
            continue;
        }

        if(current_char == '|'){
            char *trimed = cli_trim_string(buffer);
            if(trimed == NULL){
                buffer_size = 0;
                memset(buffer,0,100);
                continue;
            };

            structured_options[total_options] = trimed;
            buffer_size = 0;
            memset(buffer,0,100);

            total_options++;
            continue;
        }

        else{
            buffer[buffer_size] = current_char;
            buffer_size++;
        }
    }


    char *trimed = cli_trim_string(buffer);
    if(trimed != NULL){
        structured_options[total_options] = trimed;
        total_options++;
    };

;

    //checking if the awsner its valid

    int selected_option;
    while (true){
        bool ended = false;
        char *result = self->ask_string(self,mensage,CLI_TRIM);

        for(int i = 0; i <total_options; i++ ) {
            char *current_option = structured_options[i];
            if(strcmp(current_option,result) == 0){
                selected_option = i;
                ended = true;
                break;
            }
        }

        free(result);
        if(ended){
            break;
        }
        else{
            char formated_mensage[3000];
            sprintf(formated_mensage,"%s (",self->wrong_option_menssage);
            for(int i = 0; i <total_options; i++ ){
                char *current_option = structured_options[i];
                strcat(formated_mensage,"\"");
                strcat(formated_mensage,current_option);
                strcat(formated_mensage,"\"");
                if(i < total_options -1){
                    strcat(formated_mensage,",");

                }
            }
            strcat(formated_mensage,")");
            printf("%s %s\n",self->error_color,formated_mensage);
            printf("%s",self->normal_color);
        }

    }

    //free memory
    for(int i = 0; i <total_options; i++ ) {
        char *current_option = structured_options[i];
        free(current_option);
    }



    return selected_option;

    return 0;
}


void CliInterface_print(struct CliInterface *self,const  char *format,...){

    va_list  argptr;
    va_start(argptr, format);

    int text_size = strlen(format);

    printf("%s",self->print_color);

    for(int i =0;i < text_size ;i++){
        char last_char =  format[i-1];
        char current_char =  format[i];
        if(last_char =='%'){
            if(current_char == 'd' || current_char == 'i'){

                printf("%d", va_arg(argptr,int));
            }

            else if(current_char == 'c'){
                char result = va_arg(argptr,int);
                printf("%c",result);
            }

            else if(current_char == 'b'){
                bool value = va_arg(argptr,int);
                if(value){
                    printf("true");
                }else{
                    printf("false");
                }
            }
            else if(current_char == 's'){
                const char *value = va_arg(argptr,const char*);
                printf("%s",value);
            }

            else{
                printf("%c",current_char);
            }

            continue;
        }

        if(current_char == '%'){
            continue;
        }
        printf("%c",current_char);

    }
    printf("%s",self->normal_color);
    va_end(argptr);

}

void CliInterface_warning(struct CliInterface *self,const  char *format,...){

    va_list  argptr;
    va_start(argptr, format);

    int text_size = strlen(format);

    printf("%s",self->warning_color);

    for(int i =0;i < text_size ;i++){
        char last_char =  format[i-1];
        char current_char =  format[i];
        if(last_char =='%'){
            if(current_char == 'd' || current_char == 'i'){

                printf("%d", va_arg(argptr,int));
            }

            else if(current_char == 'c'){
                char result = va_arg(argptr,int);
                printf("%c",result);
            }

            else if(current_char == 'b'){
                bool value = va_arg(argptr,int);
                if(value){
                    printf("true");
                }else{
                    printf("false");
                }
            }
            else if(current_char == 's'){
                const char *value = va_arg(argptr,const char*);
                printf("%s",value);
            }

            else{
                printf("%c",current_char);
            }

            continue;
        }

        if(current_char == '%'){
            continue;
        }
        printf("%c",current_char);

    }
    printf("%s",self->normal_color);
    va_end(argptr);

}

#endif