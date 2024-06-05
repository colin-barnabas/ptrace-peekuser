#include <stdbool.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  pid_t child;
  long orig_rax, rax;
  long params[3];
  int status;
  int insyscall = 0;
  struct user *user_space = (struct user *)0;
  child = fork();

  if (child == 0) {
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execl("/bin/ls", "ls", 0);
  } else {
    while (true) {
      wait(&status);
      if (WIFEXITED(status))
        break;
      orig_rax =
          ptrace(PTRACE_PEEKUSER, child, &user_space->regs.orig_rax, NULL);
        if (insyscall == 0) {
          // syscall entry
          insyscall = 1;
          params[0] =
              ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rbx, NULL);
          params[1] =
              ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rcx, NULL);
          params[2] =
              ptrace(PTRACE_PEEKUSER, child, &user_space->regs.rdx, NULL);

          printf("Syscall %llu called with %llu, %llu, %llu\n", orig_rax, params[1],
                 params[2]);
        } else {
          rax =
              ptrace(PTRACE_PEEKUSER, child, &user_space->regs.orig_rax, NULL);
          printf("Syscall %llu returned with %ld\n", orig_rax, rax);
          insyscall = 0;
        }
      ptrace(PTRACE_SYSCALL, child, NULL, NULL);
    }
  }
  return 0;
}
