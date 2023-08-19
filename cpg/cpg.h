#ifndef CPG_H
#define CPG_H


#include <stdio.h>
#include <stdlib.h>

#include "libpq/libpq-fe.h"


// get postgresql version
extern int GetPgLibVersion();


// exit then postgresql  bad connection
// stop postgresql connection and kill program
void KillPg();

// close postgresql connection
void ClosePg();

// connect postgresql
void ConnectPg();

// clear postgresql results
void ClearPg();

// execute sql commands
void Query(const char* query );



#endif
