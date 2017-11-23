/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef jaeger_TYPES_H
#define jaeger_TYPES_H

#include <iosfwd>

#include "thrift-lib/TBase.h"
#include "thrift-lib/protocol/TProtocol.h"
#include "thrift-lib/transport/TTransport.h"

struct TagType {
  enum type {
    STRING = 0,
    DOUBLE = 1,
    BOOL = 2,
    LONG = 3,
    BINARY = 4
  };
};

extern const std::map<int, const char*> _TagType_VALUES_TO_NAMES;

struct SpanRefType {
  enum type {
    CHILD_OF = 0,
    FOLLOWS_FROM = 1
  };
};

extern const std::map<int, const char*> _SpanRefType_VALUES_TO_NAMES;

class Tag;

class Log;

class SpanRef;

class Span;

class Process;

class Batch;

typedef struct _Tag__isset {
  _Tag__isset() : vStr(false), vDouble(false), vBool(false), vLong(false), vBinary(false) {}
  bool vStr :1;
  bool vDouble :1;
  bool vBool :1;
  bool vLong :1;
  bool vBinary :1;
} _Tag__isset;

class Tag : public virtual ::apache::thrift::TBase {
 public:

  Tag(const Tag&);
  Tag& operator=(const Tag&);
  Tag() : key(), vType((TagType::type)0), vStr(), vDouble(0), vBool(0), vLong(0), vBinary() {
  }

  virtual ~Tag() noexcept;
  std::string key;
  TagType::type vType;
  std::string vStr;
  double vDouble;
  bool vBool;
  int64_t vLong;
  std::string vBinary;

  _Tag__isset __isset;

  void __set_key(const std::string& val);

  void __set_vType(const TagType::type val);

  void __set_vStr(const std::string& val);

  void __set_vDouble(const double val);

  void __set_vBool(const bool val);

  void __set_vLong(const int64_t val);

  void __set_vBinary(const std::string& val);

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(::Tag &a, ::Tag &b);

class Log : public virtual ::apache::thrift::TBase {
 public:

  Log(const Log&);
  Log& operator=(const Log&);
  Log() : timestamp(0) {
  }

  virtual ~Log() noexcept;
  int64_t timestamp;
  std::vector<::Tag>  fields;

  void __set_timestamp(const int64_t val);

  void __set_fields(const std::vector<::Tag> & val);

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(::Log &a, ::Log &b);

class SpanRef : public virtual ::apache::thrift::TBase {
 public:

  SpanRef(const SpanRef&);
  SpanRef& operator=(const SpanRef&);
  SpanRef() : refType((SpanRefType::type)0), traceIdLow(0), traceIdHigh(0), spanId(0) {
  }

  virtual ~SpanRef() noexcept;
  SpanRefType::type refType;
  int64_t traceIdLow;
  int64_t traceIdHigh;
  int64_t spanId;

  void __set_refType(const SpanRefType::type val);

  void __set_traceIdLow(const int64_t val);

  void __set_traceIdHigh(const int64_t val);

  void __set_spanId(const int64_t val);

  bool operator == (const SpanRef & rhs) const
  {
    if (!(refType == rhs.refType))
      return false;
    if (!(traceIdLow == rhs.traceIdLow))
      return false;
    if (!(traceIdHigh == rhs.traceIdHigh))
      return false;
    if (!(spanId == rhs.spanId))
      return false;
    return true;
  }
  bool operator != (const SpanRef &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SpanRef & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(SpanRef &a, SpanRef &b);

typedef struct _Span__isset {
  _Span__isset() : references(false), tags(false), logs(false) {}
  bool references :1;
  bool tags :1;
  bool logs :1;
} _Span__isset;

class Span : public virtual ::apache::thrift::TBase {
 public:

  Span(const Span&);
  Span& operator=(const Span&);
  Span() : traceIdLow(0), traceIdHigh(0), spanId(0), parentSpanId(0), operationName(), flags(0), startTime(0), duration(0) {
  }

  virtual ~Span() noexcept;
  int64_t traceIdLow;
  int64_t traceIdHigh;
  int64_t spanId;
  int64_t parentSpanId;
  std::string operationName;
  std::vector<SpanRef>  references;
  int32_t flags;
  int64_t startTime;
  int64_t duration;
  std::vector<::Tag>  tags;
  std::vector<::Log>  logs;

  _Span__isset __isset;

  void __set_traceIdLow(const int64_t val);

  void __set_traceIdHigh(const int64_t val);

  void __set_spanId(const int64_t val);

  void __set_parentSpanId(const int64_t val);

  void __set_operationName(const std::string& val);

  void __set_references(const std::vector<SpanRef> & val);

  void __set_flags(const int32_t val);

  void __set_startTime(const int64_t val);

  void __set_duration(const int64_t val);

  void __set_tags(const std::vector<::Tag> & val);

  void __set_logs(const std::vector<::Log> & val);

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Span &a, Span &b);

typedef struct _Process__isset {
  _Process__isset() : tags(false) {}
  bool tags :1;
} _Process__isset;

class Process : public virtual ::apache::thrift::TBase {
 public:

  Process(const Process&);
  Process& operator=(const Process&);
  Process() : serviceName() {
  }

  virtual ~Process() noexcept;
  std::string serviceName;
  std::vector<::Tag>  tags;

  _Process__isset __isset;

  void __set_serviceName(const std::string& val);

  void __set_tags(const std::vector<::Tag> & val);

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(::Process &a, ::Process &b);

class Batch : public virtual ::apache::thrift::TBase {
 public:

  Batch(const Batch&);
  Batch& operator=(const Batch&);
  Batch() {
  }

  virtual ~Batch() noexcept;
  ::Process process;
  std::vector<Span>  spans;

  void __set_process(const ::Process& val);

  void __set_spans(const std::vector<Span> & val);

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Batch &a, Batch &b);

#endif