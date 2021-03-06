// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_LOGIN_AUTH_ONLINE_ATTEMPT_HOST_H_
#define CHROME_BROWSER_CHROMEOS_LOGIN_AUTH_ONLINE_ATTEMPT_HOST_H_

#include <string>

#include "base/memory/ref_counted.h"
#include "base/memory/scoped_ptr.h"
#include "base/memory/weak_ptr.h"
#include "chrome/browser/chromeos/login/auth/auth_attempt_state_resolver.h"
#include "chrome/browser/chromeos/login/auth/user_context.h"

namespace content {
class BrowserContext;
}

namespace chromeos {

class AuthAttemptState;
class OnlineAttempt;
class UserContext;

// Helper class which hosts OnlineAttempt for online credentials checking.
class OnlineAttemptHost : public AuthAttemptStateResolver {
 public:
  class Delegate {
    public:
     // Called after user_context were checked online.
     virtual void OnChecked(const std::string& username, bool success) = 0;
  };

  explicit OnlineAttemptHost(Delegate *delegate);
  virtual ~OnlineAttemptHost();

  // Performs an online check of the credentials in |user_context| and invokes
  // the delegate's OnChecked() with the result. Note that only one check can be
  // in progress at any given time. If this method is invoked with a different
  // |user_context| than a check currently in progress, the current check will
  // be silently aborted.
  void Check(content::BrowserContext* auth_context,
             const UserContext& user_context);

  // Resets the checking process.
  void Reset();

  // AuthAttemptStateResolver overrides.
  // Executed on IO thread.
  virtual void Resolve() OVERRIDE;

  // Does an actual resolve on UI thread.
  void ResolveOnUIThread(bool success);

 private:
  Delegate* delegate_;
  UserContext current_attempt_user_context_;
  scoped_ptr<OnlineAttempt> online_attempt_;
  scoped_ptr<AuthAttemptState> state_;
  base::WeakPtrFactory<OnlineAttemptHost> weak_ptr_factory_;

  DISALLOW_COPY_AND_ASSIGN(OnlineAttemptHost);
};

}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_LOGIN_AUTH_ONLINE_ATTEMPT_HOST_H_

