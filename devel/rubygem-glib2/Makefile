# $FreeBSD$

PORTNAME=	glib2
PORTVERSION=	3.4.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding for GLib2

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

RUN_DEPENDS=	rubygem-native-package-installer>=1.0.3:devel/rubygem-native-package-installer \
		rubygem-pkg-config>=1.3.5:devel/rubygem-pkg-config

USES=		gem gnome
USE_GNOME=	glib20
USE_RUBY=	yes

.include <bsd.port.mk>
