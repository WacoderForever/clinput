
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