/*
 * Copyright (C) 2017 Igalia S.L.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <wtf/Forward.h>
#include <wtf/HashMap.h>
#include <wtf/TZoneMallocInlines.h>
#include <wtf/text/StringHash.h>

namespace WebKit {
class WebNotification;
class WebNotificationManagerProxy;
class WebPageProxy;

enum class WebNotificationIdentifierType;
using WebNotificationIdentifier = ObjectIdentifier<WebNotificationIdentifierType>;
}

namespace WebCore {
class NotificationResources;
}

namespace API {

class NotificationProvider {
    WTF_MAKE_TZONE_ALLOCATED_INLINE(NotificationProvider);
public:
    virtual ~NotificationProvider() = default;

    virtual bool show(WebKit::WebPageProxy*, WebKit::WebNotification&, RefPtr<WebCore::NotificationResources>&&) { return false; }
    virtual void cancel(WebKit::WebNotification&) { }
    virtual void didDestroyNotification(WebKit::WebNotification&) { }
    virtual void clearNotifications(const Vector<WebKit::WebNotificationIdentifier>&) { }

    virtual void addNotificationManager(WebKit::WebNotificationManagerProxy&) { }
    virtual void removeNotificationManager(WebKit::WebNotificationManagerProxy&) { }

    virtual HashMap<WTF::String, bool> notificationPermissions() { return HashMap<WTF::String, bool>(); };
};

} // namespace API
