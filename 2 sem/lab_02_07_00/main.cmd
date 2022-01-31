@ECHO OFF
CHCP 65001
CALL compil.cmd
datagen.py 200000 >data.txt
app.exe <data.txt
gprof app.exe > report.txt