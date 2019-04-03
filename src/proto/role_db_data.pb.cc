// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: role_db_data.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "role_db_data.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace ROLE_DB {

namespace {

const ::google::protobuf::Descriptor* BASE_DATA_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BASE_DATA_reflection_ = NULL;
const ::google::protobuf::Descriptor* ROLE_DATA_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ROLE_DATA_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_role_5fdb_5fdata_2eproto() {
  protobuf_AddDesc_role_5fdb_5fdata_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "role_db_data.proto");
  GOOGLE_CHECK(file != NULL);
  BASE_DATA_descriptor_ = file->message_type(0);
  static const int BASE_DATA_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BASE_DATA, role_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BASE_DATA, user_id_),
  };
  BASE_DATA_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BASE_DATA_descriptor_,
      BASE_DATA::default_instance_,
      BASE_DATA_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BASE_DATA, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BASE_DATA, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BASE_DATA));
  ROLE_DATA_descriptor_ = file->message_type(1);
  static const int ROLE_DATA_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ROLE_DATA, base_data_),
  };
  ROLE_DATA_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ROLE_DATA_descriptor_,
      ROLE_DATA::default_instance_,
      ROLE_DATA_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ROLE_DATA, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ROLE_DATA, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ROLE_DATA));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_role_5fdb_5fdata_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BASE_DATA_descriptor_, &BASE_DATA::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ROLE_DATA_descriptor_, &ROLE_DATA::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_role_5fdb_5fdata_2eproto() {
  delete BASE_DATA::default_instance_;
  delete BASE_DATA_reflection_;
  delete ROLE_DATA::default_instance_;
  delete ROLE_DATA_reflection_;
}

void protobuf_AddDesc_role_5fdb_5fdata_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  static const char descriptor[] = {  "\n\022role_db_data.proto\022\007ROLE_DB\"-\n\tBASE_DA"
      "TA\022\017\n\007role_id\030\001 \002(\004\022\017\n\007user_id\030\002 \002(\004\"2\n\t"
      "ROLE_DATA\022%\n\tbase_data\030\001 \001(\0132\022.ROLE_DB.B"
      "ASE_DATA"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(    descriptor, 128);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "role_db_data.proto", &protobuf_RegisterTypes);
  BASE_DATA::default_instance_ = new BASE_DATA();
  ROLE_DATA::default_instance_ = new ROLE_DATA();
  BASE_DATA::default_instance_->InitAsDefaultInstance();
  ROLE_DATA::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_role_5fdb_5fdata_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_role_5fdb_5fdata_2eproto {
  StaticDescriptorInitializer_role_5fdb_5fdata_2eproto() {
    protobuf_AddDesc_role_5fdb_5fdata_2eproto();
  }
} static_descriptor_initializer_role_5fdb_5fdata_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int BASE_DATA::kRoleIdFieldNumber;
const int BASE_DATA::kUserIdFieldNumber;
#endif  // !_MSC_VER

BASE_DATA::BASE_DATA()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ROLE_DB.BASE_DATA)
}

void BASE_DATA::InitAsDefaultInstance() {
}

BASE_DATA::BASE_DATA(const BASE_DATA& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ROLE_DB.BASE_DATA)
}

void BASE_DATA::SharedCtor() {
  _cached_size_ = 0;
  role_id_ = GOOGLE_ULONGLONG(0);
  user_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BASE_DATA::~BASE_DATA() {
  // @@protoc_insertion_point(destructor:ROLE_DB.BASE_DATA)
  SharedDtor();
}

void BASE_DATA::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BASE_DATA::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BASE_DATA::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BASE_DATA_descriptor_;
}

const BASE_DATA& BASE_DATA::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_role_5fdb_5fdata_2eproto();
  return *default_instance_;
}

BASE_DATA* BASE_DATA::default_instance_ = NULL;

BASE_DATA* BASE_DATA::New() const {
  return new BASE_DATA;
}

void BASE_DATA::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<BASE_DATA*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(role_id_, user_id_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BASE_DATA::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ROLE_DB.BASE_DATA)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 role_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &role_id_)));
          set_has_role_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_user_id;
        break;
      }

      // required uint64 user_id = 2;
      case 2: {
        if (tag == 16) {
         parse_user_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &user_id_)));
          set_has_user_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ROLE_DB.BASE_DATA)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ROLE_DB.BASE_DATA)
  return false;
#undef DO_
}

void BASE_DATA::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ROLE_DB.BASE_DATA)
  // required uint64 role_id = 1;
  if (has_role_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->role_id(), output);
  }

  // required uint64 user_id = 2;
  if (has_user_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->user_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ROLE_DB.BASE_DATA)
}

::google::protobuf::uint8* BASE_DATA::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ROLE_DB.BASE_DATA)
  // required uint64 role_id = 1;
  if (has_role_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->role_id(), target);
  }

  // required uint64 user_id = 2;
  if (has_user_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->user_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ROLE_DB.BASE_DATA)
  return target;
}

int BASE_DATA::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 role_id = 1;
    if (has_role_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->role_id());
    }

    // required uint64 user_id = 2;
    if (has_user_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->user_id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void BASE_DATA::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BASE_DATA* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BASE_DATA*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BASE_DATA::MergeFrom(const BASE_DATA& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_role_id()) {
      set_role_id(from.role_id());
    }
    if (from.has_user_id()) {
      set_user_id(from.user_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BASE_DATA::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BASE_DATA::CopyFrom(const BASE_DATA& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BASE_DATA::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void BASE_DATA::Swap(BASE_DATA* other) {
  if (other != this) {
    std::swap(role_id_, other->role_id_);
    std::swap(user_id_, other->user_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BASE_DATA::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BASE_DATA_descriptor_;
  metadata.reflection = BASE_DATA_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ROLE_DATA::kBaseDataFieldNumber;
#endif  // !_MSC_VER

ROLE_DATA::ROLE_DATA()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ROLE_DB.ROLE_DATA)
}

void ROLE_DATA::InitAsDefaultInstance() {
  base_data_ = const_cast< ::ROLE_DB::BASE_DATA*>(&::ROLE_DB::BASE_DATA::default_instance());
}

ROLE_DATA::ROLE_DATA(const ROLE_DATA& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ROLE_DB.ROLE_DATA)
}

void ROLE_DATA::SharedCtor() {
  _cached_size_ = 0;
  base_data_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ROLE_DATA::~ROLE_DATA() {
  // @@protoc_insertion_point(destructor:ROLE_DB.ROLE_DATA)
  SharedDtor();
}

void ROLE_DATA::SharedDtor() {
  if (this != default_instance_) {
    delete base_data_;
  }
}

void ROLE_DATA::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ROLE_DATA::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ROLE_DATA_descriptor_;
}

const ROLE_DATA& ROLE_DATA::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_role_5fdb_5fdata_2eproto();
  return *default_instance_;
}

ROLE_DATA* ROLE_DATA::default_instance_ = NULL;

ROLE_DATA* ROLE_DATA::New() const {
  return new ROLE_DATA;
}

void ROLE_DATA::Clear() {
  if (has_base_data()) {
    if (base_data_ != NULL) base_data_->::ROLE_DB::BASE_DATA::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ROLE_DATA::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ROLE_DB.ROLE_DATA)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .ROLE_DB.BASE_DATA base_data = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_base_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ROLE_DB.ROLE_DATA)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ROLE_DB.ROLE_DATA)
  return false;
#undef DO_
}

void ROLE_DATA::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ROLE_DB.ROLE_DATA)
  // optional .ROLE_DB.BASE_DATA base_data = 1;
  if (has_base_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->base_data(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ROLE_DB.ROLE_DATA)
}

::google::protobuf::uint8* ROLE_DATA::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ROLE_DB.ROLE_DATA)
  // optional .ROLE_DB.BASE_DATA base_data = 1;
  if (has_base_data()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->base_data(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ROLE_DB.ROLE_DATA)
  return target;
}

int ROLE_DATA::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .ROLE_DB.BASE_DATA base_data = 1;
    if (has_base_data()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->base_data());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ROLE_DATA::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ROLE_DATA* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ROLE_DATA*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ROLE_DATA::MergeFrom(const ROLE_DATA& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_base_data()) {
      mutable_base_data()->::ROLE_DB::BASE_DATA::MergeFrom(from.base_data());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ROLE_DATA::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ROLE_DATA::CopyFrom(const ROLE_DATA& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ROLE_DATA::IsInitialized() const {

  if (has_base_data()) {
    if (!this->base_data().IsInitialized()) return false;
  }
  return true;
}

void ROLE_DATA::Swap(ROLE_DATA* other) {
  if (other != this) {
    std::swap(base_data_, other->base_data_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ROLE_DATA::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ROLE_DATA_descriptor_;
  metadata.reflection = ROLE_DATA_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace ROLE_DB

// @@protoc_insertion_point(global_scope)
