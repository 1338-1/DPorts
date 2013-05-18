# $FreeBSD: Mk/Uses/readline.mk 317523 2013-05-06 15:31:45Z bapt $
#
# handle dependency on the readline port
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	readline
# Usage:	USES=readline
# Valid ARGS:	port
#

.if !defined(_INCLUDE_USES_READLINE_MK)
_INCLUDE_USES_READLINE_MK=	yes

.if ${OSVERSION} > 1000000
readline_ARGS=	port
.endif

.if defined(readline_ARGS) && ${readline_ARGS} == port
LIB_DEPENDS+=		readline.6:${PORTSDIR}/devel/readline
CFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -lreadline
.endif

.endif
