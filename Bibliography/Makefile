# polynomial project

# compilatore
CC = g++
# flag per il compilatore
CFLAGS = -std=c++11 -pedantic -Wall
# lista delle dipendenze: i file .h contengono i nomi delle funzioni
DEPS = QuickSort.h Publication.h ConferenceArticle.h Book.h PaperArticle.h
# file oggetto
OBJS = Publication.o ConferenceArticle.o Book.o PaperArticle.o main.o

# ricetta per ogni file .o: serve il file .cpp con lo stesso nome, più le dipendenze
# il comando può essere tradotto come segue:
# g++ -c -o main.o main.cpp Polynomials.h -std=c++11 -pedantic -Wall
%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

# ricetta per l'eseguibile: servono tutti i file oggetto
main: ${OBJS}
	${CC} -o $@ $^ ${CFLAGS}