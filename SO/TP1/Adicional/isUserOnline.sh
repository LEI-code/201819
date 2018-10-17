if [[ $(who) == *"$1"* ]]; then 
	echo "online"
else 
	echo "offline"
fi
