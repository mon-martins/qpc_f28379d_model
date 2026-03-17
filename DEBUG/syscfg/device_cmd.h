#ifndef DEVICE_CMD_H
#define DEVICE_CMD_H

#include <cpy_tbl.h>


#ifdef CMD_Config
extern COPY_TABLE copyTable_ramfunc;
extern COPY_TABLE copyTable_cla1Prog;
void CMD_Config_init();
#endif

void CMD_init();

#endif
