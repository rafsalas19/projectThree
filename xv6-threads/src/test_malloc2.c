#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"

/*test
  test malloc in two threads 
*/
int global;
int global2;

void threadfunc2(void *arg1, void *arg2) {
  int *mal = malloc(sizeof(int)); 
  *mal =2;
  
  global2 = (int)arg1 + (int)arg2;
  
  global2 = global2 *(*mal);
  exit();
}

void threadfunc(void *arg1, void *arg2) {
  int *mal = malloc(sizeof(int)); 
  *mal =3;
  
  global = (int)arg1 + (int)arg2;
  
  global = global *(*mal);
  exit();
}

int main(int argc, char *argv[])
{
  int arg1 = 0;
  int arg2 = 2;
  int pid = thread_create(threadfunc2, (void*)arg1, (void *)arg2);
  printf(1,"parent this is childs return pid %d\n", pid);
  pid = thread_create(threadfunc, (void*)arg1, (void *)arg2);
  printf(1,"parent this is childs return pid %d\n", pid);
  thread_join();
 thread_join();
  printf(1,"globals = %d,%d \n",global, global2);

  exit();
}