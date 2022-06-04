# Linux namespace

## reference link:
https://www.toptal.com/linux/separation-anxiety-isolating-your-system-with-linux-namespaces
## pid namespace

1. Stacks grow downward on all
    processors that run Linux (except the HP PA processors), so stack
    usually points to the topmost address of the memory space set up
    for the child stack.

2. refer to this link for the reason [why providing stack pointer is needed](https://stackoverflow.com/questions/10597104/child-stack-explaination-in-clone-system-call)

3. usage: 
```
make
sudo ./pid 10
```

Note: `sudo` is mandatory!

4. Notice that the PID of the child is 1, because we add `CLONE_NEWPID` flag.