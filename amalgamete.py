import CToolKit as ct

STARTER  = f'clinput/CliInterface/CliInterface.h'
OUTPUT = 'clinput.h'
amalgamated_code = ct.generate_amalgamated_code(STARTER,OUTPUT)