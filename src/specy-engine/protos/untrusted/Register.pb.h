// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Register.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Register_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Register_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Register_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Register_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Register_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_Register_2eproto_metadata_getter(int index);
namespace request_proto {
class EngineInfoRequest;
struct EngineInfoRequestDefaultTypeInternal;
extern EngineInfoRequestDefaultTypeInternal _EngineInfoRequest_default_instance_;
class EngineInfoResponse;
struct EngineInfoResponseDefaultTypeInternal;
extern EngineInfoResponseDefaultTypeInternal _EngineInfoResponse_default_instance_;
}  // namespace request_proto
PROTOBUF_NAMESPACE_OPEN
template<> ::request_proto::EngineInfoRequest* Arena::CreateMaybeMessage<::request_proto::EngineInfoRequest>(Arena*);
template<> ::request_proto::EngineInfoResponse* Arena::CreateMaybeMessage<::request_proto::EngineInfoResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace request_proto {

// ===================================================================

class EngineInfoRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:request_proto.EngineInfoRequest) */ {
 public:
  inline EngineInfoRequest() : EngineInfoRequest(nullptr) {}
  virtual ~EngineInfoRequest();
  explicit constexpr EngineInfoRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  EngineInfoRequest(const EngineInfoRequest& from);
  EngineInfoRequest(EngineInfoRequest&& from) noexcept
    : EngineInfoRequest() {
    *this = ::std::move(from);
  }

  inline EngineInfoRequest& operator=(const EngineInfoRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline EngineInfoRequest& operator=(EngineInfoRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const EngineInfoRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const EngineInfoRequest* internal_default_instance() {
    return reinterpret_cast<const EngineInfoRequest*>(
               &_EngineInfoRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(EngineInfoRequest& a, EngineInfoRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(EngineInfoRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(EngineInfoRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline EngineInfoRequest* New() const final {
    return CreateMaybeMessage<EngineInfoRequest>(nullptr);
  }

  EngineInfoRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<EngineInfoRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const EngineInfoRequest& from);
  void MergeFrom(const EngineInfoRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EngineInfoRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "request_proto.EngineInfoRequest";
  }
  protected:
  explicit EngineInfoRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_Register_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kChainTypeFieldNumber = 1,
    kChainIdFieldNumber = 2,
  };
  // string ChainType = 1;
  void clear_chaintype();
  const std::string& chaintype() const;
  void set_chaintype(const std::string& value);
  void set_chaintype(std::string&& value);
  void set_chaintype(const char* value);
  void set_chaintype(const char* value, size_t size);
  std::string* mutable_chaintype();
  std::string* release_chaintype();
  void set_allocated_chaintype(std::string* chaintype);
  private:
  const std::string& _internal_chaintype() const;
  void _internal_set_chaintype(const std::string& value);
  std::string* _internal_mutable_chaintype();
  public:

  // string ChainId = 2;
  void clear_chainid();
  const std::string& chainid() const;
  void set_chainid(const std::string& value);
  void set_chainid(std::string&& value);
  void set_chainid(const char* value);
  void set_chainid(const char* value, size_t size);
  std::string* mutable_chainid();
  std::string* release_chainid();
  void set_allocated_chainid(std::string* chainid);
  private:
  const std::string& _internal_chainid() const;
  void _internal_set_chainid(const std::string& value);
  std::string* _internal_mutable_chainid();
  public:

  // @@protoc_insertion_point(class_scope:request_proto.EngineInfoRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr chaintype_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr chainid_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Register_2eproto;
};
// -------------------------------------------------------------------

class EngineInfoResponse PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:request_proto.EngineInfoResponse) */ {
 public:
  inline EngineInfoResponse() : EngineInfoResponse(nullptr) {}
  virtual ~EngineInfoResponse();
  explicit constexpr EngineInfoResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  EngineInfoResponse(const EngineInfoResponse& from);
  EngineInfoResponse(EngineInfoResponse&& from) noexcept
    : EngineInfoResponse() {
    *this = ::std::move(from);
  }

  inline EngineInfoResponse& operator=(const EngineInfoResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline EngineInfoResponse& operator=(EngineInfoResponse&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const EngineInfoResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const EngineInfoResponse* internal_default_instance() {
    return reinterpret_cast<const EngineInfoResponse*>(
               &_EngineInfoResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(EngineInfoResponse& a, EngineInfoResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(EngineInfoResponse* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(EngineInfoResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline EngineInfoResponse* New() const final {
    return CreateMaybeMessage<EngineInfoResponse>(nullptr);
  }

  EngineInfoResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<EngineInfoResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const EngineInfoResponse& from);
  void MergeFrom(const EngineInfoResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EngineInfoResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "request_proto.EngineInfoResponse";
  }
  protected:
  explicit EngineInfoResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_Register_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIasAttestationReportFieldNumber = 1,
    kEnclavePkFieldNumber = 2,
    kErrorInfoFieldNumber = 3,
  };
  // string ias_attestation_report = 1;
  void clear_ias_attestation_report();
  const std::string& ias_attestation_report() const;
  void set_ias_attestation_report(const std::string& value);
  void set_ias_attestation_report(std::string&& value);
  void set_ias_attestation_report(const char* value);
  void set_ias_attestation_report(const char* value, size_t size);
  std::string* mutable_ias_attestation_report();
  std::string* release_ias_attestation_report();
  void set_allocated_ias_attestation_report(std::string* ias_attestation_report);
  private:
  const std::string& _internal_ias_attestation_report() const;
  void _internal_set_ias_attestation_report(const std::string& value);
  std::string* _internal_mutable_ias_attestation_report();
  public:

  // string enclave_pk = 2;
  void clear_enclave_pk();
  const std::string& enclave_pk() const;
  void set_enclave_pk(const std::string& value);
  void set_enclave_pk(std::string&& value);
  void set_enclave_pk(const char* value);
  void set_enclave_pk(const char* value, size_t size);
  std::string* mutable_enclave_pk();
  std::string* release_enclave_pk();
  void set_allocated_enclave_pk(std::string* enclave_pk);
  private:
  const std::string& _internal_enclave_pk() const;
  void _internal_set_enclave_pk(const std::string& value);
  std::string* _internal_mutable_enclave_pk();
  public:

  // string error_info = 3;
  void clear_error_info();
  const std::string& error_info() const;
  void set_error_info(const std::string& value);
  void set_error_info(std::string&& value);
  void set_error_info(const char* value);
  void set_error_info(const char* value, size_t size);
  std::string* mutable_error_info();
  std::string* release_error_info();
  void set_allocated_error_info(std::string* error_info);
  private:
  const std::string& _internal_error_info() const;
  void _internal_set_error_info(const std::string& value);
  std::string* _internal_mutable_error_info();
  public:

  // @@protoc_insertion_point(class_scope:request_proto.EngineInfoResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr ias_attestation_report_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr enclave_pk_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr error_info_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Register_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EngineInfoRequest

// string ChainType = 1;
inline void EngineInfoRequest::clear_chaintype() {
  chaintype_.ClearToEmpty();
}
inline const std::string& EngineInfoRequest::chaintype() const {
  // @@protoc_insertion_point(field_get:request_proto.EngineInfoRequest.ChainType)
  return _internal_chaintype();
}
inline void EngineInfoRequest::set_chaintype(const std::string& value) {
  _internal_set_chaintype(value);
  // @@protoc_insertion_point(field_set:request_proto.EngineInfoRequest.ChainType)
}
inline std::string* EngineInfoRequest::mutable_chaintype() {
  // @@protoc_insertion_point(field_mutable:request_proto.EngineInfoRequest.ChainType)
  return _internal_mutable_chaintype();
}
inline const std::string& EngineInfoRequest::_internal_chaintype() const {
  return chaintype_.Get();
}
inline void EngineInfoRequest::_internal_set_chaintype(const std::string& value) {
  
  chaintype_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void EngineInfoRequest::set_chaintype(std::string&& value) {
  
  chaintype_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:request_proto.EngineInfoRequest.ChainType)
}
inline void EngineInfoRequest::set_chaintype(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  chaintype_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:request_proto.EngineInfoRequest.ChainType)
}
inline void EngineInfoRequest::set_chaintype(const char* value,
    size_t size) {
  
  chaintype_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:request_proto.EngineInfoRequest.ChainType)
}
inline std::string* EngineInfoRequest::_internal_mutable_chaintype() {
  
  return chaintype_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* EngineInfoRequest::release_chaintype() {
  // @@protoc_insertion_point(field_release:request_proto.EngineInfoRequest.ChainType)
  return chaintype_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void EngineInfoRequest::set_allocated_chaintype(std::string* chaintype) {
  if (chaintype != nullptr) {
    
  } else {
    
  }
  chaintype_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), chaintype,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:request_proto.EngineInfoRequest.ChainType)
}

// string ChainId = 2;
inline void EngineInfoRequest::clear_chainid() {
  chainid_.ClearToEmpty();
}
inline const std::string& EngineInfoRequest::chainid() const {
  // @@protoc_insertion_point(field_get:request_proto.EngineInfoRequest.ChainId)
  return _internal_chainid();
}
inline void EngineInfoRequest::set_chainid(const std::string& value) {
  _internal_set_chainid(value);
  // @@protoc_insertion_point(field_set:request_proto.EngineInfoRequest.ChainId)
}
inline std::string* EngineInfoRequest::mutable_chainid() {
  // @@protoc_insertion_point(field_mutable:request_proto.EngineInfoRequest.ChainId)
  return _internal_mutable_chainid();
}
inline const std::string& EngineInfoRequest::_internal_chainid() const {
  return chainid_.Get();
}
inline void EngineInfoRequest::_internal_set_chainid(const std::string& value) {
  
  chainid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void EngineInfoRequest::set_chainid(std::string&& value) {
  
  chainid_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:request_proto.EngineInfoRequest.ChainId)
}
inline void EngineInfoRequest::set_chainid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  chainid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:request_proto.EngineInfoRequest.ChainId)
}
inline void EngineInfoRequest::set_chainid(const char* value,
    size_t size) {
  
  chainid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:request_proto.EngineInfoRequest.ChainId)
}
inline std::string* EngineInfoRequest::_internal_mutable_chainid() {
  
  return chainid_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* EngineInfoRequest::release_chainid() {
  // @@protoc_insertion_point(field_release:request_proto.EngineInfoRequest.ChainId)
  return chainid_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void EngineInfoRequest::set_allocated_chainid(std::string* chainid) {
  if (chainid != nullptr) {
    
  } else {
    
  }
  chainid_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), chainid,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:request_proto.EngineInfoRequest.ChainId)
}

// -------------------------------------------------------------------

// EngineInfoResponse

// string ias_attestation_report = 1;
inline void EngineInfoResponse::clear_ias_attestation_report() {
  ias_attestation_report_.ClearToEmpty();
}
inline const std::string& EngineInfoResponse::ias_attestation_report() const {
  // @@protoc_insertion_point(field_get:request_proto.EngineInfoResponse.ias_attestation_report)
  return _internal_ias_attestation_report();
}
inline void EngineInfoResponse::set_ias_attestation_report(const std::string& value) {
  _internal_set_ias_attestation_report(value);
  // @@protoc_insertion_point(field_set:request_proto.EngineInfoResponse.ias_attestation_report)
}
inline std::string* EngineInfoResponse::mutable_ias_attestation_report() {
  // @@protoc_insertion_point(field_mutable:request_proto.EngineInfoResponse.ias_attestation_report)
  return _internal_mutable_ias_attestation_report();
}
inline const std::string& EngineInfoResponse::_internal_ias_attestation_report() const {
  return ias_attestation_report_.Get();
}
inline void EngineInfoResponse::_internal_set_ias_attestation_report(const std::string& value) {
  
  ias_attestation_report_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void EngineInfoResponse::set_ias_attestation_report(std::string&& value) {
  
  ias_attestation_report_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:request_proto.EngineInfoResponse.ias_attestation_report)
}
inline void EngineInfoResponse::set_ias_attestation_report(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  ias_attestation_report_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:request_proto.EngineInfoResponse.ias_attestation_report)
}
inline void EngineInfoResponse::set_ias_attestation_report(const char* value,
    size_t size) {
  
  ias_attestation_report_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:request_proto.EngineInfoResponse.ias_attestation_report)
}
inline std::string* EngineInfoResponse::_internal_mutable_ias_attestation_report() {
  
  return ias_attestation_report_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* EngineInfoResponse::release_ias_attestation_report() {
  // @@protoc_insertion_point(field_release:request_proto.EngineInfoResponse.ias_attestation_report)
  return ias_attestation_report_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void EngineInfoResponse::set_allocated_ias_attestation_report(std::string* ias_attestation_report) {
  if (ias_attestation_report != nullptr) {
    
  } else {
    
  }
  ias_attestation_report_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ias_attestation_report,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:request_proto.EngineInfoResponse.ias_attestation_report)
}

// string enclave_pk = 2;
inline void EngineInfoResponse::clear_enclave_pk() {
  enclave_pk_.ClearToEmpty();
}
inline const std::string& EngineInfoResponse::enclave_pk() const {
  // @@protoc_insertion_point(field_get:request_proto.EngineInfoResponse.enclave_pk)
  return _internal_enclave_pk();
}
inline void EngineInfoResponse::set_enclave_pk(const std::string& value) {
  _internal_set_enclave_pk(value);
  // @@protoc_insertion_point(field_set:request_proto.EngineInfoResponse.enclave_pk)
}
inline std::string* EngineInfoResponse::mutable_enclave_pk() {
  // @@protoc_insertion_point(field_mutable:request_proto.EngineInfoResponse.enclave_pk)
  return _internal_mutable_enclave_pk();
}
inline const std::string& EngineInfoResponse::_internal_enclave_pk() const {
  return enclave_pk_.Get();
}
inline void EngineInfoResponse::_internal_set_enclave_pk(const std::string& value) {
  
  enclave_pk_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void EngineInfoResponse::set_enclave_pk(std::string&& value) {
  
  enclave_pk_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:request_proto.EngineInfoResponse.enclave_pk)
}
inline void EngineInfoResponse::set_enclave_pk(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  enclave_pk_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:request_proto.EngineInfoResponse.enclave_pk)
}
inline void EngineInfoResponse::set_enclave_pk(const char* value,
    size_t size) {
  
  enclave_pk_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:request_proto.EngineInfoResponse.enclave_pk)
}
inline std::string* EngineInfoResponse::_internal_mutable_enclave_pk() {
  
  return enclave_pk_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* EngineInfoResponse::release_enclave_pk() {
  // @@protoc_insertion_point(field_release:request_proto.EngineInfoResponse.enclave_pk)
  return enclave_pk_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void EngineInfoResponse::set_allocated_enclave_pk(std::string* enclave_pk) {
  if (enclave_pk != nullptr) {
    
  } else {
    
  }
  enclave_pk_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), enclave_pk,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:request_proto.EngineInfoResponse.enclave_pk)
}

// string error_info = 3;
inline void EngineInfoResponse::clear_error_info() {
  error_info_.ClearToEmpty();
}
inline const std::string& EngineInfoResponse::error_info() const {
  // @@protoc_insertion_point(field_get:request_proto.EngineInfoResponse.error_info)
  return _internal_error_info();
}
inline void EngineInfoResponse::set_error_info(const std::string& value) {
  _internal_set_error_info(value);
  // @@protoc_insertion_point(field_set:request_proto.EngineInfoResponse.error_info)
}
inline std::string* EngineInfoResponse::mutable_error_info() {
  // @@protoc_insertion_point(field_mutable:request_proto.EngineInfoResponse.error_info)
  return _internal_mutable_error_info();
}
inline const std::string& EngineInfoResponse::_internal_error_info() const {
  return error_info_.Get();
}
inline void EngineInfoResponse::_internal_set_error_info(const std::string& value) {
  
  error_info_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void EngineInfoResponse::set_error_info(std::string&& value) {
  
  error_info_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:request_proto.EngineInfoResponse.error_info)
}
inline void EngineInfoResponse::set_error_info(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  error_info_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:request_proto.EngineInfoResponse.error_info)
}
inline void EngineInfoResponse::set_error_info(const char* value,
    size_t size) {
  
  error_info_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:request_proto.EngineInfoResponse.error_info)
}
inline std::string* EngineInfoResponse::_internal_mutable_error_info() {
  
  return error_info_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* EngineInfoResponse::release_error_info() {
  // @@protoc_insertion_point(field_release:request_proto.EngineInfoResponse.error_info)
  return error_info_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void EngineInfoResponse::set_allocated_error_info(std::string* error_info) {
  if (error_info != nullptr) {
    
  } else {
    
  }
  error_info_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), error_info,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:request_proto.EngineInfoResponse.error_info)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace request_proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Register_2eproto
