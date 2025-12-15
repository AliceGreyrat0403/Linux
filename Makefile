cmd.exe:mycmd.c
	gcc -o $@ $^ -g
.PHONY:clean
clean:
	rm -f cmd.exe
