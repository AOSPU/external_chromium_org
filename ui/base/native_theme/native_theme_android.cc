// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/base/native_theme/native_theme_android.h"

#include "base/basictypes.h"
#include "base/logging.h"

namespace ui {

// static
NativeTheme* NativeTheme::instance() {
  return NativeThemeAndroid::instance();
}

// static
NativeThemeAndroid* NativeThemeAndroid::instance() {
  CR_DEFINE_STATIC_LOCAL(NativeThemeAndroid, s_native_theme, ());
  return &s_native_theme;
}

SkColor NativeThemeAndroid::GetSystemColor(ColorId color_id) const {
  NOTIMPLEMENTED();
  return SK_ColorBLACK;
}

NativeThemeAndroid::NativeThemeAndroid() {
}

NativeThemeAndroid::~NativeThemeAndroid() {
}

}  // namespace ui