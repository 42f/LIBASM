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
b ft_atoi_base

define hook-kill
    set confirm off
end

define hook-stop
	i r
	echo \nSTACK IN HEX from rsp\n
	x/32x $rsp
	info line
	echo NEXT\n
	shell sed 's/\x0//g' /tmp/gdboutput > /tmp/gdboutput_new
	shell diff --color -y --text /tmp/gdboutput_old /tmp/gdboutput_new > /tmp/diff
	shell cat /tmp/gdboutput_new > /tmp/gdboutput_old
	shell true > /tmp/gdboutput
end
