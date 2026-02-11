Bin=process_bar
Cc=gcc
Src=$(wildcard *.c)
Obj=$(Src:.c=.o)

$(Bin):$(Obj)
	@echo "$^ link to $@"
	@$(Cc) -o $@ $^
%.o:%.c
	@echo "compling $< to $@"
	@$(Cc) -c $<

.PHONY:clean
clean:
	@echo "Clean Project ... Done"
	@rm -f $(Obj) $(Bin)

.PHONY:Print
Print:
	@echo $(Bin)
	@echo $(Cc)
	@echo $(Src)
	@echo $(Obj)

