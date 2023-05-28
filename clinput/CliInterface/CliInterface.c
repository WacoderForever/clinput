
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
    self.wrong_option_menssage = "These its not an valid option";

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

    value[value_size]= '\0';

    if (trim == CLI_NOT_TRIM){
        char *formated_value = (char*)malloc(value_size + 2);
        strcpy(formated_value,value);
        return formated_value;
    }
    else{
        return cli_trim_string(value);
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
    char buffer[1000] = {0};
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
                continue;
            };
            structured_options[total_options] = trimed;
            buffer_size = 0;
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

    char formated_mensage[3000];

    sprintf(formated_mensage,"%s (",mensage);
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

    //checking if the awsner its valid

    int selected_option;
    while (true){

        char *result = self->ask_string(self,formated_mensage,CLI_TRIM);
        bool ended = false;

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
            printf("%s %s\n",self->error_color,self->wrong_option_menssage);
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