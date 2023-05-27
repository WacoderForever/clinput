

typedef struct CliInterface{

    //colors
    char * warning_color;
    char * error_color;
    char * normal_color;
    char * sucess_color;



    //warnings mensage
    char * invalid_type_mensage;
    char * min_value_mensage;
    char * max_value_mensage;
    char * wrong_option_menssage;

    char   *(*ask_string)(struct CliInterface *self,char *mensage,bool trim);

    long   (*ask_integer)(struct CliInterface *self,char *mensage, long min, long max);
    double (*ask_double)(struct CliInterface *self,char *mensage,double min, double max);




}CliInterface;


//constructor method
CliInterface newCliInterface();


char * CliInterface_ask_string(struct CliInterface *self,char *mensage,bool trim);
