#!/bin/bash

for f in `ls /bin`
do
	./nm '/bin/'$f > fichier
	nm '/bin/'$f > fichier2
	x=$(diff fichier fichier2)
	if [ "$x" != "" ]
	then
		echo $f
	fi
done
