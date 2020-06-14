set history save on
file test
b ft_strcpy:5

define hook-kill
    set confirm off
end

define hook-stop
	x /s $rdi
	x /c $rdi
	x /s $rsi
	x /c $rsi
	c /d $rax
end
