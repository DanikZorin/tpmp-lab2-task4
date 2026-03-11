bin/main: obj/main.o obj/write.o
	gcc obj/main.o obj/write.o -o bin/main

obj/main.o: src/main.c
	gcc -c src/main.c -o obj/main.o 

obj/write.o: src/write.c
	gcc -c src/write.c -o obj/write.o


clean:
	rm -f obj/* bin/*

run: bin/main
	./bin/main
