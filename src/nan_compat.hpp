#ifndef NODE_MDNS_NAN_COMPAT_INCLUDED
#define NODE_MDNS_NAN_COMPAT_INCLUDED

// Compatibility shim for V8 versions where PropertyCallbackInfo::This()
// and Holder() have been removed in favor of HolderV2().

#include <v8-version.h>

#if defined(V8_MAJOR_VERSION) && (V8_MAJOR_VERSION > 12 ||                    \
    (V8_MAJOR_VERSION == 12 && defined(V8_MINOR_VERSION) &&                    \
     (V8_MINOR_VERSION > 5 || (V8_MINOR_VERSION == 5 &&                        \
      defined(V8_BUILD_NUMBER) && V8_BUILD_NUMBER >= 214))))
# define MDNS_HOLDER(info) (info).HolderV2()
#else
# define MDNS_HOLDER(info) (info).Holder()
#endif

// Raw V8 getter signature for use instead of NAN_GETTER on newer V8.
#define MDNS_GETTER(name)                                                      \
    void name(v8::Local<v8::Name> property,                                    \
              const v8::PropertyCallbackInfo<v8::Value> &info)

#endif // NODE_MDNS_NAN_COMPAT_INCLUDED
