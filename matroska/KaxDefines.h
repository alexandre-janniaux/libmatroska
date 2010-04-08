/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2010 Steve Lhomme.  All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
** 
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
** 
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** See http://www.matroska.org/license/lgpl/ for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
	\file
	\version \$Id: KaxDefines.h,v 1.8 2010/04/02 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_DEFINES_H
#define LIBMATROSKA_DEFINES_H

#include "ebml/EbmlVersion.h"
#include "ebml/EbmlElement.h"

#if LIBEBML_VERSION >= 0x010000
#define DEFINE_MKX_CONTEXT(a)                DEFINE_xxx_CONTEXT(a,*GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER_CONS(a,b,c,d,e)    DEFINE_xxx_MASTER_CONS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER(a,b,c,d,e)         DEFINE_xxx_MASTER(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER_ORPHAN(a,b,c,d)    DEFINE_xxx_MASTER_ORPHAN(a,b,c,d,*GetKaxGlobal_Context)
#define DEFINE_MKX_UINTEGER_DEF(a,b,c,d,e,v) DEFINE_xxx_UINTEGER_DEF(a,b,c,d,e,*GetKaxGlobal_Context,v)
#define DEFINE_MKX_UINTEGER(a,b,c,d,e)       DEFINE_xxx_UINTEGER(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_SINTEGER(a,b,c,d,e)       DEFINE_xxx_SINTEGER(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_SINTEGER_CONS(a,b,c,d,e)  DEFINE_xxx_SINTEGER_CONS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_STRING_DEF(a,b,c,d,e,v)   DEFINE_xxx_STRING_DEF(a,b,c,d,e,*GetKaxGlobal_Context,v)
#define DEFINE_MKX_STRING(a,b,c,d,e)         DEFINE_xxx_STRING(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_UNISTRING(a,b,c,d,e)      DEFINE_xxx_UNISTRING(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_BINARY(a,b,c,d,e)         DEFINE_xxx_BINARY(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_BINARY_CONS(a,b,c,d,e)    DEFINE_xxx_BINARY_CONS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_FLOAT_DEF(a,b,c,d,e,v)    DEFINE_xxx_FLOAT_DEF(a,b,c,d,e,*GetKaxGlobal_Context,v)
#define DEFINE_MKX_FLOAT(a,b,c,d,e)          DEFINE_xxx_FLOAT(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_FLOAT64(a,b,c,d,e)        DEFINE_xxx_FLOAT64(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_DATE(a,b,c,d,e)           DEFINE_xxx_DATE(a,b,c,d,e,*GetKaxGlobal_Context)

#define DECLARE_MKX_CONTEXT(x)

#define DECLARE_MKX_MASTER(x)     DECLARE_MKX_CONTEXT(x) \
class MATROSKA_DLL_API x : public EbmlMaster { \
    public: x(); \
    x(const x & ElementToClone) :EbmlMaster(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_MASTER_CONS(x)     DECLARE_MKX_CONTEXT(x) \
class MATROSKA_DLL_API x : public EbmlMaster { \
    public: x(); \
    x(const x & ElementToClone); \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_BINARY(x)     DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlBinary { \
    public: x(); \
    x(const x & ElementToClone) :EbmlBinary(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_BINARY_CONS(x) DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlBinary { \
    public: x(); \
    x(const x & ElementToClone); \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_UNISTRING(x)  DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlUnicodeString { \
    public: x(); \
    x(const x & ElementToClone) :EbmlUnicodeString(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_STRING(x)     DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlString { \
    public: x(); \
    x(const x & ElementToClone) :EbmlString(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_UINTEGER(x)   DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlUInteger { \
    public: x(); \
    x(const x & ElementToClone) :EbmlUInteger(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_SINTEGER_CONS(x)   DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlSInteger { \
    public: x(); \
    x(const x & ElementToClone); \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_SINTEGER(x)   DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlSInteger { \
    public: x(); \
    x(const x & ElementToClone) :EbmlSInteger(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_DATE(x)       DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlDate { \
    public: x(); \
    x(const x & ElementToClone) :EbmlDate(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_FLOAT(x)      DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlFloat { \
    public: x(); \
    x(const x & ElementToClone) :EbmlFloat(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)


#else
#define DEFINE_MKX_CONTEXT(a)                DEFINE_xxx_CONTEXT(a,*GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER_CONS(a,b,c,d,e)    DEFINE_xxx_MASTER_CONS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER(a,b,c,d,e)         DEFINE_xxx_MASTER(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_MASTER_ORPHAN(a,b,c,d)    DEFINE_xxx_MASTER_ORPHAN(a,b,c,d,*GetKaxGlobal_Context)
#define DEFINE_MKX_UINTEGER_DEF(a,b,c,d,e,v) DEFINE_xxx_UINTEGER_DEF(a,b,c,d,e,*GetKaxGlobal_Context,v)
#define DEFINE_MKX_UINTEGER(a,b,c,d,e)       DEFINE_xxx_CLASS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_SINTEGER(a,b,c,d,e)       DEFINE_xxx_CLASS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_STRING_DEF(a,b,c,d,e,v)   DEFINE_xxx_STRING_DEF(a,b,c,d,e,*GetKaxGlobal_Context,v)
#define DEFINE_MKX_STRING(a,b,c,d,e)         DEFINE_xxx_CLASS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_UNISTRING(a,b,c,d,e)      DEFINE_xxx_CLASS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_BINARY(a,b,c,d,e)         DEFINE_xxx_CLASS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_FLOAT_DEF(a,b,c,d,e,v)    DEFINE_xxx_FLOAT_DEF(a,b,c,d,e,*GetKaxGlobal_Context,v)
#define DEFINE_MKX_FLOAT(a,b,c,d,e)          DEFINE_xxx_CLASS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_DATE(a,b,c,d,e)           DEFINE_xxx_CLASS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_BINARY_CONS(a,b,c,d,e)    DEFINE_xxx_CLASS_CONS(a,b,c,d,e,*GetKaxGlobal_Context)
#define DEFINE_MKX_SINTEGER_CONS(a,b,c,d,e)  DEFINE_xxx_CLASS_CONS(a,b,c,d,e,*GetKaxGlobal_Context)

#define DECLARE_MKX_CONTEXT(x)

#define DECLARE_MKX_MASTER(x)     DECLARE_MKX_CONTEXT(x) \
class MATROSKA_DLL_API x : public EbmlMaster { \
    public: x(); \
    x(const x & ElementToClone) :EbmlMaster(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_MASTER_CONS(x)     DECLARE_MKX_CONTEXT(x) \
class MATROSKA_DLL_API x : public EbmlMaster { \
    public: x(); \
    x(const x & ElementToClone); \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_BINARY(x)     DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlBinary { \
    public: x(); \
    x(const x & ElementToClone) :EbmlBinary(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_BINARY_CONS(x) DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlBinary { \
    public: x(); \
    x(const x & ElementToClone); \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_UNISTRING(x)  DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlUnicodeString { \
    public: x(); \
    x(const x & ElementToClone) :EbmlUnicodeString(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_STRING(x)     DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlString { \
    public: x(); \
    x(const x & ElementToClone) :EbmlString(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_UINTEGER(x)   DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlUInteger { \
    public: x(); \
    x(const x & ElementToClone) :EbmlUInteger(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_SINTEGER_CONS(x)   DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlSInteger { \
    public: x(); \
    x(const x & ElementToClone); \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_SINTEGER(x)   DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlSInteger { \
    public: x(); \
    x(const x & ElementToClone) :EbmlSInteger(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_DATE(x)       DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlDate { \
    public: x(); \
    x(const x & ElementToClone) :EbmlDate(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#define DECLARE_MKX_FLOAT(x)      DECLARE_MKX_CONTEXT(x) \
  class MATROSKA_DLL_API x : public EbmlFloat { \
    public: x(); \
    x(const x & ElementToClone) :EbmlFloat(ElementToClone) {} \
    EBML_CONCRETE_CLASS(x)

#endif

#endif // LIBMATROSKA_DEFINES_H
