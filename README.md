*This project has been created as part of the 42 curriculum by cebouhad*

# 🔎 Description

The get_next_line project aims to build the get_next_line function, which allows reading a stream pointed to by a file descriptor line by line.

The function adapts to different buffer sizes and file descriptors (open files, tty). The implementation can utilize either dynamic or static buffer allocation; however, in the latter case, careful attention must be paid to the stack frame size. As mentioned in the subject, allocating a buffer with a size of 10,000,000 can lead to stack overflow issues.

Buffers of size 1 must also be managed without "cheating" the allocation (e.g., BUFFER_SIZE + 1 is strictly forbidden!).

Finally, this project introduces the concept of static variables, as they allow storing the remainder of a line (the "stash") for the subsequent call to get_next_line.

# 📋 Instructions

The get_next_line function takes a file descriptor as a parameter. The maximum number of file descriptors referenced is the soft limit defined in /proc/$(process pid)/limits (Max open files).

```C

char *get_next_line(int fd);

```

# 📖 Ressources

    man open
    man read
    42born2code.slack.com
    https://en.wikipedia.org/wiki/File_descriptor
    https://lldb.llvm.org/use/map.html
    https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/
    https://stackoverflow.com
    gemini for README translation help
    
    

# 🛠️ Detailed Description

After initializing the t_gnl structure and verifying that the file descriptor is neither negative nor exceeds the limits, the get_next_line function is divided into three main processes.
## ⚙️ Processing the "Stash" from the Previous Call:

    Case 1:
    The stash does not contain a newline character (\n). In this case, the stash is joined to the line, the dynamic allocation for the stash is freed, the pointer is set to NULL, and the process_stash() function returns the READ code. get_next_line then enters read mode.

    Case 2:
    The stash contains a newline character. The stash is joined to the line from index 0 up to the \n character. If characters exist after the newline, they form the new stash (ensuring the previous stash's memory is freed). Otherwise, the memory is freed and the pointer is set to NULL. The buffer memory is also freed. Finally, the NOREAD code is returned by process_stash(), and get_next_line returns the completed line.

## ▶️ Reading the File:

The file is read using the read system call, which takes the file descriptor, the buffer, and the number of bytes to read. To handle buffers of size 1, a null-terminator (\0) is not added to the end of the buffer. Consequently, the utility functions for buffer processing do not rely on \0 as a reference, but rather on the return value of the read function (number of bytes read).

## ⚙️ Buffer Processing:

    Case 1: The buffer does not contain a newline. The buffer is simply appended to the line via the ft_strjoin_gnl() function.

    Case 2: The buffer contains a newline. The buffer is split into two parts:

        The first part (index 0 to \n) is joined to the current line.

        The second part (from \n + 1 to the last byte of the buffer) becomes the stash for the next call.
        The process_buffer() function returns NOREAD, the buffer allocation is freed, and get_next_line returns the line.

# 🚨 Error Handling:

All dynamic allocations and functions involving memory allocation are verified and return an ERR code if an issue occurs. If ERR is triggered, a call to clean_data() ensures that all dynamic allocations are freed based on the current progress within the function's execution flow.