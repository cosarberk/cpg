#include <stdio.h>
#include <stdlib.h>
#include "cpg/cpg.h"

const char *cinfos="host= port= dbname= user= password= ";


int main() {
  printf("Version of libpq: %d\n", GetPgLibVersion());
  ConnectPg(cinfos);
  Query("SELECT * FROM users");
  ClosePg();
  return 0;
}


