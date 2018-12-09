#!/bin/bash

for f in `ls /bin`
do
	./otool '/bin/'$f > fichier
	otool -t '/bin/'$f > fichier2
	x=$(diff fichier fichier2)
	if [ "$x" != "" ]
	then
		echo $f
	fi
done
