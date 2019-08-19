#ifndef __ONSFACTORY_H_
#define __ONSFACTORY_H_

#include <stdexcept>

#include "LocalTransactionChecker.h"
#include "ONSChannel.h"
#include "ONSClientException.h"
#include "OrderConsumer.h"
#include "OrderProducer.h"
#include "Producer.h"
#include "PullConsumer.h"
#include "PushConsumer.h"
#include "TransactionProducer.h"

namespace ons {
class ONSCLIENT_API ONSFactoryProperty {
 public:
  ONSFactoryProperty();
  virtual ~ONSFactoryProperty();
  bool checkValidityOfFactoryProperties(const std::string& key, const std::string& value) noexcept(false);
  const char* getLogPath() const;
  void setSendMsgTimeout(const int value);
  void setSendMsgRetryTimes(const int value);
  void setMaxMsgCacheSize(const int size);
  void setOnsTraceSwitch(bool onswitch);
  void setOnsChannel(ONSChannel onsChannel) noexcept(false);
  void setFactoryProperty(const char* key, const char* value) noexcept(false);
  void setFactoryProperties(std::map<std::string, std::string> factoryProperties);
  std::map<std::string, std::string> getFactoryProperties() const;
  const char* getProducerId() const;
  const char* getConsumerId() const;
  const char* getGroupId() const;
  const char* getPublishTopics() const;
  const char* getMessageModel() const;
  const int getSendMsgTimeout() const;
  const int getSuspendTimeMillis() const;
  const int getSendMsgRetryTimes() const;
  const int getConsumeThreadNums() const;
  const int getMaxMsgCacheSize() const;
  const int getMaxMsgCacheSizeInMiB() const;
  const ONSChannel getOnsChannel() const;
  const char* getChannel() const;
  const char* getMessageContent() const;
  const char* getNameSrvAddr() const;
  const char* getNameSrvDomain() const;
  const char* getAccessKey() const;
  const char* getSecretKey() const;
  const char* getConsumerInstanceName() const;
  bool getOnsTraceSwitch() const;
  const char* getInstanceId() const;

 public:
  static const char* LogPath;
  static const char* ProducerId;
  static const char* ConsumerId;
  static const char* GroupId;
  static const char* PublishTopics;
  static const char* MsgContent;
  static const char* ONSAddr;
  static const char* AccessKey;
  static const char* SecretKey;
  static const char* MessageModel;
  static const char* BROADCASTING;
  static const char* CLUSTERING;
  static const char* SendMsgTimeoutMillis;
  static const char* SuspendTimeMillis;
  static const char* NAMESRV_ADDR;
  static const char* ConsumeThreadNums;
  static const char* OnsChannel;
  static const char* MaxMsgCacheSize;
  static const char* MaxCachedMessageSizeInMiB;
  static const char* OnsTraceSwitch;
  static const char* SendMsgRetryTimes;
  static const char* ConsumerInstanceName;
  static const char* InstanceId;

 private:
  std::map<std::string, std::string> m_onsFactoryProperties;
};

class ONSCLIENT_API ONSFactoryAPI {
 public:
  ONSFactoryAPI();
  virtual ~ONSFactoryAPI();

  virtual ons::Producer* createProducer(ons::ONSFactoryProperty factoryProperty) noexcept(false);
  virtual ons::OrderProducer* createOrderProducer(ons::ONSFactoryProperty factoryProperty) noexcept(false);
  virtual ons::OrderConsumer* createOrderConsumer(ons::ONSFactoryProperty factoryProperty) noexcept(false);
  virtual ons::TransactionProducer* createTransactionProducer(ons::ONSFactoryProperty factoryProperty,
                                                              ons::LocalTransactionChecker* checker) noexcept(false);
  virtual ons::PullConsumer* createPullConsumer(ons::ONSFactoryProperty factoryProperty) noexcept(false);
  virtual ons::PushConsumer* createPushConsumer(ons::ONSFactoryProperty factoryProperty) noexcept(false);
};

class ONSCLIENT_API ONSFactory {
 public:
  virtual ~ONSFactory();
  static ons::ONSFactoryAPI* getInstance();

 private:
  ONSFactory();
  static ons::ONSFactoryAPI* onsFactoryInstance;
};
}  // namespace ons
#endif
