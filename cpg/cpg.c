

#include "cpg.h"

PGconn *conn;
PGresult *res; 
FILE *fp;

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

void Print(PGresult * res){
  FileOut();
typedef struct
{
    pqbool  header;      /* print output field headings and row count */
    pqbool  align;       /* fill align the fields */
    pqbool  standard;    /* old brain dead format */
    pqbool  html3;       /* output HTML tables */
    pqbool  expanded;    /* expand tables */
    pqbool  pager;       /* use pager for output if needed */
    char    *fieldSep;   /* field separator */
    char    *tableOpt;   /* attributes for HTML table element */
    char    *caption;    /* HTML table caption */
    char    **fieldName; /* null-terminated array of replacement field names */
} PQprintOpt;
 PQprintOpt *op;

 
 
  PQprint(fp,res, op);
}


void FileOut(){
if ((fp = fopen("out.html", "w")) == NULL) {
      printf("Dosya açma hatası!\n");
      exit(1);
  }
}

// execute sql commands
void Query(const char* query ,int i ,int j){
  res = PQexec(conn, query);
  if (PQresultStatus(res) != PGRES_TUPLES_OK){
    printf("No data retrieved\n");        
    ClosePg();
  }
  printf("%s\n", PQgetvalue(res, i, j));
  ClearPg();
}

// execute sql commands
void QueryPrint(const char* query){
  res = PQexec(conn, query);
  if (PQresultStatus(res) != PGRES_TUPLES_OK){
    printf("No data retrieved\n");        
    ClosePg();
  }
  Print(res);
  ClearPg();
}




