# Copyright 2013 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
from telemetry import test

from measurements import startup
import page_sets


@test.Disabled('snowleopard') # crbug.com/336913
class StartupColdBlankPage(test.Test):
  tag = 'cold'
  test = startup.Startup
  page_set = page_sets.BlankPageSet
  options = {'cold': True,
             'pageset_repeat': 5}


class StartupWarmBlankPage(test.Test):
  tag = 'warm'
  test = startup.Startup
  page_set = page_sets.BlankPageSet
  options = {'warm': True,
             'pageset_repeat': 20}

@test.Disabled('snowleopard') # crbug.com/336913
class StartupColdTheme(test.Test):
  tag = 'theme_cold'
  test = startup.Startup
  page_set = page_sets.BlankPageSet
  generated_profile_archive = 'theme_profile.zip'
  options = {'cold': True,
             'pageset_repeat': 5}


class StartupWarmTheme(test.Test):
  tag = 'theme_warm'
  test = startup.Startup
  page_set = page_sets.BlankPageSet
  generated_profile_archive = 'theme_profile.zip'
  options = {'warm': True,
             'pageset_repeat': 20}

@test.Disabled('snowleopard') # crbug.com/336913
class StartupColdManyExtensions(test.Test):
  tag = 'many_extensions_cold'
  test = startup.Startup
  page_set = page_sets.BlankPageSet
  generated_profile_archive = 'many_extensions_profile.zip'
  options = {'cold': True,
             'pageset_repeat': 5}


class StartupWarmManyExtensions(test.Test):
  tag = 'many_extensions_warm'
  test = startup.Startup
  page_set = page_sets.BlankPageSet
  generated_profile_archive = 'many_extensions_profile.zip'
  options = {'warm': True,
             'pageset_repeat': 20}
