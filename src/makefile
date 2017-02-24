app:		main.o functions.o fileHandler.o
			g++ *.o -o ../app -l comdlg32 -fpermissive

main.o:		main.cpp functions.cpp fileHandler.cpp
			g++ -c main.cpp -fpermissive

functions.o: functions.cpp fileHandler.cpp
			g++ -c functions.cpp -l comdlg32 -fpermissive

fileHandler.o: fileHandler.cpp
			g++ -c fileHandler.cpp -fpermissive

clean:	
		rm -f *.o

mrproper: clean
		rm -f app.exe