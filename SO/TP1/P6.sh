if [ $(($1 % 4)) -ne 0 ];then
	echo 28
elif [ $(($1 % 100)) -ne 0 ]; then
	echo 29
elif [ $(($1 % 400)) -ne 0 ]; then
	echo 28
else
	echo 29
fi
