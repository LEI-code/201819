result=1
for i in $(seq $1);
do
	#Similar to the let command, the (( ... )) construct permits arithmetic expansion and evaluation.
	#http://tldp.org/LDP/abs/html/dblparens.html
	result=$(($result * $i))
done
echo $result