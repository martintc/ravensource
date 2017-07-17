#!/bin/sh
#
# The purpose of this script is to catch FPC_EQUIVALENT values of "N/A"
# that are not on a whitelist.  This usually means they were forgotten
# to be defined.

location=/usr/raven
tmpfile=/tmp/fpc.notlist
PROG='{if ($3 == "N/A") print}'
awk "${PROG}" ${location}/Mk/Misc/fpc_equivalents > ${tmpfile}

echo "List of ports with undefined FPC_EQUIVALENT values:"
while read ravenport version fpc_port; do
   case "${ravenport}" in
	libbsd) ;; 		# linux only
	libusb) ;; 		# linux only
	shadow) ;;		# linux only

	ravenports) ;;		# unique to ravenports
	libdl) ;;		# unique to ravenports
	ravensys-root) ;;	# unique to ravenports
	ravensys-toolchain) ;;	# unique to ravenports
	ravensys-uname) ;;	# unique to ravenports
	bmake-mk-files) ;;	# unique to ravenports
	ravenadm) ;;		# unique to ravenports

	xz) ;;			# deleted from FPC
	zlib) ;;		# deleted from FPC

	fetch) ;;		# From DragonFly
	makewhatis) ;;		# From DragonFly
	mtree) ;;		# From DragonFly
	rpcgen) ;;		# From DragonFly
	sha256) ;;		# From DragonFly

	libedit) ;;		# Different version scheme from FPC
	gnat-util) ;;		# Different version scheme from FPC
	gcc[678]) ;;		# Different version scheme from FPC
	gprbuild) ;;		# Different version scheme from FPC

	libexecinfo) ;;		# Different source from FPC

	libadalang) ;;		# Rest are ports that FPC doesn't have yet
	libtickit) ;;
	libmpack) ;;
	lua-mpack) ;;
	quex) ;;
	slider) ;;
	*) echo "${ravenport} ${version}"
   esac
done < ${tmpfile}

rm -f ${tmpfile}
