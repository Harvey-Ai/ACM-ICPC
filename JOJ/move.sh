/* author: hongwei Ai
 * it is used to extract the text files from vc project.
 * it is wonderful that i save about 200M storage.
 * 2010-4-05
 */



#!/bin/bash

for problem in ./*
do
	if [ -d "$problem" ]
	then
		cd "$problem"
		echo "in $problem"
		if [ -e 1.cpp ]
		then
			mv 1.cpp "../joj/$problem.cpp"
		else
			echo "$problem.1.cpp not found"
		fi
		echo "$problem success"
		cd ..
	fi
done

