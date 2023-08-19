

#include "cpg.h"

PGconn *conn;
PGresult *res; 


// get postgresql version
int GetPgLibVersion(){
  int lib_ver = PQlibVersion();
  return lib_ver;
}

// exit then postgresql  bad connection
// stop postgresql connection and kill program
void KillPg(){

  printf("Connection kill\n");
  PQfinish(conn);
  exit(1);
}
// close postgresql connection
void ClosePg(){
  printf("Connection close\n");
  PQfinish(conn);
  
}

// connect postgresql
void ConnectPg(const char *cinfos){
   conn = PQconnectdb(cinfos);

if (PQstatus(conn) ==CONNECTION_BAD)
    {
      PQerrorMessage(conn);
      KillPg();
    }
    printf("Connection ok\n");
  
}
// clear postgresql results
void ClearPg(){
  PQclear(res);
}


// execute sql commands
void Query(const char* query ){
  res = PQexec(conn, query);
  if (PQresultStatus(res) != PGRES_TUPLES_OK){
    printf("No data retrieved\n");        
    ClosePg();
  }
  printf("%s\n", PQgetvalue(res, 0, 0));
  ClearPg();
}





