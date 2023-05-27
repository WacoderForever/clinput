
CliInterface newCliInterface(){
    CliInterface self;

    self.warning_color = CLI_YELLOW;
    self.error_color = CLI_RED;
    self.normal_color = CLI_GREEN;
    self.sucess_color = CLI_BLUE;

    self.invalid_type_mensage = "The value its not an #type#";
    self.min_value_mensage = "The value its lower than #min_value#";
    self.max_value_mensage = "The value its higher than #max_value#";
    self.wrong_option_menssage = "The value should be betwen #options#";

    //methods
    self.ask_string = CliInterface_ask_string;
    return self;

}

char * CliInterface_ask_string(struct CliInterface *self,char *mensage,bool trim){

    printf("%s %s: ",self->normal_color,mensage);
    char value[1000];
    int value_size;

    for(value_size =0; value_size < 1000;value_size++){
        char ch;
        ch = getchar();
        if(ch == '\n'){
            break;
        }
        value[value_size] = ch;
    }


    char *formated_value = (char*)malloc(value_size);


    //implementing the trim system

    bool finded_start;
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

    formated_value[value_size] = '\0';


    return formated_value;
}