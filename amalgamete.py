import CToolKit as ct

STARTER  = f'CliInterface/CliInterface.h'
OUTPUT = 'amalgamated.h'
amalgamated_code = ct.generate_amalgamated_code(STARTER,OUTPUT)