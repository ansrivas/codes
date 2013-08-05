#!bin/bash

#for i in `find . -type d -print`
for i in `ls -d */`
do
# if [ grep $i ]
   echo $i
# fi
done
