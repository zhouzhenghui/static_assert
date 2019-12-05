#!/bin/sh
set -x
aclocal -I ./m4
autoconf
automake --foreign --add-missing --copy
