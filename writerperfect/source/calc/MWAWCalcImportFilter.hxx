/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_WRITERPERFECT_SOURCE_CALC_MWAWCALCIMPORTFILTER_HXX
#define INCLUDED_WRITERPERFECT_SOURCE_CALC_MWAWCALCIMPORTFILTER_HXX

#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>

#include <ImportFilter.hxx>

#include <DocumentHandlerForOds.hxx>

/* This component will be instantiated for both import or export. Whether it calls
 * setSourceDocument or setTargetDocument determines which Impl function the filter
 * member calls */
class MWAWCalcImportFilter : public writerperfect::ImportFilter<OdsGenerator>
{
public:
    explicit MWAWCalcImportFilter(const css::uno::Reference<css::uno::XComponentContext>& rxContext)
        : writerperfect::ImportFilter<OdsGenerator>(rxContext)
    {
    }

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual sal_Bool SAL_CALL supportsService(const OUString& ServiceName) override;
    virtual css::uno::Sequence<OUString> SAL_CALL getSupportedServiceNames() override;

private:
    virtual bool doDetectFormat(librevenge::RVNGInputStream& rInput, OUString& rTypeName) override;
    virtual bool doImportDocument(weld::Window* pParent, librevenge::RVNGInputStream& rInput,
                                  OdsGenerator& rGenerator, utl::MediaDescriptor&) override;
    virtual void doRegisterHandlers(OdsGenerator& rGenerator) override;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
