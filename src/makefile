app:		main.o fileHandler.o
			g++ *.o -o ../app

main.o:		main.cpp fileHandler.h
			g++ -c main.cpp

Session.o: 	fileHandler.cpp fileHandler.h
			g++ -c fileHandler.cpp

clean:	
		rm -f *.o

mrproper: clean
		rm -f app.exe