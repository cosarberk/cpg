#include <stdio.h>
#include <stdlib.h>
#include "cpg/cpg.h"

const char *cinfos="host= port=5432 dbname= user= password=";





int main() {
  printf("Version of libpq: %d\n", GetPgLibVersion());
  ConnectPg(cinfos);
  //Query("SELECT * FROM glb_hobbys",1,2);
  QueryPrint("SELECT * FROM glb_hobbys");

  ClosePg();
  return 0;
}





