/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "PrivateAttribution.h"

#include "mozilla/Components.h"
#include "mozilla/StaticPrefs_datareporting.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/ContentChild.h"
#include "mozilla/dom/PrivateAttributionBinding.h"
#include "nsIGlobalObject.h"
#include "nsIPrivateAttributionService.h"
#include "nsURLHelper.h"
#include "nsXULAppAPI.h"

namespace mozilla::dom {

NS_IMPL_CYCLE_COLLECTION_WRAPPERCACHE(PrivateAttribution, mGlobal)

PrivateAttribution::PrivateAttribution(nsIGlobalObject* aGlobal)
    : mGlobal(aGlobal) {
  MOZ_ASSERT(aGlobal);
}

JSObject* PrivateAttribution::WrapObject(JSContext* aCx,
                                         JS::Handle<JSObject*> aGivenProto) {
  return nullptr;
}

PrivateAttribution::~PrivateAttribution() = default;

bool PrivateAttribution::ShouldRecord() {
  return false;
}

bool PrivateAttribution::GetSourceHostIfNonPrivate(nsACString& aSourceHost,
                                                   ErrorResult& aRv) {
  MOZ_ASSERT(mGlobal);
  nsIPrincipal* prin = mGlobal->PrincipalOrNull();
  if (!prin || NS_FAILED(prin->GetHost(aSourceHost))) {
    aRv.ThrowInvalidStateError("Couldn't get source host");
    return false;
  }
  return !prin->GetIsInPrivateBrowsing();
}

[[nodiscard]] static bool ValidateHost(const nsACString& aHost,
                                       ErrorResult& aRv) {
  if (!net_IsValidDNSHost(aHost)) {
    aRv.ThrowSyntaxError(aHost + " is not a valid host name"_ns);
    return false;
  }
  return true;
}

void PrivateAttribution::SaveImpression(
    const PrivateAttributionImpressionOptions& aOptions, ErrorResult& aRv) {}
void PrivateAttribution::MeasureConversion(
    const PrivateAttributionConversionOptions& aOptions, ErrorResult& aRv) {}

}  // namespace mozilla::dom
