*This project has been created as part of the 42 curriculum by mgiraldi*

Description:

	get_next_line is a C function designed to read a single line from a given file descriptor line by line across successive function calls. When invoked, it reads data chunks from the file descriptor into memory, parses the stream to isolate the next complete line (stopping strictly at and including the first newline character, \n), and saves any remaining characters for subsequent calls using a static state variable. Returns a newly allocated, null-terminated string containing the line read from the file descriptor, including the newline character (\n) if it was present at the end of the line, or/and returns NULL if the end of the file (EOF) has been reached and no more content is left to read, if an invalid file descriptor is supplied, or if a memory allocation or read error occurs.

Instructions:

	To run the header file in your C source use #include "get_next_line.h".
	Compile using "bash cc -Wall -Wextra -Werror -D BUFFER_SIZE=n *.c *.h".

Resources:
  * **Testing:** 
    * [Francinette](https://github.com/xicodomingues/francinette)
  * **Libraries:**
	* <unistd.h>
	* <stdlib.h>