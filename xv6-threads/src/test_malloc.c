#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"

/*test
  test malloc in one thread 
*/
int global;

void threadfunc2(void *arg1, void *arg2) {
  int *mal = malloc(sizeof(int)); 
  *mal =2;
  
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

  thread_join();

  printf(1,"global = %d\n",global);

  exit();
}