
CliInterface newCliInterface(){
    CliInterface self;

    self.warning_color = CLI_YELLOW;
    self.error_color = CLI_RED;
    self.normal_color = CLI_WHITE;

    self.ask_color = CLI_GREEN;
    self.response_color =CLI_MAGENTA;
    self.sucess_color = CLI_BLUE;


    self.invalid_type_mensage = "The value its not an #type#";
    self.min_value_mensage = "The value its lower than #min_value#";
    self.max_value_mensage = "The value its higher than #max_value#";
    self.wrong_option_menssage = "The value should be betwen #options#";

    //methods
    self.ask_string = CliInterface_ask_string;
    self.ask_integer=CliInterface_ask_integer;
    return self;

}



char * CliInterface_ask_string(struct CliInterface *self,char *mensage,bool trim){

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
long CliInterface_ask_integer(struct CliInterface *self,char *mensage,int min,int max){
    char *value=self->ask_string(self,mensage,CLI_TRIM);
    long converted_value=atoi(value);
    free(value);
    return converted_value;
}