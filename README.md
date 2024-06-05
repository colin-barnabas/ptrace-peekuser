## PTRACE_PEEKUSER Demo

```shell
11:50:06 ❯ make
/usr/bin/clang -ggdb3 -Wall -lm ptrace_peekuser.c -o ptrace_peekuser
ptrace_peekuser.c:40:65: warning: format specifies type 'unsigned long long' but the argument has type 'long' [-Wformat]
   40 |           printf("Syscall %llu called with %llu, %llu, %llu\n", orig_rax, params[1],
      |                           ~~~~                                  ^~~~~~~~
      |                           %ld
ptrace_peekuser.c:40:75: warning: format specifies type 'unsigned long long' but the argument has type 'long' [-Wformat]
   40 |           printf("Syscall %llu called with %llu, %llu, %llu\n", orig_rax, params[1],
      |                                            ~~~~                           ^~~~~~~~~
      |                                            %ld
ptrace_peekuser.c:41:18: warning: format specifies type 'unsigned long long' but the argument has type 'long' [-Wformat]
   40 |           printf("Syscall %llu called with %llu, %llu, %llu\n", orig_rax, params[1],
      |                                                  ~~~~
      |                                                  %ld
   41 |                  params[2]);
      |                  ^~~~~~~~~
ptrace_peekuser.c:40:59: warning: more '%' conversions than data arguments [-Wformat-insufficient-args]
   40 |           printf("Syscall %llu called with %llu, %llu, %llu\n", orig_rax, params[1],
      |                                                        ~~~^
ptrace_peekuser.c:45:54: warning: format specifies type 'unsigned long long' but the argument has type 'long' [-Wformat]
   45 |           printf("Syscall %llu returned with %ld\n", orig_rax, rax);
      |                           ~~~~                       ^~~~~~~~
      |                           %ld
5 warnings generated.
./ptrace_peekuser
rm ptrace_peekuser
Syscall 59 called with 0, 0, 2
Syscall 12 returned with 12
Syscall 12 called with 131755874605115, 0, 2
Syscall 9 returned with 9
Syscall 9 called with 131755874609900, 3, 2
Syscall 21 returned with 21
Syscall 21 called with 131755874608779, 0, 2
Syscall 257 returned with 257
Syscall 257 called with 131755874609457, 524288, 2
Syscall 262 returned with 262
Syscall 262 called with 131755874608878, 140733322979568, 2
Syscall 257 returned with 257
Syscall 257 called with 131755874609457, 524288, 2
Syscall 262 returned with 262
Syscall 262 called with 131755874608878, 140733322979568, 2
Syscall 257 returned with 257
...
Syscall 231 returned with 231
11:50:10 ❯
```
