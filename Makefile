
BLUE = "\033[1;34m"
RED =  "\033[1;31m"
NONE = "\033[0m"

SUBDIR := ColorPicker

.PHONY: $(SUBDIR) libxputty  recurse

$(MAKECMDGOALS) recurse: $(SUBDIR)

check-and-reinit-submodules :
	@if git submodule status 2>/dev/null | egrep -q '^[-]|^[+]' ; then \
		echo $(RED)"INFO: Need to reinitialize git submodules"$(NONE); \
		git submodule update --init; \
		echo $(BLUE)"Done"$(NONE); \
	else echo $(BLUE)"Submodule up to date"$(NONE); \
	fi

clean:

libxputty: check-and-reinit-submodules
ifneq ($(MAKECMDGOALS),debug)
	@exec $(MAKE) -j 1 -C $@ $(MAKECMDGOALS) CFLAGS='-O3 -D_FORTIFY_SOURCE=2 -Wall \
	-fstack-protector -fno-ident -fno-asynchronous-unwind-tables -s -DNDEBUG'
else
	@exec $(MAKE) -j 1 -C $@ $(MAKECMDGOALS)
endif

$(SUBDIR): libxputty
	@exec $(MAKE) -j 1 -C $@ $(MAKECMDGOALS)

