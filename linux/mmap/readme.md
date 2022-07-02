## mmap introduction

### 1. usage
The command is:
```
make
./main
```

### 2. flag
    PROT_READ
            Pages may be read.

    PROT_WRITE
            Pages may be written.

    PROT_NONE
            Pages may not be accessed.

    MAP_SHARED
            Share this mapping.  Update to the mapping are visible to
            other processes mapping the same region, and (in the case
            of file-backed mappings) are carried through to the
            underlying file. (To precisely control when updates are
            carried through to the underlying file requires the use of msync(2).)
    MAP_PRIVATE
            Create a private copy-on-write mapping.  Updates to the
            mapping are not visible to other processes mapping the
            same file, and are not carried through to the underlying
            file.  It is unspecified whether changes made to the file
            after the mmap() call are visible in the mapped region.
### 3. issues



### 4. reference
refer to [mmap doc](https://man7.org/linux/man-pages/man2/mmap.2.html).

Two other reference:
https://linuxhint.com/using_mmap_function_linux/
https://www.lemoda.net/c/mmap-example/
https://www.cnblogs.com/huxiao-tee/p/4660352.html

