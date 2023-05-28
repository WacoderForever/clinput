

typedef struct CliInterface{

    //colors

    char * error_color;
    char * normal_color;
    char * ask_color;
    char * print_color;
    char * response_color;


    //warnings mensage
    char * invalid_long_menssage;
    char * invalid_double_menssage;
    char * wrong_option_menssage;


    char   *(*ask_string)(struct CliInterface *self,const char *mensage,bool trim);
    long  (*ask_long)(struct CliInterface *self,const char *mensage);
    double (*ask_double)(struct CliInterface *self,const char *mensage);
    int (*ask_option)(struct CliInterface *self,const  char *mensage,const char *options);
    void (*print)(struct CliInterface *self,const  char *format,...);




}CliInterface;


//constructor method
CliInterface newCliInterface();

char * CliInterface_ask_string(struct  CliInterface *self,const char *mensage,bool trim);
long   CliInterface_ask_long(struct CliInterface *self,const char *mensage);
double CliInterface_ask_double(struct CliInterface *self,const char *mensage);
int CliInterface_ask_option(struct CliInterface *self,const  char *mensage,const char *options);
void CliInterface_print(struct CliInterface *self,const  char *format,...);

