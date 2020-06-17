set history save on
file /home/user42/42/repo/tester_bvalette/test
b ft_strdup

define hook-kill
    set confirm off
end

define hook-stop
	i r
	echo \nSTACK IN HEX \n
	x/20x $rdi - 10
#	echo \nSTACK IN DECIMAL \n
#	x/30d $sp
end
