/*
** syscalls.h for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/include
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Sat Apr 02 23:45:45 2016 Bastien DHIVER
** Last update Thu Apr  7 14:39:50 2016 florian videau
*/

#ifndef SYSCALLS_H_
# define SYSCALLS_H_

# define QUOTE(stuff)	#stuff

typedef enum		e_types
{
  E_UNKN,
  E_INT,
  E_STR,
  E_ADDR,
  E_STRUC,
  E_SIZE_T,
  E_INT_2,
  E_USI_L,
  E_STRSTR,
  E_LONG,
  E_END
}			t_types;

# define UNKN		E_UNKN
# define INT		E_INT
# define STR		E_STR
# define ADDR		E_ADDR
# define STRUC		E_STRUCT
# define SIZE_T		E_SIZE_T
# define INT_2		E_INT_2
# define USI_L		E_USI_L
# define STRSTR		E_STRSTR
# define LONG		E_LONG

# define S_UNKN		QUOTE(0)
# define S_INT		QUOTE(1)
# define S_STR		QUOTE(2)
# define S_ADDR		QUOTE(3)
# define S_STRUC	QUOTE(4)
# define S_SIZE_T	QUOTE(5)
# define S_INT_2	QUOTE(6)
# define S_USI_L	QUOTE(7)
# define S_STRSTR	QUOTE(8)
# define S_LONG		QUOTE(9)

typedef	struct		s_syscalls
{
  char			*name;
  int			ret;
  char			*args;
}			t_syscalls;

const t_syscalls	g_syscalls[] =
	{{"read", INT, S_INT S_STR S_SIZE_T},
	{"write", INT, S_INT S_STR S_SIZE_T},
	{"open", INT, S_STR S_INT},
	{"close", INT, S_INT},
	{"stat", INT, S_STR S_STRUC},
	{"fstat", INT, S_INT S_STRUC},
	{"lstat", INT, S_STR S_STRUC},
	{"poll", INT, S_STRUC S_INT S_INT},
	{"lseek", INT, S_INT S_INT S_INT},
	{"mmap", ADDR, S_ADDR S_SIZE_T S_INT S_INT S_INT S_INT},
	{"mprotect", INT, S_ADDR S_SIZE_T S_INT},
	{"munmap", INT, S_ADDR S_SIZE_T},
	{"brk", ADDR, S_INT},
	{"rt_sigaction", INT, S_INT S_STRUC S_STRUC},
	{"rt_sigprocmask", INT, S_INT S_ADDR S_ADDR},
	{"rt_sigreturn", INT, S_UNKN},
	{"ioctl", INT, S_INT S_USI_L S_UNKN},
	{"pread64", INT, S_INT S_ADDR S_SIZE_T S_INT},
	{"pwrite64", INT, S_INT S_ADDR S_SIZE_T S_INT},
	{"readv", INT, S_INT S_STRUC S_INT},
	{"writev", INT, S_INT S_STRUC S_INT},
	{"access", INT, S_STR S_INT},
	{"pipe", INT, S_INT_2},
	{"select", INT, S_INT S_ADDR S_ADDR S_ADDR S_STRUC},
	{"sched_yield", INT, ""},
	{"mremap", ADDR, S_ADDR S_SIZE_T S_SIZE_T S_INT S_ADDR},
	{"msync", INT, S_ADDR S_SIZE_T S_INT},
	{"mincore", INT, S_ADDR S_SIZE_T S_ADDR},
	{"madvise", INT, S_ADDR S_SIZE_T S_INT},
	{"shmget", INT, S_INT S_SIZE_T S_INT},
	{"shmat", ADDR, S_INT S_ADDR S_INT},
	{"shmctl", INT, S_INT S_INT S_STRUC},
	{"dup", INT, S_INT},
	{"dup2", INT, S_INT S_INT},
	{"pause", INT, ""},
	{"nanosleep", INT, S_STRUC S_STRUC},
	{"getitimer", INT, S_INT S_STRUC},
	{"alarm", SIZE_T, S_SIZE_T},
	{"setitimer", INT, S_STRUC S_STRUC},
	{"getpid", INT, ""},
	{"sendfile", INT, S_INT S_INT S_ADDR S_SIZE_T},
	{"socket", INT, S_INT S_INT S_INT},
	{"connect", INT, S_INT S_STRUC S_INT},
	{"accept", INT, S_INT S_STRUC S_ADDR},
	{"sendto", INT, S_INT S_ADDR S_SIZE_T S_INT S_STRUC S_INT},
	{"recvfrom", INT, S_INT S_ADDR S_SIZE_T S_INT S_STRUC S_ADDR},
	{"sendmsg", INT, S_INT S_STRUC S_INT},
	{"recvmsg", INT, S_INT S_STRUC S_INT},
	{"shutdown", INT, S_INT S_INT},
	{"bind", INT, S_INT S_STRUC S_INT},
	{"listen", INT, S_INT S_INT},
	{"getsockname", INT, S_INT S_STRUC S_INT},
	{"getpeername", INT, S_INT S_STRUC S_INT},
	{"socketpair", INT, S_INT S_INT S_INT S_INT_2},
	{"setsockopt", INT, S_INT S_INT S_INT S_ADDR S_INT},
	{"getsockopt", INT, S_INT S_INT S_INT S_ADDR S_INT},
	{"clone", INT, S_USI_L S_ADDR S_ADDR S_ADDR S_STRUC},
	{"fork", INT, ""},
	{"vfork", INT, ""},
	{"execve", INT, S_STR S_STRSTR S_STRSTR},
	{"exit", UNKN, S_INT},
	{"wait4", INT, S_INT S_ADDR S_INT S_STRUC},
	{"kill", INT, S_INT S_INT},
	{"uname", INT, S_STRUC},
	{"semget", INT, S_INT S_INT S_INT},
	{"semop", INT, S_INT S_STRUC S_SIZE_T},
	{"semctl", INT, S_INT S_INT S_INT S_UNKN},
	{"shmdt", INT, S_ADDR},
	{"msgget", INT, S_INT S_INT},
	{"msgsnd", INT, S_INT S_ADDR S_SIZE_T S_INT},
	{"msgrcv", INT, S_INT S_ADDR S_SIZE_T S_LONG S_INT},
	{"msgctl", INT, S_INT S_INT S_STRUC},
	{"fcntl", INT, S_INT S_INT S_UNKN},
	{"flock", INT, S_INT S_INT},
	{"fsync", INT, S_INT},
	{"fdatasync", INT, S_INT},
	{"truncate", INT, S_STR S_INT},
	{"ftruncate", INT, S_INT S_INT},
	{"getdents", INT, S_SIZE_T S_STRUC S_SIZE_T},
	{"getcwd", STR, S_STR S_SIZE_T},
	{"chdir", INT, S_STR},
	{"fchdir", INT, S_INT},
	{"rename", INT, S_STR S_STR},
	{"mkdir", INT, S_STR S_INT},
	{"rmdir", INT, S_STR},
	{"creat", INT, S_STR S_INT},
	{"link", INT, S_STR S_STR},
	{"unlink", INT, S_STR},
	{"symlink", INT, S_STR S_STR},
	{"readlink", INT, S_STR S_STR S_SIZE_T},
	{"chmod", INT, S_STR S_INT},
	{"fchmod", INT, S_INT},
	{"chown", INT, S_STR S_INT S_INT},
	{"fchown", INT, S_INT S_INT S_INT},
	{"lchown", INT, S_STR S_INT S_INT},
	{"umask", INT, S_INT},
	{"gettimeofday", INT, S_STRUC S_STRUC},
	{"getrlimit", INT, S_INT S_STRUC},
	{"getrusage", INT, S_INT S_STRUC},
	{"sysinfo", INT, S_STRUC},
	{"times", INT, S_STRUC},
	{"ptrace", LONG, S_INT S_INT S_ADDR S_ADDR},
	{"getuid", INT, ""},
	{"syslog", INT, S_INT S_STR S_INT},
	{"getgid", INT, ""},
	{"setuid", INT, S_INT},
	{"setgid", INT, S_INT},
	{"geteuid", INT, ""},
	{"getegid", INT, ""},
	{"setpgid", INT, S_INT S_INT},
	{"getppid", INT, ""},
	{"getpgrp", INT, S_INT},
	{"setsid", INT, ""},
	{"setreuid", INT, S_INT S_INT},
	{"setregid", INT, S_INT S_INT},
	{"getgroups", INT, S_INT S_ADDR},
	{"setgroups", INT, S_INT S_ADDR},
	{"setresuid", INT, S_INT S_INT S_INT},
	{"getresuid", INT, S_INT S_INT S_INT},
	{"setresgid", INT, S_INT S_INT S_INT},
	{"getresgid", INT, S_INT S_INT S_INT},
	{"getpgid", INT, S_INT},
	{"setfsuid", INT, S_INT},
	{"setfsgid", INT, S_INT},
	{"getsid", INT, S_INT},
	{"capget", INT, S_INT S_INT},
	{"capset", INT, S_INT S_INT},
	{"rt_sigpending", INT, S_ADDR},
	{"rt_sigtimedwait", INT, S_ADDR S_ADDR S_STRUC},
	{"rt_sigqueueinfo", INT, S_INT S_INT S_ADDR},
	{"rt_sigsuspend", INT, S_ADDR},
	{"sigaltstack", INT, S_ADDR S_ADDR},
	{"utime", INT, S_STR S_STRUC},
	{"mknod", INT, S_STR S_INT S_INT},
	{"uselib", INT, S_STR},
	{"personality", INT, S_USI_L},
	{"ustat", INT, S_INT S_STRUC},
	{"statfs", INT, S_STR S_STRUC},
	{"fstatfs", INT, S_INT S_STRUC},
	{"sysfs", INT, S_INT},
	{"getpriority", INT, S_INT S_INT},
	{"setpriority", INT, S_INT S_INT S_INT},
	{"sched_setparam", INT, S_INT S_STRUC},
	{"sched_getparam", INT, S_INT S_STRUC},
	{"sched_setscheduler", INT, S_INT S_INT S_STRUC},
	{"sched_getscheduler", INT, S_INT},
	{"sched_get_priority_max", INT, S_INT},
	{"sched_get_priority_min", INT, S_INT},
	{"sched_rr_get_interval", INT, S_INT S_STRUC},
	{"mlock", INT, S_ADDR S_SIZE_T},
	{"munlock", INT, S_ADDR S_SIZE_T},
	{"mlockall", INT, S_INT},
	{"munlockall", INT, ""},
	{"vhangup", INT, ""},
	{"modify_ldt", INT, S_INT S_ADDR S_USI_L},
	{"pivot_root", INT, S_STR S_STR},
	{"_sysctl", INT, S_STRUC},
	{"prctl", INT, S_INT S_USI_L S_USI_L S_USI_L S_USI_L},
	{"arch_prctl", INT, S_INT S_USI_L},
	{"adjtimex", INT, S_ADDR},
	{"setrlimit", INT, S_INT S_STRUC},
	{"chroot", INT, S_STR},
	{"sync", UNKN, ""},
	{"acct", INT, S_STR},
	{"settimeofday", INT, S_STRUC S_STRUC},
	{"mount", INT, S_STR S_STR S_STR S_USI_L S_ADDR},
	{"umount2", INT, S_STR S_INT},
	{"swapon", INT, S_STR S_INT},
	{"swapoff", INT, S_STR},
	{"reboot", INT, S_INT},
	{"sethostname", INT, S_STR S_SIZE_T},
	{"setdomainname", INT, S_STR S_SIZE_T},
	{"iopl", INT, S_INT},
	{"ioperm", INT, S_USI_L S_USI_L S_INT},
	{"create_module", INT, S_STR S_SIZE_T},
	{"init_module", INT, S_ADDR S_USI_L S_STR},
	{"delete_module", INT, S_STR S_INT},
	{"get_kernel_syms", INT, S_STRUC},
	{"query_module", INT, S_STR S_INT S_ADDR S_SIZE_T S_ADDR},
	{"quotactl", INT, S_INT S_STR S_INT S_INT},
	{"nfsservctl", LONG, S_INT S_STRUC S_ADDR},
	{"getpmsg", UNKN, ""},
	{"putpmsg", UNKN, ""},
	{"afs_syscall", UNKN, ""},
	{"tuxcall", UNKN, ""},
	{"security", UNKN, ""},
	{"gettid", INT, ""},
	{"readahead", INT, S_INT S_INT S_SIZE_T},
	{"setxattr", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
	{"lsetxattr", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
	{"fsetxattr", INT, S_INT S_STR S_ADDR S_SIZE_T S_INT},
	{"getxattr", INT, S_STR S_STR S_ADDR S_SIZE_T},
	{"lgetxattr", INT, S_STR S_STR S_ADDR S_SIZE_T},
	{"fgetxattr", INT, S_INT S_STR S_ADDR S_SIZE_T},
	{"listxattr", INT, S_STR S_STR S_SIZE_T},
	{"llistxattr", INT, S_STR S_STR S_SIZE_T},
	{"flistxattr", INT, S_INT S_STR S_SIZE_T},
	{"removexattr", INT, S_STR S_STR},
	{"lremovexattr", INT, S_STR S_STR},
	{"fremovexattr", INT, S_INT S_STR},
	{"tkill", INT, S_INT S_INT},
	{"time", INT, S_ADDR},
	{"futex", INT, S_ADDR S_INT S_INT S_STRUC S_ADDR S_INT},
	{"sched_setaffinity", INT, S_INT S_SIZE_T S_ADDR},
	{"sched_getaffinity", INT, S_INT S_SIZE_T S_ADDR},
	{"set_thread_area", INT, S_STRUC},
	{"io_setup", INT, S_SIZE_T S_ADDR},
	{"io_destroy", INT, S_SIZE_T},
	{"io_getevents", INT, S_SIZE_T S_LONG S_LONG S_STRUC S_STRUC},
	{"io_submit", INT, S_INT S_LONG S_ADDR},
	{"io_cancel", INT, S_SIZE_T S_STRUC S_STRUC},
	{"get_thread_area", INT, S_STRUC},
	{"lookup_dcookie", INT, S_SIZE_T S_STR S_SIZE_T},
	{"epoll_create", INT, S_INT},
	{"epoll_ctl_old", UNKN, ""},
	{"epoll_wait_old", UNKN, ""},
	{"remap_file_pages", INT, S_ADDR S_SIZE_T S_INT S_SIZE_T S_INT},
	{"getdents64", INT, S_SIZE_T S_STRUC S_SIZE_T},
	{"set_tid_address", LONG, S_ADDR},
	{"restart_syscall", INT, ""},
	{"semtimedop", INT, S_INT S_STRUC S_SIZE_T},
	{"fadvise64", INT, S_INT S_INT S_INT S_INT},
	{"timer_create", INT, S_INT S_STRUC S_ADDR},
	{"timer_settime", INT, S_INT S_INT S_STRUC S_STRUC},
	{"timer_gettime", INT, S_INT S_STRUC},
	{"timer_getoverrun", INT, S_INT},
	{"timer_delete", INT, S_INT},
	{"clock_settime", INT, S_INT S_STRUC},
	{"clock_gettime", INT, S_INT S_STRUC},
	{"clock_getres", INT, S_INT S_STRUC},
	{"clock_nanosleep", INT, S_INT S_INT S_STRUC S_STRUC},
	{"exit_group", UNKN, S_INT},
	{"epoll_wait", INT, S_INT S_STRUC S_INT S_INT},
	{"epoll_ctl", INT, S_INT S_INT S_INT S_STRUC},
	{"tgkill", INT, S_INT S_INT S_INT},
	{"utimes", INT, S_STR S_STRUC},
	{"vserver", UNKN, ""},
	{"mbind", LONG, S_ADDR S_USI_L S_INT S_ADDR S_USI_L S_SIZE_T},
	{"set_mempolicy", LONG, S_INT S_ADDR S_USI_L},
	{"get_mempolicy", INT, S_ADDR S_ADDR S_USI_L S_USI_L S_USI_L},
	{"mq_open", INT, S_STR S_INT},
	{"mq_unlink", INT, S_STR},
	{"mq_timedsend", INT, S_INT S_STR S_SIZE_T S_SIZE_T},
	{"mq_timedreceive", INT, S_INT S_STR S_SIZE_T S_ADDR S_STRUC},
	{"mq_notify", INT, S_INT S_STRUC},
	{"mq_getsetattr", INT, S_INT S_STRUC S_STRUC},
	{"kexec_load", LONG, S_USI_L S_USI_L S_STRUC S_USI_L},
	{"waitid", INT, S_INT S_ADDR S_INT},
	{"add_key", INT, S_STR S_STR S_ADDR S_SIZE_T S_INT},
	{"request_key", INT, S_STR S_STR S_STR S_INT},
	{"keyctl", LONG, S_INT S_UNKN},
	{"ioprio_set", INT, S_INT S_INT S_INT},
	{"ioprio_get", INT, S_INT S_INT},
	{"inotify_init", INT, ""},
	{"inotify_add_watch", INT, S_INT S_STR S_INT},
	{"inotify_rm_watch", INT, S_INT S_INT},
	{"migrate_pages", LONG, S_INT S_USI_L S_ADDR S_ADDR},
	{"openat", INT, S_INT S_STR S_INT},
	{"mkdirat", INT, S_INT S_STR S_INT},
	{"mknodat", INT, S_INT S_STR S_INT S_INT},
	{"fchownat", INT, S_INT S_STR S_INT S_INT S_INT},
	{"futimesat", INT, S_INT S_STR S_STRUC},
	{"newfstatat", INT, S_INT S_STR S_STRUC S_INT},
	{"unlinkat", INT, S_INT S_STR S_INT},
	{"renameat", INT, S_INT S_STR S_INT S_STR},
	{"linkat", INT, S_INT S_STR S_INT S_STR S_INT},
	{"symlinkat", INT, S_STR S_INT S_STR},
	{"readlinkat", INT, S_INT S_STR S_STR S_SIZE_T},
	{"fchmodat", INT, S_INT S_STR S_INT S_INT},
	{"faccessat", INT, S_INT S_STR S_INT S_INT},
	{"pselect6", INT, S_INT S_ADDR S_ADDR S_ADDR S_STRUC S_ADDR},
	{"ppoll", INT, S_STRUC S_INT S_STRUC S_ADDR},
	{"unshare", INT, S_INT},
	{"set_robust_list", LONG, S_STRUC S_SIZE_T},
	{"get_robust_list", LONG, S_INT S_ADDR S_ADDR},
	{"splice", INT, S_INT S_ADDR S_INT S_ADDR S_SIZE_T S_SIZE_T},
	{"tee", INT, S_INT S_INT S_SIZE_T S_SIZE_T},
	{"sync_file_range", INT, S_INT S_SIZE_T S_SIZE_T S_SIZE_T},
	{"vmsplice", INT, S_INT S_STRUC S_USI_L S_SIZE_T},
	{"move_pages", LONG, S_INT S_LONG S_ADDR S_ADDR S_ADDR S_INT},
	{"utimensat", INT, S_INT S_STR S_STRUC S_INT},
	{"epoll_pwait", INT, S_INT S_STRUC S_INT S_INT S_ADDR},
	{"signalfd", INT, S_INT S_ADDR S_INT},
	{"timerfd_create", INT, S_INT S_INT},
	{"eventfd", INT, S_SIZE_T S_INT},
	{"fallocate", INT, S_INT S_INT S_INT S_INT},
	{"timerfd_settime", INT, S_INT S_INT S_STRUC S_STRUC},
	{"timerfd_gettime", INT, S_INT S_STRUC},
	{"accept4", INT, S_INT S_STRUC S_ADDR S_INT},
	{"signalfd4", INT, S_INT S_ADDR S_INT},
	{"eventfd2", INT, S_SIZE_T S_INT},
	{"epoll_create1", INT, S_INT},
	{"dup3", INT, S_INT S_INT S_INT},
	{"pipe2", INT, S_INT_2 S_INT},
	{"inotify_init1", INT, S_INT},
	{"preadv", INT, S_INT S_STRUC S_INT S_INT},
	{"pwritev", INT, S_INT S_STRUC S_INT S_INT},
	{"rt_tgsigqueueinfo", INT, S_INT S_INT S_INT S_ADDR},
	{"perf_event_open", INT, S_STRUC S_INT S_INT S_INT S_USI_L},
	{"recvmmsg", INT, S_INT S_STRUC S_INT},
	{"fanotify_init", INT, S_SIZE_T S_SIZE_T},
	{"fanotify_mark", INT, S_INT S_SIZE_T S_SIZE_T S_INT S_STR},
	{"prlimit64", INT, S_INT S_INT S_STRUC S_STRUC},
	{"name_to_handle_at", INT, S_INT S_STR S_STRUC S_ADDR S_INT},
	{"open_by_handle_at", INT, S_INT S_STRUC S_INT},
	{"clock_adjtime", UNKN, ""},
	{"syncfs", INT, S_INT},
	{"sendmmsg", INT, S_INT S_STRUC S_INT},
	{"setns", INT, S_INT S_INT},
	{"getcpu", INT, S_ADDR S_ADDR S_STRUC},
	{"process_vm_readv", INT, S_INT S_STRUC S_USI_L S_STRUC S_USI_L S_USI_L},
	{"process_vm_writev", INT, S_INT S_STRUC S_USI_L S_STRUC S_USI_L S_USI_L},
	{"kcmp", INT, S_INT S_INT S_INT S_USI_L S_USI_L},
	{"finit_module", INT, S_INT S_STR S_INT},
	{"sched_setattr", INT, S_INT S_STRUC S_USI_L},
	{"sched_getattr", INT, S_INT S_STRUC S_USI_L S_USI_L},
	{"renameat2", INT, S_INT S_STR S_INT S_STR S_SIZE_T},
	{"seccomp", INT, S_SIZE_T S_SIZE_T S_ADDR},
	{"getrandom", INT, S_ADDR S_SIZE_T S_SIZE_T},
	{"memfd_create", INT, S_STR S_SIZE_T},
	{"kexec_file_load", LONG, S_INT S_INT S_SIZE_T S_STR S_SIZE_T},
	{"bpf", INT, S_INT S_ADDR S_SIZE_T},
	{"execveat", INT, S_INT S_STR S_STRSTR S_STRSTR S_INT},
	{"userfaultfd", UNKN, ""},
	{"membarrier", INT, S_INT S_INT},
	{"mlock2", INT, S_STR S_SIZE_T S_INT},
	{"", UNKN, ""}
};

#endif /* !SYSCALLS_H_*/
