<<<<<<< HEAD
testpipe:testpipe.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f testpipe
=======
cmd.exe:mycmd.c
	gcc -o $@ $^ -g
.PHONY:clean
clean:
	rm -f cmd.exe
>>>>>>> 695c6efdc46eea363c971be538ad40aad07769af
