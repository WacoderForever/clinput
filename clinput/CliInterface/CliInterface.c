
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

char * CliInterface_ask_string(struct CliInterface *self,char *mensage){

    printf("%s %s:",self->normal_color,mensage);
    char *value = (char*)malloc(1000);
    scanf("%s",value);
    return value;
}