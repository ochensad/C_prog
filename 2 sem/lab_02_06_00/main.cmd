@ECHO OFF
CHCP 65001
CALL compil.cmd
FOR /L %%B IN (1,1,10) DO (
	datagen.py 10 >data10_10.txt
	datagen.py 2000 >data2000_10.txt
	datagen.py 4000 >data4000_10.txt
	datagen.py 7000 >data7000_10.txt
	datagen.py 10000 >data10000_10.txt
	app_01.exe <data10_10.txt >>time10_10_01.txt
	app_01.exe <data2000_10.txt >>time10_2000_01.txt
	app_01.exe <data4000_10.txt >>time10_4000_01.txt
	app_01.exe <data7000_10.txt >>time10_7000_01.txt
	app_01.exe <data10000_10.txt >>time10_10000_01.txt
	)
FOR /L %%B IN (1,1,500) DO (
	datagen.py 10 >data10_100.txt
	datagen.py 2000 >data2000_100.txt
	datagen.py 4000 >data4000_100.txt
	datagen.py 7000 >data7000_100.txt
	datagen.py 10000 >data10000_100.txt
	app_01.exe <data10_100.txt >>time100_10_01.txt
	app_01.exe <data2000_100.txt >>time100_2000_01.txt
	app_01.exe <data4000_100.txt >>time100_4000_01.txt
	app_01.exe <data7000_100.txt >>time100_7000_01.txt
	app_01.exe <data10000_100.txt >>time100_10000_01.txt
	)

del data*.txt
avg.py 10 <time10_10_01.txt >>avg10_01.txt
avg.py 2000 <time10_2000_01.txt >>avg10_01.txt
avg.py 4000 <time10_4000_01.txt >>avg10_01.txt
avg.py 7000 <time10_7000_01.txt >>avg10_01.txt
avg.py 10000 <time10_10000_01.txt >>avg10_01.txt

avg.py 10 <time100_10_01.txt >>avg100_01.txt
avg.py 2000 <time100_2000_01.txt >>avg100_01.txt
avg.py 4000 <time100_4000_01.txt >>avg100_01.txt
avg.py 7000 <time100_7000_01.txt >>avg100_01.txt
avg.py 10000 <time100_10000_01.txt >>avg100_01.txt

del time1*.txt

FOR /L %%B IN (1,1,10) DO (
	datagen.py 10 >data10_10.txt
	datagen.py 2000 >data2000_10.txt
	datagen.py 4000 >data4000_10.txt
	datagen.py 7000 >data7000_10.txt
	datagen.py 10000 >data10000_10.txt
	app_02.exe <data10_10.txt >>time10_10_02.txt
	app_02.exe <data2000_10.txt >>time10_2000_02.txt
	app_02.exe <data4000_10.txt >>time10_4000_02.txt
	app_02.exe <data7000_10.txt >>time10_7000_02.txt
	app_02.exe <data10000_10.txt >>time10_10000_02.txt
	)
FOR /L %%B IN (1,1,500) DO (
	datagen.py 10 >data10_100.txt
	datagen.py 2000 >data2000_100.txt
	datagen.py 4000 >data4000_100.txt
	datagen.py 7000 >data7000_100.txt
	datagen.py 10000 >data10000_100.txt
	app_02.exe <data10_100.txt >>time100_10_02.txt
	app_02.exe <data2000_100.txt >>time100_2000_02.txt
	app_02.exe <data4000_100.txt >>time100_4000_02.txt
	app_02.exe <data7000_100.txt >>time100_7000_02.txt
	app_02.exe <data10000_100.txt >>time100_10000_02.txt
	)

del data*.txt
avg.py 10 <time10_10_02.txt >>avg10_02.txt
avg.py 2000 <time10_2000_02.txt >>avg10_02.txt
avg.py 4000 <time10_4000_02.txt >>avg10_02.txt
avg.py 7000 <time10_7000_02.txt >>avg10_02.txt
avg.py 10000 <time10_10000_02.txt >>avg10_02.txt

avg.py 10 <time100_10_02.txt >>avg100_02.txt
avg.py 2000 <time100_2000_02.txt >>avg100_02.txt
avg.py 4000 <time100_4000_02.txt >>avg100_02.txt
avg.py 7000 <time100_7000_02.txt >>avg100_02.txt
avg.py 10000 <time100_10000_02.txt >>avg100_02.txt

del time1*.txt

FOR /L %%B IN (1,1,10) DO (
	datagen.py 10 >data10_10.txt
	datagen.py 2000 >data2000_10.txt
	datagen.py 4000 >data4000_10.txt
	datagen.py 7000 >data7000_10.txt
	datagen.py 10000 >data10000_10.txt
	app_03.exe <data10_10.txt >>time10_10_03.txt
	app_03.exe <data2000_10.txt >>time10_2000_03.txt
	app_03.exe <data4000_10.txt >>time10_4000_03.txt
	app_03.exe <data7000_10.txt >>time10_7000_03.txt
	app_03.exe <data10000_10.txt >>time10_10000_03.txt
	)
FOR /L %%B IN (1,1,500) DO (
	datagen.py 10 >data10_100.txt
	datagen.py 2000 >data2000_100.txt
	datagen.py 4000 >data4000_100.txt
	datagen.py 7000 >data7000_100.txt
	datagen.py 10000 >data10000_100.txt
	app_03.exe <data10_100.txt >>time100_10_03.txt
	app_03.exe <data2000_100.txt >>time100_2000_03.txt
	app_03.exe <data4000_100.txt >>time100_4000_03.txt
	app_03.exe <data7000_100.txt >>time100_7000_03.txt
	app_03.exe <data10000_100.txt >>time100_10000_03.txt
	)

del data*.txt
avg.py 10 <time10_10_03.txt >>avg10_03.txt
avg.py 2000 <time10_2000_03.txt >>avg10_03.txt
avg.py 4000 <time10_4000_03.txt >>avg10_03.txt
avg.py 7000 <time10_7000_03.txt >>avg10_03.txt
avg.py 10000 <time10_10000_03.txt >>avg10_03.txt

avg.py 10 <time100_10_03.txt >>avg100_03.txt
avg.py 2000 <time100_2000_03.txt >>avg100_03.txt
avg.py 4000 <time100_4000_03.txt >>avg100_03.txt
avg.py 7000 <time100_7000_03.txt >>avg100_03.txt
avg.py 10000 <time100_10000_03.txt >>avg100_03.txt

del time1*.txt
