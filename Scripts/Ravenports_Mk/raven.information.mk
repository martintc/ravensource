# RESERVED_WARNING
# This file is not directly used by the Raven framework.
# It's sole purpose is to provide definitions that multiple specifications
# need in a single location.  The data is extracted by using the
# EXTRACT_INFO function on a specification definition, e.g.
#
# DEF[PORTVERSION]=		EXTRACT_INFO(GCC11_VERSION)
# 
# This file is only used at "compile-time", that is when the port
# specification is used to generate the buildsheet.

# ------------------------------------------------------------------------
# APQ
# ------------------------------------------------------------------------

APQ_VERSION=			3.2.0
APQ_BASE_REVISION=		1
APQ_PGSQL_REVISION=		1
APQ_ODBC_REVISION=		1

# ------------------------------------------------------------------------
# boost
# ------------------------------------------------------------------------

BOOST_VERSION=			1.83.0
BOOST_JAM_REVISION=		0
BOOST_LIBRARIES_REVISION=	0

# ------------------------------------------------------------------------
# Only keep the open branches of GCC
# ------------------------------------------------------------------------
# ------------------------------------------------------------------------
# gcc11
# ------------------------------------------------------------------------

GCC11_BRANCH=			11
GCC11_POINT=			4.0
GCC11_VERSION=			${GCC11_BRANCH}.${GCC11_POINT}
GCC11_SNAPSHOT=			20230529
GCC11_BUILD_RELEASE=		yes
GCC11_REVISION=			0
GCC11_GNATCROSS_REVISION=	0
GCC11_BOOTSTRAP_REVISION=	0

.if ${GCC11_BUILD_RELEASE:Mno}
GCC11_PORTVERSION=		${GCC11_BRANCH}.${GCC11_SNAPSHOT}
GCC11_IDENTIFICATION=		gcc-${GCC11_BRANCH}-${GCC11_SNAPSHOT}
GCC11_MS_SUBDIR=		snapshots/${GCC11_BRANCH}-${GCC11_SNAPSHOT}
GCC11_PHASE=			snapshot
.else
GCC11_PORTVERSION=		${GCC11_VERSION}
GCC11_IDENTIFICATION=		gcc-${GCC11_VERSION}
GCC11_MS_SUBDIR=		releases/gcc-${GCC11_VERSION}
GCC11_PHASE=			release
.endif

# ------------------------------------------------------------------------
# gcc12
# ------------------------------------------------------------------------

GCC12_BRANCH=			12
GCC12_POINT=			3.0
GCC12_VERSION=			${GCC12_BRANCH}.${GCC12_POINT}
GCC12_SNAPSHOT=			20230508
GCC12_BUILD_RELEASE=		yes
GCC12_REVISION=			1
GCC12_GNATCROSS_REVISION=	0
GCC12_BOOTSTRAP_REVISION=	0

.if ${GCC12_BUILD_RELEASE:Mno}
GCC12_PORTVERSION=		${GCC12_BRANCH}.${GCC12_SNAPSHOT}
GCC12_IDENTIFICATION=		gcc-${GCC12_BRANCH}-${GCC12_SNAPSHOT}
GCC12_MS_SUBDIR=		snapshots/${GCC12_BRANCH}-${GCC12_SNAPSHOT}
GCC12_PHASE=			snapshot
.else
GCC12_PORTVERSION=		${GCC12_VERSION}
GCC12_IDENTIFICATION=		gcc-${GCC12_VERSION}
GCC12_MS_SUBDIR=		releases/gcc-${GCC12_VERSION}
GCC12_PHASE=			release
.endif

# ------------------------------------------------------------------------
# gcc13
# ------------------------------------------------------------------------

GCC13_BRANCH=			13
GCC13_POINT=			2.0
GCC13_VERSION=			${GCC13_BRANCH}.${GCC13_POINT}
GCC13_SNAPSHOT=			20230727
GCC13_BUILD_RELEASE=		yes
GCC13_REVISION=			1
GCC13_GNATCROSS_REVISION=	0
GCC13_BOOTSTRAP_REVISION=	0

.if ${GCC13_BUILD_RELEASE:Mno}
GCC13_PORTVERSION=		${GCC13_BRANCH}.${GCC13_SNAPSHOT}
GCC13_IDENTIFICATION=		gcc-${GCC13_BRANCH}-${GCC13_SNAPSHOT}
GCC13_MS_SUBDIR=		snapshots/${GCC13_BRANCH}-${GCC13_SNAPSHOT}
GCC13_PHASE=			snapshot
.else
GCC13_PORTVERSION=		${GCC13_VERSION}
GCC13_IDENTIFICATION=		gcc-${GCC13_VERSION}
GCC13_MS_SUBDIR=		releases/gcc-${GCC13_VERSION}
GCC13_PHASE=			release
.endif

# ------------------------------------------------------------------------
# Ravenports base compiler
# ------------------------------------------------------------------------

GCCBASE_BRANCH=			13
GCCBASE_POINT=			2.0
GCCBASE_VERSION=		${GCCBASE_BRANCH}.${GCCBASE_POINT}
GCCBASE_REVISION=		0
GCCBASE_PORTVERSION=		${GCCBASE_VERSION}
GCCBASE_IDENTIFICATION=		gcc-${GCCBASE_VERSION}
GCCBASE_MS_SUBDIR=		releases/gcc-${GCCBASE_VERSION}
GCCBASE_PHASE=			release

# ------------------------------------------------------------------------
# icu
# ------------------------------------------------------------------------

ICU_VERSION=			73.2
ICU_REVISION=			1
ICU_LX_REVISION=		0

# ------------------------------------------------------------------------
# libxml2
# ------------------------------------------------------------------------

LIBXML2_VERSION=		2.11.5
LIBXML2_REVISION=		0
LIBXML2_PYTHON_REVISION=	0

# ------------------------------------------------------------------------
# libxslt
# ------------------------------------------------------------------------

LIBXSLT_VERSION=		1.1.38
LIBXSLT_REVISION=		0
LIBXSLT_PYTHON_REVISION=	0

# ------------------------------------------------------------------------
# ruby
# ------------------------------------------------------------------------

RUBY_2.7_REVISION=		0
RUBY_2.7_PATCHLEVEL=		0

RUBY_3.0_REVISION=		0
RUBY_3.0_PATCHLEVEL=		0

RUBY_3.1_REVISION=		0
RUBY_3.1_PATCHLEVEL=		0

RUBY_3.2_REVISION=		0
RUBY_3.2_PATCHLEVEL=		0

# ------------------------------------------------------------------------
# gnome
# ------------------------------------------------------------------------

GTK2_VERSION=			2.10.0
GTK3_VERSION=			3.0.0
GTK4_VERSION=			4.0.0
GTK2_PORT_VERSION=		2.24.33
GTK3_PORT_VERSION=		3.24.38
GTK4_PORT_VERSION=		4.12.1

# ------------------------------------------------------------------------
# Ravenports binutils
# ------------------------------------------------------------------------

BINUTILS_VERSION=		2.41
RPBASE_BINUTILS=		2.41

# ------------------------------------------------------------------------
# aspell
# ------------------------------------------------------------------------

ASPELL_CORE_VERSION=		0.60.8
ASPELL_INSTALL_VERSION=		${ASPELL_CORE_VERSION:R}

# ------------------------------------------------------------------------
# apr1 and other apache projects
# ------------------------------------------------------------------------

APR1_VERSION=			1.7.4
APR1_UTIL_VERSION=		1.6.3
SUBVERSION_VERSION=		1.14.2

# ------------------------------------------------------------------------
# Miscellaneous master versions
# ------------------------------------------------------------------------

LIBFM_VERSION=			1.3.2
LIBTOOL_VERSION=		2.4.7
FREI0R_VERSION=			1.8.0
M17N_VERSION=			1.8.4
GLIBC_VERSION=			2.26
GSTREAMER1_VERSION=		1.22.5		# only even (1.16.x, 1.18.x)
GSTREAMER1_GST=			1.0
GSTREAMER1_SOVERSION=		0.2205.0
XORG_VERSION=			7.7
LLVM_VERSION=			16.0.6
ZLIB_VERSION=			1.3
GHOSTSCRIPT_VERSION=		10.01.2
SPHINX_UNDERSCORE=		1.13.1
ANCIENT_UNDERSCORE=		1.3.1
LATEST_JQUERY=			3.6.0
PECL_YAML=			2.2.3

# ------------------------------------------------------------------------
# Gnatcross options
# ------------------------------------------------------------------------

GNATCROSS_FREEBSD_11=		11.3
GNATCROSS_FREEBSD_12=		12.2
GNATCROSS_MIDNIGHTBSD_3=	12.3
GNATCROSS_NETBSD_9=		9.2
MIDNIGHT64_CC_TARGET=		x86_64-raven-freebsd12.3
MIDNIGHT32_CC_TARGET=		i386-raven-freebsd12.3

# ------------------------------------------------------------------------
# Qt and Qt-based desktops
# ------------------------------------------------------------------------

QT5_VERSION=			5.15.6
QT6_VERSION=			6.5.2
LUMINA_VERSION=			1.6.2
LUMINA_RELEASE_TAG=		1.6.2
KDE_FRAMEWORKS_VERSION=		5.109.0
