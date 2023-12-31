// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Register.proto

#include "Register.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace request_proto {
constexpr EngineInfoRequest::EngineInfoRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : chaintype_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , chainid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct EngineInfoRequestDefaultTypeInternal {
  constexpr EngineInfoRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~EngineInfoRequestDefaultTypeInternal() {}
  union {
    EngineInfoRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT EngineInfoRequestDefaultTypeInternal _EngineInfoRequest_default_instance_;
constexpr EngineInfoResponse::EngineInfoResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : ias_attestation_report_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , enclave_pk_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , error_info_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct EngineInfoResponseDefaultTypeInternal {
  constexpr EngineInfoResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~EngineInfoResponseDefaultTypeInternal() {}
  union {
    EngineInfoResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT EngineInfoResponseDefaultTypeInternal _EngineInfoResponse_default_instance_;
}  // namespace request_proto
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Register_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Register_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Register_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Register_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::request_proto::EngineInfoRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::request_proto::EngineInfoRequest, chaintype_),
  PROTOBUF_FIELD_OFFSET(::request_proto::EngineInfoRequest, chainid_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::request_proto::EngineInfoResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::request_proto::EngineInfoResponse, ias_attestation_report_),
  PROTOBUF_FIELD_OFFSET(::request_proto::EngineInfoResponse, enclave_pk_),
  PROTOBUF_FIELD_OFFSET(::request_proto::EngineInfoResponse, error_info_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::request_proto::EngineInfoRequest)},
  { 7, -1, sizeof(::request_proto::EngineInfoResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::request_proto::_EngineInfoRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::request_proto::_EngineInfoResponse_default_instance_),
};

const char descriptor_table_protodef_Register_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016Register.proto\022\rrequest_proto\"7\n\021Engin"
  "eInfoRequest\022\021\n\tChainType\030\001 \001(\t\022\017\n\007Chain"
  "Id\030\002 \001(\t\"\\\n\022EngineInfoResponse\022\036\n\026ias_at"
  "testation_report\030\001 \001(\t\022\022\n\nenclave_pk\030\002 \001"
  "(\t\022\022\n\nerror_info\030\003 \001(\t2`\n\010Register\022T\n\rGe"
  "tEngineInfo\022 .request_proto.EngineInfoRe"
  "quest\032!.request_proto.EngineInfoResponse"
  "b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Register_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Register_2eproto = {
  false, false, 288, descriptor_table_protodef_Register_2eproto, "Register.proto", 
  &descriptor_table_Register_2eproto_once, nullptr, 0, 2,
  schemas, file_default_instances, TableStruct_Register_2eproto::offsets,
  file_level_metadata_Register_2eproto, file_level_enum_descriptors_Register_2eproto, file_level_service_descriptors_Register_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_Register_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_Register_2eproto);
  return descriptor_table_Register_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Register_2eproto(&descriptor_table_Register_2eproto);
namespace request_proto {

// ===================================================================

class EngineInfoRequest::_Internal {
 public:
};

EngineInfoRequest::EngineInfoRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:request_proto.EngineInfoRequest)
}
EngineInfoRequest::EngineInfoRequest(const EngineInfoRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  chaintype_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_chaintype().empty()) {
    chaintype_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_chaintype(), 
      GetArena());
  }
  chainid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_chainid().empty()) {
    chainid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_chainid(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:request_proto.EngineInfoRequest)
}

void EngineInfoRequest::SharedCtor() {
chaintype_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
chainid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

EngineInfoRequest::~EngineInfoRequest() {
  // @@protoc_insertion_point(destructor:request_proto.EngineInfoRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void EngineInfoRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  chaintype_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  chainid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void EngineInfoRequest::ArenaDtor(void* object) {
  EngineInfoRequest* _this = reinterpret_cast< EngineInfoRequest* >(object);
  (void)_this;
}
void EngineInfoRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void EngineInfoRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void EngineInfoRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:request_proto.EngineInfoRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  chaintype_.ClearToEmpty();
  chainid_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* EngineInfoRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string ChainType = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_chaintype();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.EngineInfoRequest.ChainType"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string ChainId = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_chainid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.EngineInfoRequest.ChainId"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* EngineInfoRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:request_proto.EngineInfoRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string ChainType = 1;
  if (this->chaintype().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_chaintype().data(), static_cast<int>(this->_internal_chaintype().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.EngineInfoRequest.ChainType");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_chaintype(), target);
  }

  // string ChainId = 2;
  if (this->chainid().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_chainid().data(), static_cast<int>(this->_internal_chainid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.EngineInfoRequest.ChainId");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_chainid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:request_proto.EngineInfoRequest)
  return target;
}

size_t EngineInfoRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:request_proto.EngineInfoRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string ChainType = 1;
  if (this->chaintype().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chaintype());
  }

  // string ChainId = 2;
  if (this->chainid().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_chainid());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void EngineInfoRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:request_proto.EngineInfoRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const EngineInfoRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<EngineInfoRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:request_proto.EngineInfoRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:request_proto.EngineInfoRequest)
    MergeFrom(*source);
  }
}

void EngineInfoRequest::MergeFrom(const EngineInfoRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:request_proto.EngineInfoRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.chaintype().size() > 0) {
    _internal_set_chaintype(from._internal_chaintype());
  }
  if (from.chainid().size() > 0) {
    _internal_set_chainid(from._internal_chainid());
  }
}

void EngineInfoRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:request_proto.EngineInfoRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EngineInfoRequest::CopyFrom(const EngineInfoRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:request_proto.EngineInfoRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EngineInfoRequest::IsInitialized() const {
  return true;
}

void EngineInfoRequest::InternalSwap(EngineInfoRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  chaintype_.Swap(&other->chaintype_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  chainid_.Swap(&other->chainid_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata EngineInfoRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class EngineInfoResponse::_Internal {
 public:
};

EngineInfoResponse::EngineInfoResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:request_proto.EngineInfoResponse)
}
EngineInfoResponse::EngineInfoResponse(const EngineInfoResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ias_attestation_report_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_ias_attestation_report().empty()) {
    ias_attestation_report_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_ias_attestation_report(), 
      GetArena());
  }
  enclave_pk_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_enclave_pk().empty()) {
    enclave_pk_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_enclave_pk(), 
      GetArena());
  }
  error_info_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_error_info().empty()) {
    error_info_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_error_info(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:request_proto.EngineInfoResponse)
}

void EngineInfoResponse::SharedCtor() {
ias_attestation_report_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
enclave_pk_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
error_info_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

EngineInfoResponse::~EngineInfoResponse() {
  // @@protoc_insertion_point(destructor:request_proto.EngineInfoResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void EngineInfoResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  ias_attestation_report_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  enclave_pk_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  error_info_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void EngineInfoResponse::ArenaDtor(void* object) {
  EngineInfoResponse* _this = reinterpret_cast< EngineInfoResponse* >(object);
  (void)_this;
}
void EngineInfoResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void EngineInfoResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void EngineInfoResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:request_proto.EngineInfoResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ias_attestation_report_.ClearToEmpty();
  enclave_pk_.ClearToEmpty();
  error_info_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* EngineInfoResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string ias_attestation_report = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_ias_attestation_report();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.EngineInfoResponse.ias_attestation_report"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string enclave_pk = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_enclave_pk();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.EngineInfoResponse.enclave_pk"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string error_info = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_error_info();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "request_proto.EngineInfoResponse.error_info"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* EngineInfoResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:request_proto.EngineInfoResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string ias_attestation_report = 1;
  if (this->ias_attestation_report().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_ias_attestation_report().data(), static_cast<int>(this->_internal_ias_attestation_report().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.EngineInfoResponse.ias_attestation_report");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_ias_attestation_report(), target);
  }

  // string enclave_pk = 2;
  if (this->enclave_pk().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_enclave_pk().data(), static_cast<int>(this->_internal_enclave_pk().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.EngineInfoResponse.enclave_pk");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_enclave_pk(), target);
  }

  // string error_info = 3;
  if (this->error_info().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_error_info().data(), static_cast<int>(this->_internal_error_info().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "request_proto.EngineInfoResponse.error_info");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_error_info(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:request_proto.EngineInfoResponse)
  return target;
}

size_t EngineInfoResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:request_proto.EngineInfoResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string ias_attestation_report = 1;
  if (this->ias_attestation_report().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_ias_attestation_report());
  }

  // string enclave_pk = 2;
  if (this->enclave_pk().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_enclave_pk());
  }

  // string error_info = 3;
  if (this->error_info().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_error_info());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void EngineInfoResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:request_proto.EngineInfoResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const EngineInfoResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<EngineInfoResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:request_proto.EngineInfoResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:request_proto.EngineInfoResponse)
    MergeFrom(*source);
  }
}

void EngineInfoResponse::MergeFrom(const EngineInfoResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:request_proto.EngineInfoResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.ias_attestation_report().size() > 0) {
    _internal_set_ias_attestation_report(from._internal_ias_attestation_report());
  }
  if (from.enclave_pk().size() > 0) {
    _internal_set_enclave_pk(from._internal_enclave_pk());
  }
  if (from.error_info().size() > 0) {
    _internal_set_error_info(from._internal_error_info());
  }
}

void EngineInfoResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:request_proto.EngineInfoResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void EngineInfoResponse::CopyFrom(const EngineInfoResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:request_proto.EngineInfoResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool EngineInfoResponse::IsInitialized() const {
  return true;
}

void EngineInfoResponse::InternalSwap(EngineInfoResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ias_attestation_report_.Swap(&other->ias_attestation_report_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  enclave_pk_.Swap(&other->enclave_pk_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  error_info_.Swap(&other->error_info_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata EngineInfoResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace request_proto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::request_proto::EngineInfoRequest* Arena::CreateMaybeMessage< ::request_proto::EngineInfoRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::request_proto::EngineInfoRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::request_proto::EngineInfoResponse* Arena::CreateMaybeMessage< ::request_proto::EngineInfoResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::request_proto::EngineInfoResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
