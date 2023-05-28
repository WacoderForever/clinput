

typedef struct CliInterface{

    //colors
    char * warning_color;
    char * error_color;
    char * normal_color;
    char * ask_color;
    char * response_color;
    char * sucess_color;


    //warnings mensage
    char * invalid_int_menssage;
    char * wrong_option_menssage;

    char   *(*ask_string)(struct CliInterface *self,const char *mensage,bool trim);

    int   (*ask_integer)(struct CliInterface *self,const char *mensage);
    long  (*ask_long)(struct CliInterface *self,const char *mensage);

    double (*ask_double)(struct CliInterface *self,const char *mensage,double min, double max);




}CliInterface;


//constructor method
CliInterface newCliInterface();


char * CliInterface_ask_string(struct  CliInterface *self,const char *mensage,bool trim);
long   CliInterface_ask_long(struct CliInterface *self,const char *mensage);