#echo $(ls *$1 | sed -e 's/\..*$//')
#regex:
#	s/ <- substitution indicator
#	\. <- escaped dot
#	.  <- single instance
#	*  <- any number of the previous (single instance of a character)
#	$  <- end of the string
#   // <- first indicates the beginning of the second pattern, 
#		  second indicates the end of the s operator
#http://tldp.org/LDP/abs/html/x23170.html

for fil in $(ls *$1 | sed -e 's/\..*$//');do
	mv $fil$1 $fil$2
done
