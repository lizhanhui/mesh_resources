#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include <stdexcept>

#include "Message.h"
#include "MessageQueueONS.h"
#include "ONSCallback.h"
#include "ONSClientException.h"
#include "SendResultONS.h"

namespace ons {

class ONSCLIENT_API Producer {
 public:
  Producer() {}
  virtual ~Producer() {}

  // before send msg, start must be called to allocate resources.
  virtual void start() = 0;
  // before exit ons, shutdown must be called to release all resources allocated
  // by ons internally.
  virtual void shutdown() = 0;
  // retry max 3 times if send failed. if no exception throwed, it sends
  // success;
  virtual ons::SendResultONS send(Message& msg) noexcept(false)                            = 0;
  virtual ons::SendResultONS send(Message& msg, const MessageQueueONS& mq) noexcept(false) = 0;

  // async send
  virtual void sendAsync(Message& msg, ons::SendCallbackONS* callback) noexcept(false) = 0;

  // oneway send
  virtual void sendOneway(Message& msg) noexcept(false) = 0;
};
}  // namespace ons
#endif
