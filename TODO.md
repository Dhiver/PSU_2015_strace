# Strace

- [ ] How to handle a segfaulting program ? (Florian)
	- [ ] Remove current infinite wait
- [ ] Improve global speed (as the real strace) (Florian)
- [/] -p (Bastien)
	- [ ] Do not exit when detach
	- [ ] Do not freez the attached program
- [/] -s (Bastien)
- [ ] Fix first execve arguments (Bastien)
	- [ ] Look for the executable absolute path ('ls' -> '/bin/ls') like for minishell (Bastien)
