[École 42 - project] First approach to basics of assembly language, with intel x86_64 syntax. This project reimplement some C standard functions.

# libasm

This lib contain basic functions of the libc :

libc equivalents:

- ft_read
- ft_write
- ft_strcpy
- ft_strdup
- ft_strcmp
- ft_strlen
- ft_strchr

special functions:
|function|comment|
|:----------|:-------------|
ft_atoi_base|convert string containing number in a given base to an integet in base 10.
ft_list_push_front|add a linked-list element at the begining of a list.
ft_list_remove_if|removed a linked-list element if the function passed as argument returns is not 0
ft_list_size|returns the number of elements in a linked-list passed as argument

