set history save on
file test
b ft_strcmp
define hook-stop
	x /s $rdi
	x /c $rdi
	x /s $rsi
	x /c $rsi
	print $eflags
end
