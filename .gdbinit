set history save on
file test
b ft_strcpy:5

define hook-kill
    set confirm off
end

define hook-stop
	echo \nSTACK IN HEX \n
	x/100x $sp
	echo \nSTACK IN DECIMAL \n
	x/30d $sp
end
