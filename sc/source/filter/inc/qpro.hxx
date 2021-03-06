/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SC_SOURCE_FILTER_INC_QPRO_HXX
#define INCLUDED_SC_SOURCE_FILTER_INC_QPRO_HXX

#include <rtl/ustring.hxx>
#include <sal/config.h>
#include <filter.hxx>

#include "flttypes.hxx"
#include "ftools.hxx"
#include "qprostyle.hxx"

class ScDocument;

// Stream wrapper class
class ScQProReader
{
    sal_uInt16 mnId;
    sal_uInt16 mnLength;
    sal_uInt32 mnOffset;
    SvStream *mpStream;
    bool mbEndOfFile;
    const SCTAB mnMaxTab;

public:
    ScQProReader(SvStream* pStream);
    ~ScQProReader();

    bool recordsLeft();
    void SetEof( bool bValue ){ mbEndOfFile = bValue; }
    bool nextRecord();
    sal_uInt16 getId() { return mnId; }
    sal_uInt16 getLength() { return mnLength; }
    OUString readString(sal_uInt16 nLength);

    ErrCode parse( ScDocument *pDoc );
    ErrCode import( ScDocument *pDoc ); //parse + CalcAfterLoad
    ErrCode readSheet( SCTAB nTab, ScDocument* pDoc, ScQProStyle *pStyle );
};
#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
