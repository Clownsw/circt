//===- SVAttributes.cpp - Implement SV attributes -------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "circt/Dialect/SV/SVAttributes.h"
#include "circt/Dialect/SV/SVDialect.h"
#include "circt/Dialect/SV/SVOps.h"
#include "circt/Dialect/SV/SVTypes.h"
#include "circt/Support/LLVM.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace circt;
using namespace circt::sv;

//===----------------------------------------------------------------------===//
// ODS Boilerplate
//===----------------------------------------------------------------------===//

#define GET_ATTRDEF_CLASSES
#include "circt/Dialect/SV/SVAttributes.cpp.inc"

#include "circt/Dialect/SV/SVEnums.cpp.inc"

bool circt::sv::hasSVAttributes(mlir::Operation *op) {
  return op->hasAttr(sv::SVAttributeAttr::getSVAttributesAttrName());
}

sv::SVAttributesAttr circt::sv::getSVAttributes(mlir::Operation *op) {
  return op->getAttrOfType<sv::SVAttributesAttr>(
      sv::SVAttributeAttr::getSVAttributesAttrName());
}

void circt::sv::setSVAttributes(mlir::Operation *op, mlir::Attribute attr) {
  return op->setAttr(sv::SVAttributeAttr::getSVAttributesAttrName(), attr);
}

void SVDialect::registerAttributes() {
  addAttributes<
#define GET_ATTRDEF_LIST
#include "circt/Dialect/SV/SVAttributes.cpp.inc"
      >();
}
