// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_SYNC_MANAGED_USER_SIGNIN_MANAGER_WRAPPER_H_
#define CHROME_BROWSER_SYNC_MANAGED_USER_SIGNIN_MANAGER_WRAPPER_H_

#include <string>

#include "base/basictypes.h"

class Profile;
class SigninManagerBase;

// Some chrome cloud services support managed users as well as normally
// authenticated users that sign in through SigninManager.  To facilitate
// getting the "effective" username and account identifiers, services can
// use this class to wrap the SigninManager and return managed user account
// information when appropriate.
class ManagedUserSigninManagerWrapper {
 public:
  ManagedUserSigninManagerWrapper(Profile* profile,
                                  SigninManagerBase* original);
  virtual ~ManagedUserSigninManagerWrapper();

  virtual std::string GetEffectiveUsername() const;
  virtual std::string GetAccountIdToUse() const;

  virtual std::string GetSyncScopeToUse() const;

  SigninManagerBase* GetOriginal();

 private:
  Profile* profile_;
  SigninManagerBase* original_;
  DISALLOW_COPY_AND_ASSIGN(ManagedUserSigninManagerWrapper);
};

#endif  // CHROME_BROWSER_SYNC_MANAGED_USER_SIGNIN_MANAGER_WRAPPER_H_
