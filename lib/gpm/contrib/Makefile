# Generated automatically from Makefile.in by configure.
#        -*-makefile-*- (gpm/contrib)
#
# Copyright (C) 2001 Nico Schottelius <nico@schottelius.org>
#


srcdir = /home/user/nico/computer/sources/linux/gpm/cvstree/contrib
top_builddir = ..

include $(top_builddir)/Makefile.include

all: $(srcdir)/$(ELISP)

install: all
	if [ -n "$(ELISP)" ]; then for i in `echo $(ELISP)`; do \
		$(INSTALL_DATA) $(srcdir)/$$i $(lispdir)/`basename $$i` ;\
	done; fi

%.elc: %.el
	$(EMACS) -batch -l $(srcdir)/emacs/exec.el -exec '(byte-compile-file "$<")'

uninstall:
	if [ -n "$(ELISP)" ]; then for i in `echo $(ELISP)`; do \
		rm -f $(lispdir)/$$i ;\
	done; fi 

dist:
	$(CP) -r $(srcdir) $(top_builddir)/gpm-$(release)/

clean distclean:
	$(RM) -f $(srcdir)/emacs/*.elc
