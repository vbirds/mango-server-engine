// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: role_db_data.proto

#ifndef PROTOBUF_role_5fdb_5fdata_2eproto__INCLUDED
#define PROTOBUF_role_5fdb_5fdata_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace ROLE_DB {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_role_5fdb_5fdata_2eproto();
void protobuf_AssignDesc_role_5fdb_5fdata_2eproto();
void protobuf_ShutdownFile_role_5fdb_5fdata_2eproto();

class ROLE_BASE_DATA;
class ROLE_DATA;

// ===================================================================

class ROLE_BASE_DATA : public ::google::protobuf::Message {
 public:
  ROLE_BASE_DATA();
  virtual ~ROLE_BASE_DATA();

  ROLE_BASE_DATA(const ROLE_BASE_DATA& from);

  inline ROLE_BASE_DATA& operator=(const ROLE_BASE_DATA& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ROLE_BASE_DATA& default_instance();

  void Swap(ROLE_BASE_DATA* other);

  // implements Message ----------------------------------------------

  ROLE_BASE_DATA* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ROLE_BASE_DATA& from);
  void MergeFrom(const ROLE_BASE_DATA& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint64 role_id = 1;
  inline bool has_role_id() const;
  inline void clear_role_id();
  static const int kRoleIdFieldNumber = 1;
  inline ::google::protobuf::uint64 role_id() const;
  inline void set_role_id(::google::protobuf::uint64 value);

  // required uint64 user_id = 2;
  inline bool has_user_id() const;
  inline void clear_user_id();
  static const int kUserIdFieldNumber = 2;
  inline ::google::protobuf::uint64 user_id() const;
  inline void set_user_id(::google::protobuf::uint64 value);

  // optional string role_name = 3;
  inline bool has_role_name() const;
  inline void clear_role_name();
  static const int kRoleNameFieldNumber = 3;
  inline const ::std::string& role_name() const;
  inline void set_role_name(const ::std::string& value);
  inline void set_role_name(const char* value);
  inline void set_role_name(const char* value, size_t size);
  inline ::std::string* mutable_role_name();
  inline ::std::string* release_role_name();
  inline void set_allocated_role_name(::std::string* role_name);

  // optional int32 level = 4;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 4;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // optional int32 create_time = 5;
  inline bool has_create_time() const;
  inline void clear_create_time();
  static const int kCreateTimeFieldNumber = 5;
  inline ::google::protobuf::int32 create_time() const;
  inline void set_create_time(::google::protobuf::int32 value);

  // optional int32 last_login_time = 6;
  inline bool has_last_login_time() const;
  inline void clear_last_login_time();
  static const int kLastLoginTimeFieldNumber = 6;
  inline ::google::protobuf::int32 last_login_time() const;
  inline void set_last_login_time(::google::protobuf::int32 value);

  // optional int32 last_save_time = 7;
  inline bool has_last_save_time() const;
  inline void clear_last_save_time();
  static const int kLastSaveTimeFieldNumber = 7;
  inline ::google::protobuf::int32 last_save_time() const;
  inline void set_last_save_time(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ROLE_DB.ROLE_BASE_DATA)
 private:
  inline void set_has_role_id();
  inline void clear_has_role_id();
  inline void set_has_user_id();
  inline void clear_has_user_id();
  inline void set_has_role_name();
  inline void clear_has_role_name();
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_create_time();
  inline void clear_has_create_time();
  inline void set_has_last_login_time();
  inline void clear_has_last_login_time();
  inline void set_has_last_save_time();
  inline void clear_has_last_save_time();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint64 role_id_;
  ::google::protobuf::uint64 user_id_;
  ::std::string* role_name_;
  ::google::protobuf::int32 level_;
  ::google::protobuf::int32 create_time_;
  ::google::protobuf::int32 last_login_time_;
  ::google::protobuf::int32 last_save_time_;
  friend void  protobuf_AddDesc_role_5fdb_5fdata_2eproto();
  friend void protobuf_AssignDesc_role_5fdb_5fdata_2eproto();
  friend void protobuf_ShutdownFile_role_5fdb_5fdata_2eproto();

  void InitAsDefaultInstance();
  static ROLE_BASE_DATA* default_instance_;
};
// -------------------------------------------------------------------

class ROLE_DATA : public ::google::protobuf::Message {
 public:
  ROLE_DATA();
  virtual ~ROLE_DATA();

  ROLE_DATA(const ROLE_DATA& from);

  inline ROLE_DATA& operator=(const ROLE_DATA& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ROLE_DATA& default_instance();

  void Swap(ROLE_DATA* other);

  // implements Message ----------------------------------------------

  ROLE_DATA* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ROLE_DATA& from);
  void MergeFrom(const ROLE_DATA& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .ROLE_DB.ROLE_BASE_DATA base_data = 1;
  inline bool has_base_data() const;
  inline void clear_base_data();
  static const int kBaseDataFieldNumber = 1;
  inline const ::ROLE_DB::ROLE_BASE_DATA& base_data() const;
  inline ::ROLE_DB::ROLE_BASE_DATA* mutable_base_data();
  inline ::ROLE_DB::ROLE_BASE_DATA* release_base_data();
  inline void set_allocated_base_data(::ROLE_DB::ROLE_BASE_DATA* base_data);

  // @@protoc_insertion_point(class_scope:ROLE_DB.ROLE_DATA)
 private:
  inline void set_has_base_data();
  inline void clear_has_base_data();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::ROLE_DB::ROLE_BASE_DATA* base_data_;
  friend void  protobuf_AddDesc_role_5fdb_5fdata_2eproto();
  friend void protobuf_AssignDesc_role_5fdb_5fdata_2eproto();
  friend void protobuf_ShutdownFile_role_5fdb_5fdata_2eproto();

  void InitAsDefaultInstance();
  static ROLE_DATA* default_instance_;
};
// ===================================================================


// ===================================================================

// ROLE_BASE_DATA

// optional uint64 role_id = 1;
inline bool ROLE_BASE_DATA::has_role_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ROLE_BASE_DATA::set_has_role_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ROLE_BASE_DATA::clear_has_role_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ROLE_BASE_DATA::clear_role_id() {
  role_id_ = GOOGLE_ULONGLONG(0);
  clear_has_role_id();
}
inline ::google::protobuf::uint64 ROLE_BASE_DATA::role_id() const {
  // @@protoc_insertion_point(field_get:ROLE_DB.ROLE_BASE_DATA.role_id)
  return role_id_;
}
inline void ROLE_BASE_DATA::set_role_id(::google::protobuf::uint64 value) {
  set_has_role_id();
  role_id_ = value;
  // @@protoc_insertion_point(field_set:ROLE_DB.ROLE_BASE_DATA.role_id)
}

// required uint64 user_id = 2;
inline bool ROLE_BASE_DATA::has_user_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ROLE_BASE_DATA::set_has_user_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ROLE_BASE_DATA::clear_has_user_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ROLE_BASE_DATA::clear_user_id() {
  user_id_ = GOOGLE_ULONGLONG(0);
  clear_has_user_id();
}
inline ::google::protobuf::uint64 ROLE_BASE_DATA::user_id() const {
  // @@protoc_insertion_point(field_get:ROLE_DB.ROLE_BASE_DATA.user_id)
  return user_id_;
}
inline void ROLE_BASE_DATA::set_user_id(::google::protobuf::uint64 value) {
  set_has_user_id();
  user_id_ = value;
  // @@protoc_insertion_point(field_set:ROLE_DB.ROLE_BASE_DATA.user_id)
}

// optional string role_name = 3;
inline bool ROLE_BASE_DATA::has_role_name() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ROLE_BASE_DATA::set_has_role_name() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ROLE_BASE_DATA::clear_has_role_name() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ROLE_BASE_DATA::clear_role_name() {
  if (role_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    role_name_->clear();
  }
  clear_has_role_name();
}
inline const ::std::string& ROLE_BASE_DATA::role_name() const {
  // @@protoc_insertion_point(field_get:ROLE_DB.ROLE_BASE_DATA.role_name)
  return *role_name_;
}
inline void ROLE_BASE_DATA::set_role_name(const ::std::string& value) {
  set_has_role_name();
  if (role_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    role_name_ = new ::std::string;
  }
  role_name_->assign(value);
  // @@protoc_insertion_point(field_set:ROLE_DB.ROLE_BASE_DATA.role_name)
}
inline void ROLE_BASE_DATA::set_role_name(const char* value) {
  set_has_role_name();
  if (role_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    role_name_ = new ::std::string;
  }
  role_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:ROLE_DB.ROLE_BASE_DATA.role_name)
}
inline void ROLE_BASE_DATA::set_role_name(const char* value, size_t size) {
  set_has_role_name();
  if (role_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    role_name_ = new ::std::string;
  }
  role_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ROLE_DB.ROLE_BASE_DATA.role_name)
}
inline ::std::string* ROLE_BASE_DATA::mutable_role_name() {
  set_has_role_name();
  if (role_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    role_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:ROLE_DB.ROLE_BASE_DATA.role_name)
  return role_name_;
}
inline ::std::string* ROLE_BASE_DATA::release_role_name() {
  clear_has_role_name();
  if (role_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = role_name_;
    role_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void ROLE_BASE_DATA::set_allocated_role_name(::std::string* role_name) {
  if (role_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete role_name_;
  }
  if (role_name) {
    set_has_role_name();
    role_name_ = role_name;
  } else {
    clear_has_role_name();
    role_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:ROLE_DB.ROLE_BASE_DATA.role_name)
}

// optional int32 level = 4;
inline bool ROLE_BASE_DATA::has_level() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ROLE_BASE_DATA::set_has_level() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ROLE_BASE_DATA::clear_has_level() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ROLE_BASE_DATA::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 ROLE_BASE_DATA::level() const {
  // @@protoc_insertion_point(field_get:ROLE_DB.ROLE_BASE_DATA.level)
  return level_;
}
inline void ROLE_BASE_DATA::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
  // @@protoc_insertion_point(field_set:ROLE_DB.ROLE_BASE_DATA.level)
}

// optional int32 create_time = 5;
inline bool ROLE_BASE_DATA::has_create_time() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ROLE_BASE_DATA::set_has_create_time() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ROLE_BASE_DATA::clear_has_create_time() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ROLE_BASE_DATA::clear_create_time() {
  create_time_ = 0;
  clear_has_create_time();
}
inline ::google::protobuf::int32 ROLE_BASE_DATA::create_time() const {
  // @@protoc_insertion_point(field_get:ROLE_DB.ROLE_BASE_DATA.create_time)
  return create_time_;
}
inline void ROLE_BASE_DATA::set_create_time(::google::protobuf::int32 value) {
  set_has_create_time();
  create_time_ = value;
  // @@protoc_insertion_point(field_set:ROLE_DB.ROLE_BASE_DATA.create_time)
}

// optional int32 last_login_time = 6;
inline bool ROLE_BASE_DATA::has_last_login_time() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ROLE_BASE_DATA::set_has_last_login_time() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ROLE_BASE_DATA::clear_has_last_login_time() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ROLE_BASE_DATA::clear_last_login_time() {
  last_login_time_ = 0;
  clear_has_last_login_time();
}
inline ::google::protobuf::int32 ROLE_BASE_DATA::last_login_time() const {
  // @@protoc_insertion_point(field_get:ROLE_DB.ROLE_BASE_DATA.last_login_time)
  return last_login_time_;
}
inline void ROLE_BASE_DATA::set_last_login_time(::google::protobuf::int32 value) {
  set_has_last_login_time();
  last_login_time_ = value;
  // @@protoc_insertion_point(field_set:ROLE_DB.ROLE_BASE_DATA.last_login_time)
}

// optional int32 last_save_time = 7;
inline bool ROLE_BASE_DATA::has_last_save_time() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void ROLE_BASE_DATA::set_has_last_save_time() {
  _has_bits_[0] |= 0x00000040u;
}
inline void ROLE_BASE_DATA::clear_has_last_save_time() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void ROLE_BASE_DATA::clear_last_save_time() {
  last_save_time_ = 0;
  clear_has_last_save_time();
}
inline ::google::protobuf::int32 ROLE_BASE_DATA::last_save_time() const {
  // @@protoc_insertion_point(field_get:ROLE_DB.ROLE_BASE_DATA.last_save_time)
  return last_save_time_;
}
inline void ROLE_BASE_DATA::set_last_save_time(::google::protobuf::int32 value) {
  set_has_last_save_time();
  last_save_time_ = value;
  // @@protoc_insertion_point(field_set:ROLE_DB.ROLE_BASE_DATA.last_save_time)
}

// -------------------------------------------------------------------

// ROLE_DATA

// optional .ROLE_DB.ROLE_BASE_DATA base_data = 1;
inline bool ROLE_DATA::has_base_data() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ROLE_DATA::set_has_base_data() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ROLE_DATA::clear_has_base_data() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ROLE_DATA::clear_base_data() {
  if (base_data_ != NULL) base_data_->::ROLE_DB::ROLE_BASE_DATA::Clear();
  clear_has_base_data();
}
inline const ::ROLE_DB::ROLE_BASE_DATA& ROLE_DATA::base_data() const {
  // @@protoc_insertion_point(field_get:ROLE_DB.ROLE_DATA.base_data)
  return base_data_ != NULL ? *base_data_ : *default_instance_->base_data_;
}
inline ::ROLE_DB::ROLE_BASE_DATA* ROLE_DATA::mutable_base_data() {
  set_has_base_data();
  if (base_data_ == NULL) base_data_ = new ::ROLE_DB::ROLE_BASE_DATA;
  // @@protoc_insertion_point(field_mutable:ROLE_DB.ROLE_DATA.base_data)
  return base_data_;
}
inline ::ROLE_DB::ROLE_BASE_DATA* ROLE_DATA::release_base_data() {
  clear_has_base_data();
  ::ROLE_DB::ROLE_BASE_DATA* temp = base_data_;
  base_data_ = NULL;
  return temp;
}
inline void ROLE_DATA::set_allocated_base_data(::ROLE_DB::ROLE_BASE_DATA* base_data) {
  delete base_data_;
  base_data_ = base_data;
  if (base_data) {
    set_has_base_data();
  } else {
    clear_has_base_data();
  }
  // @@protoc_insertion_point(field_set_allocated:ROLE_DB.ROLE_DATA.base_data)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace ROLE_DB

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_role_5fdb_5fdata_2eproto__INCLUDED
