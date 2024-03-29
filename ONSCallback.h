#ifndef __ONSCALLBACK_H__
#define __ONSCALLBACK_H__

#include "ONSClientException.h"
#include "SendResultONS.h"

namespace ons {
class SendCallbackONS {
 public:
  virtual ~SendCallbackONS() {}
  virtual void onSuccess(SendResultONS& sendResult) { (void)sendResult; };
  virtual void onException(ONSClientException& e) { (void)e; };
};

}  // namespace ons
#endif  // end of _SENDCALLBACK_H_
