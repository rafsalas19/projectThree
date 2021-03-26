#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"

/*tests
-check stack size
-malloc
-fork

*/
void check_fork();

int global;

void threadfunc3(void *arg1, void *arg2) {
  
  int pid = thread_create(threadfunc2, arg1, arg2);
  printf(1,"parent this is childs return pid %d\n", pid);

  thread_join();
  
  
  
  exit();
}

void threadfunc2(void *arg1, void *arg2) {
  int *mal = malloc(sizeof(int)); 
  *mal =2;
  
  global = (int)arg1 + (int)arg2;
  
  global = global *(*mal);
  exit();
}


void threadfunc(void *arg1, void *arg2) {
  
  int pid = thread_create(threadfunc2, arg1, arg2);
  printf(1,"parent this is childs return pid %d\n", pid);

  thread_join();
  
  
  
  exit();
}

void check_fork(){
  int cpid= fork();
  //printf(1,"global = %d\n",global);
  if(cpid==0){
    printf(1,"hello in child\n");
    exit();
  }else{
    printf(1,"parent\n");
  }
   //thread_join();
  wait();


}

void thread_check(){
  int arg1 = 0;
  int arg2 = 2;
  int pid = thread_create(threadfunc, (void*)arg1, (void *)arg2);
  printf(1,"parent this is childs return pid %d\n", pid);

  thread_join();


}


int main(int argc, char *argv[])
{

  //check_fork();
  thread_check();
  exit();
}
