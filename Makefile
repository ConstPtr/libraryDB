all: libraryDB

libraryDB: main.o book.o reader.o library.o interface.o fileManage.o function.o book.h reader.h library.h interface.h fileManage.h func.h
	g++ -o libraryDB main.o book.o reader.o library.o interface.o fileManage.o func.o

main.o: main.cpp
	g++ -c main.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

reader.o: reader.cpp reader.h
	g++ -c reader.cpp

library.o: library.cpp library.h
	g++ -c library.cpp

interface.o: interface.cpp interface.h
	g++ -c interface.cpp

fileManage.o: fileManage.cpp fileManage.h
	g++ -c fileManage.cpp

function.o: func.cpp func.h
	g++ -c func.cpp

clean:
	rm -rf *.o libraryDB