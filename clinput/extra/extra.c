
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