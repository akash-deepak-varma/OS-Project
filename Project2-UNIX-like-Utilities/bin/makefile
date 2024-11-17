CC      = gcc
CFLAGS  = -g
RM      = rm -f


#CUSTOM_CMD_DIR = bin


CUSTOM_COMMANDS = c-cat c-grep c-mv c-wc c-cp c-ls c-rm


default: all


all: MyShell $(CUSTOM_COMMANDS)


MyShell: MyShell.c
	$(CC) $(CFLAGS) -o MyShell MyShell.c


Coustom_cat: c-cat.c
	$(CC) $(CFLAGS) -o c-cat c-cat.c

Coustom_grep:  c-grep.c
	$(CC) $(CFLAGS) -o c-grep c-grep.c

Coustom_mv:  c-mv.c
	$(CC) $(CFLAGS) -o c-mv c-mv.c

Coustom_wc:  c-wc.c
	$(CC) $(CFLAGS) -o c-wc c-wc.c

Coustom_cp:  c-cp.c
	$(CC) $(CFLAGS) -o c-cp c-cp.c

Coustom_ls:  c-ls.c
	$(CC) $(CFLAGS) -o c-ls c-ls.c

Coustom_rm:  c-rm.c
	$(CC) $(CFLAGS) -o c-rm c-rm.c

clean:
	$(RM) MyShell $(CUSTOM_COMMANDS)

veryclean:
	$(RM) *.o

.PHONY: all clean veryclean
