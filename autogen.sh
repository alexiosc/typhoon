#!/bin/sh
#
# $Id: autogen.sh,v 1.1 2003/08/12 16:06:54 alexios Exp $
#
# $Log: autogen.sh,v $
# Revision 1.1  2003/08/12 16:06:54  alexios
# Initial revision.
#

# Partially (and shamelessly) stolen from XMMS

libtoolize

(automake --version) < /dev/null > /dev/null 2>&1 || {
	echo;
	echo "You must have automake installed";
	echo;
	exit;
}

(autoconf --version) < /dev/null > /dev/null 2>&1 || {
	echo;
	echo "You must have autoconf installed";
	echo;
	exit;
}

echo "Generating configuration files, please wait...."
echo;

aclocal $ACLOCAL_FLAGS;
autoheader;
automake --add-missing;
autoconf;

./typhoon-configure

./configure $@

# End of file.