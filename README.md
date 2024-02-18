<p align="center">
  <a href="">
    <img src="img/GNL.png" alt="get_next_line">
  </a>
</p>

# Table of Contents
- [Table of Contents](#table-of-contents)
- [0. Description](#0-description)
- [1. Prototype](#1-prototype)
- [2. Requirements](#2-requirements)
- [3. Project](#3-project)
# 0. Description

Write a function that returns a line read from a file descriptor.


# 1. Prototype

    
    💡 `char    get_next_line(int fd);`
  

 
# 2. Requirements
    
- Repeated calls to your **get_next_line()** function should let you read the text file pointed to by the file descriptor, **one line at a time**.
    
- Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return **NULL**.
    
- The return line should include the terminating \n character, except if the end of file was reached and does not end with \n character.


# 3. Project
    
- Compile with:

  💡 `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`

### This solution uses a total of 9 functions
  
- **get_next_line.c**
    
    ```
    void	*ft_calloc(size_t n_elements, size_t size);
    ```

    ```
    char	*ft_update_next_line(char **next_line, int position);
    ```
     ```
    char	*ft_output(char **next_line, int position, int bytes);
    ```
     ```
    char	*get_next_line(int fd);
    ```

- **get_next_line_utils.c**
    
    ```
    void	ft_free(char **s);
    ```
     ```
    int ft_strchr(char *s, int c, int flag);
    ```
     ```
    int ft_strlen(char *s);
    ```
     ```
    char	*ft_strnjoin(char *s1, char *s2, int position);
    ```
     ```
    char	*ft_strndup(char *input, int position);
    ```
    
    
- ** Bonus**
    
    The bonus code has almost no differences from the normal code. The task is to develop **get_next_line()** using only one static variable and manage multiple file descriptors at the same time.
  
    

 
