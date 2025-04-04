# RESERVED_WARNING
# Provide default versions for ports with multiple versions selectable
# by the user.
#
# Users who want to override these defaults can easily do so by defining
# DEFAULT_VERSIONS in their make.conf as follows:
#
# DEFAULT_VERSIONS=	perl5=5.36 ruby=3.2
#

.if !defined(_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
_INCLUDE_BSD_DEFAULT_VERSIONS_MK=	yes

.  for base in LUA MYSQL PERL5 PHP PGSQL PYTHON3 RUBY SSL TCL
.undef ${base}_DEFAULT
.  endfor

.  for base in ${DEFAULT_VERSIONS}
_l=			${base:C/=.*//g}
${_l:tu}_DEFAULT=	${base:C/.*=//g}
.  endfor

#-------------------------------------------------------------------------
# PERL5
# Possible values: 5.34 and 5.36
#-------------------------------------------------------------------------

PERL5_DEFAULT?=		5.36

PERL_5.36_VERSION=	5.36.1
PERL_5.38_VERSION=	5.38.0

#-------------------------------------------------------------------------
# RUBY
# Possible values: 3.0, 3.1, 3.2
#-------------------------------------------------------------------------

RUBY_DEFAULT?=		3.1

RUBY_3.0_VERSION=	3.0.3
RUBY_3.1_VERSION=	3.1.3
RUBY_3.2_VERSION=	3.2.2

#-------------------------------------------------------------------------
# PYTHON
# Possible values: 3.10, 3.11
#-------------------------------------------------------------------------

PYTHON3_DEFAULT?=	3.10

PYTHON_3.10_VERSION=	3.10.13
PYTHON_3.11_VERSION=	3.11.5

#-------------------------------------------------------------------------
# SSL
# Possible values: openssl10, openssl11, openssl30, libressl, libressl-devel
#-------------------------------------------------------------------------

SSL_DEFAULT?=		libressl

#-------------------------------------------------------------------------
# LUA
# Possible values: 5.2, 5.3, 5.4
#-------------------------------------------------------------------------

LUA_DEFAULT?=		5.3

LUA_5.2_VERSION=	5.2.4
LUA_5.3_VERSION=	5.3.6
LUA_5.4_VERSION=	5.4.6

#-------------------------------------------------------------------------
# TCL/TK
# Possible values: 8.5, 8.6
#-------------------------------------------------------------------------

TCL_DEFAULT?=		8.6

TCL_8.5_VERSION=	8.5.19
TCL_8.6_VERSION=	8.6.13

#-------------------------------------------------------------------------
# PGSQL
# Possible values: 11, 12, 13, 14, 15
#-------------------------------------------------------------------------

PGSQL_DEFAULT?=		14

PGSQL_11_VERSION=	11.21
PGSQL_12_VERSION=	12.16
PGSQL_13_VERSION=	13.12
PGSQL_14_VERSION=	14.9
PGSQL_15_VERSION=	15.4

#-------------------------------------------------------------------------
# MYSQL and derivatives
# Possible values: oracle-(5.7,8.0,8.1), mariadb-(10.[456], 10.1[1], 11)
#
# MariaDB releases:
#   MariaDB 10.4   EOL 18 JUN 2024 (STABLE)
#   MariaDB 10.5   EOL 24 JUN 2025 (STABLE)
#   MariaDB 10.6   EOL 06 JUL 2026 (STABLE-LTS)
#   MariaDB 10.7   EOL 14 Feb 2023 (REMOVED)
#   MariaDB 10.8   EOL 20 May 2023 (REMOVED)
#   MariaDB 10.9   EOL 22 Aug 2023 (REMOVED)
#   MariaDB 10.10  EOL 17 Nov 2023 (REMOVED)
#   MariaDB 10.11  EOL 16 Feb 2028 (STABLE-LTS)
#   MariaDB 11.1   EOL 20 Aug 2025 (SHORT-TERM)
#
#-------------------------------------------------------------------------

MYSQL_DEFAULT=			oracle-8.0

MYSQL_oracle-5.7_VERSION=	5.7.43
MYSQL_oracle-8.0_VERSION=	8.0.34
MYSQL_oracle-8.1_VERSION=	8.1.0
MYSQL_mariadb-10.4_VERSION=	10.4.31
MYSQL_mariadb-10.5_VERSION=	10.5.22
MYSQL_mariadb-10.6_VERSION=	10.6.15
MYSQL_mariadb-10.11_VERSION=	10.11.5
MYSQL_mariadb-11_VERSION=	11.1.2

#-------------------------------------------------------------------------
# PHP (restricted to branches still receiving updates)
# Possible values: 8.0, 8.1, 8.2
#-------------------------------------------------------------------------

PHP_DEFAULT?=		8.1

PHP_8.0_VERSION=	8.0.30
PHP_8.1_VERSION=	8.1.23
PHP_8.2_VERSION=	8.2.10

#-------------------------------------------------------------------------
# Ravenports system root versions per platform
# Format: ID=opsys/arch/stdarch/os-version/os-release/os-major
#-------------------------------------------------------------------------

PLATFORM_FreeBSD_x86-64=	FreeBSD/amd64/x86_64/1302001/13.2/13
PLATFORM_DragonFly_x86-64=	DragonFly/x86_64/x86_64/600400/6.4/6.4
PLATFORM_Linux_x86-64=		Linux/x86_64/x86_64/610000/6.1.0/6.1
PLATFORM_SunOS_x86-64=		SunOS/i86pc/x86_64/510200910/5.10/5.10
PLATFORM_MacOS_x86-64=		Darwin/x86_64/x86_64/170700/17.7.0/17
PLATFORM_NetBSD_x86-64=		NetBSD/x86_64/x86_64/902000000/9.2/9
PLATFORM_MidnightBSD_x86-64=	MidnightBSD/amd64/x86_64/300005/3.0.0/3
PLATFORM_OpenBSD_x86-64=	OpenBSD/amd64/x86_64/tbd/tbd/tbd

#-------------------------------------------------------------------------
# To support old system roots
#-------------------------------------------------------------------------

PREVIOUS_DF64_R62=		DragonFly/x86_64/x86_64/600200/6.2/6.2
PREVIOUS_Linux_K44=		Linux/x86_64/x86_64/440053/4.4.0/4.4
PREVIOUS_FBSD64_R12=		FreeBSD/amd64/x86_64/1202000/12.2/12

.endif # defined (_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
