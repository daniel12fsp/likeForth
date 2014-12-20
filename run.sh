#!/bin/bash

rm *.java
java -jar ../Coco.jar -frames .. forth2c_final_attr.atg
javac *.class
java Compile teste.txt > teste.c
