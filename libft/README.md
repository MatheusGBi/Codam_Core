*This project has been created as part of the 42 curriculum by <mgiraldi>*

Description:
	In the first part of this project the goal is to recreate multiple functions from libc, adhering to their definitions from the **man** page.
	
	The following functions were implemented:
	
	ft_isalpha, 
	ft_isdigit, 
	ft_isalnum
	ft_isascii, 
	ft_isprint
	ft_memset, 
	ft_bzero,
	ft_memcpy,
	ft_strlen,
	ft_strchr,
	ft_strrchr
	ft_strncmp,
	ft_strnstr
	ft_strdup,
	ft_strlcpy,
	ft_strlcat,
	ft_calloc,
	ft_atoi,
	ft_toupper,
	ft_tolower.
		
	In the second part the goal is to develop a set of functions that either are not included in the libc or exist in another form.
	
	The following functions were implemented:
	
	ft_substr:Allocates memory (using malloc(3)) and returns a substring from the string ’s’. The substring starts at index ’start’ and has a maximum length of ’len’.
	
	ft_strjoin: Allocates memory (using malloc(3)) and returns a new string, which is the result of concatenating ’s1’ and ’s2’.
	
	ft_strtrim: Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters from ’set’ removed from the beginning and the end.
	
	ft_split: Allocates memory (using malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.
	Each string in the returned array is allocated independently. 
	The array of pointers itself is also allocated dynamically.
	The returned array must be NULL terminated.
	
	ft_strmapi: Allocates memory (using malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
	
	ft_striteri:Applies the function f to each character of the string s, passing its index as the first argument and the character itself as the second. A new string is created (using malloc(3)) to store the results from the successive applications of f.
	
	ft_itoa: Applies the function ’f’ to each character of the string passed as argument, passing its index as the first argument. Each character is passed by address to ’f’ so it can be modified if necessary.
	
	ft_putchar_fd: Outputs the character ’c’ to the specified file descriptor.
	
	ft_putstr_fd: Outputs the string ’s’ to the specified file  descriptor.
	
	ft_putendl_fd: Outputs the string ’s’ to the specified file descriptor followed by a newline.
	
	ft_putnbr_fd: Outputs the integer ’n’ to the specified file descriptor.
	
	
	In the third part of this project the goal is to develop a set of functions using a structure to manipulate linked lists using the t_list structure.
	
	typedef struct s_list
	{
    	void            *content;
    	struct s_list   *next;
	}   t_list;
	
	The following functions were implemented:	
	
	ft_lstnew - Allocates and initializes a new list node.

	ft_lstadd_front - Adds a node at the beginning of the list.

	ft_lstadd_back - Adds a node at the end of the list.
	
	ft_lstsize - Counts the number of nodes in a list.

	ft_lstlast - Returns the last node of the list.

	ft_lstdelone - Frees the content and node container of a single node.

	ft_lstclear - Deletes and frees an entire list from a given node onward.

	ft_lstiter - Iterates over a list and applies a function to each node's content.

	ft_lstmap - Creates a new list resulting from applying a function to each node's content with allocation failure recovery.

Instructions:
	Run make to compile the functions into libft.a. Make also can be ran with *make clean* to remove the .o files, *make fclean* to remove .o files and libft.a and *make re* which performs *fclean* followed by *make*.
	To run the header file in your C source use #include "libft.h".
	Compile using "bash cc -Wall -Wextra -Werror main.c libft.a".

Resources:
  * **Manuals:** Linux `man` pages (`man 3`)
  * **Testing:** 
    * [Francinette](https://github.com/xicodomingues/francinette)
