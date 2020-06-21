shell touch /tmp/gdboutput
shell touch /tmp/gdboutput_old
shell touch /tmp/gdboutput_new
shell touch /tmp/diff
set history save on
set logging file /tmp/gdboutput
#set logging overwrite on
set logging on
show logging

file /home/user42/42/repo/tester_bvalette/test
display /s $rdi
display /s $rsi
display /d $rax
display /d $rcx

b ft_atoi_base.s:28

define x_c
    set var $repeatCount=$rbp - $rsp + 8 
    eval "x/-32xc $rsp"
	echo ______________________________________________ STACK FRAME START\n 
    eval "x/%dxc $rsp", $repeatCount 
	echo ______________________________________________ STACK FRAME END\n 
    eval "x/32xc $rbp"
end
define x_b
    set var $repeatCount=$rbp - $rsp + 8 
    eval "x/-32xb $rsp"
	echo ______________________________________________ STACK FRAME START\n 
    eval "x/%dxb $rsp", $repeatCount 
	echo ______________________________________________ STACK FRAME END\n 
    eval "x/32xb $rbp"
end

define x_d
    set var $repeatCount=$rbp - $rsp + 8 
    set var $repeatCount=$repeatCount / 8
    eval "x/-16d $rsp"
	echo ______________________________________________ STACK FRAME START\n 
    eval "x/%dd $rsp", $repeatCount 
	echo ______________________________________________ STACK FRAME END\n 
    eval "x/16d $rbp"
end

define x_s
    set var $repeatCount=$rbp - $rsp + 8 
    set var $repeatCount=$repeatCount / 8
    eval "x/-16s $rsp"
	echo ______________________________________________ STACK FRAME START\n 
    eval "x/%ds $rsp", $repeatCount 
	echo ______________________________________________ STACK FRAME END\n 
    eval "x/16s $rbp"
end

define xcmd_iterative
    set var $repeatCount=$rbp - $rsp + 8 
    set var $repeatCount=$repeatCount / 8
    eval "x/-16xg $rsp"
	echo ______________________________________________ STACK FRAME START\n 
    eval "x/%dxg $rsp", $repeatCount 
	echo ______________________________________________ STACK FRAME END\n 
    eval "x/16xg $rbp"
end

define hook-kill
    set confirm off
end

define clean
	shell clear
	kill
	source .gdbinit
	shell true > /tmp/diff
	shell true > /tmp/gdboutput
	shell true > /tmp/gdboutput_new
end

define myFun_stop
	shell true > /tmp/gdboutput_new
	i r
	display
	printf "\nSTACK base  => %#lx\n", $rbp  
	printf "STACK point => %#lx\n", $rsp
	printf "STACK range => %#d\n", $rbp - $rsp
	printf "\nSTACK IN HEX from rsp\n"
	xcmd_iterative 
	if $argc == 0
		shell true > /tmp/gdboutput
	end
end

define hook-stop
	printf "\n\n\n"
	myFun_stop log
	shell sed 's/\x0//g' /tmp/gdboutput > /tmp/gdboutput_new
	shell diff --color -y --text /tmp/gdboutput_old /tmp/gdboutput_new > /tmp/diff
	shell cat /tmp/gdboutput_new > /tmp/gdboutput_old
	shell true > /tmp/gdboutput
end
