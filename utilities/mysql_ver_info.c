#include <stdio.h>
#include <mysql.h>
#include <my_global.h>

int main(void) {
  printf("MySQL client version: %s\n", mysql_get_client_info());
  return 0;
}
