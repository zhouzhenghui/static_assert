ACLOCAL_AMFLAGS = -I m4

SUBDIRS = src tests

EXTRA_DIST=\
 AUTHORS   \
 ChangeLog \
 COPYING   \
 INSTALL   \
 NEWS      \
 README    \
 README.md \
 SPONSOR   \
 autogen.sh \
 Doxyfile.in \
 doc/html \
 m4

BUILT_SOURCES = $(DX_CONFIG)

edit = sed -e 's/@\([A-Za-z_\-]*\)@/$$(\1)/g'

$(DX_CONFIG): Doxyfile.in Doxyfile
	if test -f $@; then chmod u+w $@; fi
	$(edit) $< > $@
	chmod g-w,u-w $@

docs: $(DOCDIR)/$(PACKAGE).tag

#distclean-local:

@DX_RULES@
MOSTLYCLEANFILES = $(DX_CLEANFILES) $(BUILT_SOURCES)
