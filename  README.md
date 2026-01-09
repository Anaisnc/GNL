*This project has been created as part of the 42 curriculum by <your_login>.*

# get_next_line

## Description

The **get_next_line** project consists in implementing a C function that reads a file descriptor **line by line**, returning one line at each call.

The main challenge of this project is to correctly handle partial reads caused by the `read()` system call, while preserving unread data between function calls. The function must work with any buffer size, manage memory safely, and correctly handle end-of-file and error cases.

This project introduces important concepts such as:
- Static variables
- Buffer management
- File descriptor handling
- Dynamic memory allocation
- Robust algorithm design in C

---

## Instructions

### Compilation

Compile the project with:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c

You can define a custom buffer size at compilation:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

Usage

Include the header in your program:

#include "get_next_line.h"

Example usage:

int fd;
char *line;

fd = open("example.txt", O_RDONLY);
while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);

The function returns:
	•	A line including \n if present
	•	The last line without \n if EOF is reached
	•	NULL when there is nothing left to read or on error

⸻

Algorithm Explanation

Core idea

The read() function reads a fixed number of bytes and does not respect line boundaries.
Therefore, the algorithm accumulates data until a complete line is found.

To achieve this, a static buffer is used to store unread characters between function calls.

⸻

Main variables

The algorithm uses four main variables:
	•	buff
A temporary buffer allocated with BUFFER_SIZE + 1 bytes, used to store the result of read().
	•	static tmp
A static string that keeps unread data between calls to get_next_line.
	•	save_tmp
A temporary pointer used during concatenation to safely manage memory.
	•	line
The string returned by the function, containing exactly one line.

⸻

Step-by-step behavior
	1.	Validation
	•	If fd < 0 or BUFFER_SIZE <= 0, the function returns NULL.
	2.	Reading
	•	Data is read into buff.
	•	buff is concatenated to static tmp.
	•	This continues until a newline \n is found or EOF is reached.
	3.	Newline detection
	•	If a newline is found in tmp, the line can be extracted.
	4.	Line extraction
	•	The function allocates memory for the line.
	•	Copies characters from the beginning of tmp up to and including \n.
	•	The remaining data after \n is saved back into tmp.
	5.	End of file
	•	If EOF is reached and tmp still contains data, it is returned as the final line.
	•	If no data remains, the function returns NULL.

⸻

Memory management

Special attention is given to memory safety:
	•	Every malloc is paired with a free
	•	Freed pointers are reset to NULL
	•	The static buffer is freed at EOF
	•	No memory leaks or invalid accesses occur

This ensures robust and predictable behavior.

⸻

Resources

Technical references
	•	Linux manual pages:
	•	man read
	•	man open
	•	man close
	•	GNU C Library documentation
	•	42 Network documentation and subject PDF
	•	Tutorials on file descriptors and static variables in C

Use of AI

Artificial Intelligence was used as a learning and assistance tool for:
	•	Clarifying the project requirements
	•	Structuring the algorithm explanation

⸻

Conclusion

The get_next_line project is a foundational exercise in C programming that strengthens understanding of file I/O, memory management, and algorithmic thinking.
The implemented solution is robust, efficient, and compliant with the project requirements of the 42 curriculum.

