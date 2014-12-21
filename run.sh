#!/bin/bash

rm *.java
java -jar ../Coco.jar -frames .. forth2c_final_attr.atg
javac *.java
java Compile blackjack.lf
gcc codigo_convertido.c -o codigo_convertido -lm
./codigo_convertido
