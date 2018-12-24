#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.59])
AC_INIT([static_assert], [1.0], [zhouzhenghui@gmail.com])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/static_assert/static_assert.h])
AM_INIT_AUTOMAKE(1.10 gnu -Wall no-define)

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Doxygen options
DOCDIR="doc"
DX_DOXYGEN_FEATURE(ON)
DX_HTML_FEATURE(ON)
DX_CHM_FEATURE(OFF)
DX_CHI_FEATURE(OFF)
DX_MAN_FEATURE(OFF)
DX_RTF_FEATURE(OFF)
DX_XML_FEATURE(OFF)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN([static_assert], [doxygen.cfg], [$(DOCDIR)])
AC_SUBST(DOCDIR)

AC_CONFIG_FILES([Doxyfile Makefile src/Makefile tests/Makefile])

AC_OUTPUT
