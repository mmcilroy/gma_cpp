// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UpdateCache.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "UpdateCache.pb.h"

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

namespace {

const ::google::protobuf::Descriptor* UpdateCache_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UpdateCache_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_UpdateCache_2eproto() {
  protobuf_AddDesc_UpdateCache_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "UpdateCache.proto");
  GOOGLE_CHECK(file != NULL);
  UpdateCache_descriptor_ = file->message_type(0);
  static const int UpdateCache_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateCache, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateCache, value_),
  };
  UpdateCache_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      UpdateCache_descriptor_,
      UpdateCache::default_instance_,
      UpdateCache_offsets_,
      -1,
      -1,
      -1,
      sizeof(UpdateCache),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateCache, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UpdateCache, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_UpdateCache_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      UpdateCache_descriptor_, &UpdateCache::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_UpdateCache_2eproto() {
  delete UpdateCache::default_instance_;
  delete UpdateCache_reflection_;
}

void protobuf_AddDesc_UpdateCache_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021UpdateCache.proto\")\n\013UpdateCache\022\013\n\003ke"
    "y\030\001 \001(\t\022\r\n\005value\030\002 \001(\tb\006proto3", 70);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "UpdateCache.proto", &protobuf_RegisterTypes);
  UpdateCache::default_instance_ = new UpdateCache();
  UpdateCache::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_UpdateCache_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_UpdateCache_2eproto {
  StaticDescriptorInitializer_UpdateCache_2eproto() {
    protobuf_AddDesc_UpdateCache_2eproto();
  }
} static_descriptor_initializer_UpdateCache_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int UpdateCache::kKeyFieldNumber;
const int UpdateCache::kValueFieldNumber;
#endif  // !_MSC_VER

UpdateCache::UpdateCache()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:UpdateCache)
}

void UpdateCache::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

UpdateCache::UpdateCache(const UpdateCache& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:UpdateCache)
}

void UpdateCache::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  key_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  value_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

UpdateCache::~UpdateCache() {
  // @@protoc_insertion_point(destructor:UpdateCache)
  SharedDtor();
}

void UpdateCache::SharedDtor() {
  key_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  value_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void UpdateCache::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UpdateCache::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UpdateCache_descriptor_;
}

const UpdateCache& UpdateCache::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_UpdateCache_2eproto();
  return *default_instance_;
}

UpdateCache* UpdateCache::default_instance_ = NULL;

UpdateCache* UpdateCache::New(::google::protobuf::Arena* arena) const {
  UpdateCache* n = new UpdateCache;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void UpdateCache::Clear() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool UpdateCache::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:UpdateCache)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string key = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_key()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->key().data(), this->key().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "UpdateCache.key"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_value;
        break;
      }

      // optional string value = 2;
      case 2: {
        if (tag == 18) {
         parse_value:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_value()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->value().data(), this->value().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "UpdateCache.value"));
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
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:UpdateCache)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:UpdateCache)
  return false;
#undef DO_
}

void UpdateCache::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:UpdateCache)
  // optional string key = 1;
  if (this->key().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UpdateCache.key");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->key(), output);
  }

  // optional string value = 2;
  if (this->value().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->value().data(), this->value().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UpdateCache.value");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->value(), output);
  }

  // @@protoc_insertion_point(serialize_end:UpdateCache)
}

::google::protobuf::uint8* UpdateCache::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:UpdateCache)
  // optional string key = 1;
  if (this->key().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->key().data(), this->key().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UpdateCache.key");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->key(), target);
  }

  // optional string value = 2;
  if (this->value().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->value().data(), this->value().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UpdateCache.value");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->value(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:UpdateCache)
  return target;
}

int UpdateCache::ByteSize() const {
  int total_size = 0;

  // optional string key = 1;
  if (this->key().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->key());
  }

  // optional string value = 2;
  if (this->value().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->value());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void UpdateCache::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const UpdateCache* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const UpdateCache>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UpdateCache::MergeFrom(const UpdateCache& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.key().size() > 0) {

    key_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.key_);
  }
  if (from.value().size() > 0) {

    value_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.value_);
  }
}

void UpdateCache::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UpdateCache::CopyFrom(const UpdateCache& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateCache::IsInitialized() const {

  return true;
}

void UpdateCache::Swap(UpdateCache* other) {
  if (other == this) return;
  InternalSwap(other);
}
void UpdateCache::InternalSwap(UpdateCache* other) {
  key_.Swap(&other->key_);
  value_.Swap(&other->value_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata UpdateCache::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UpdateCache_descriptor_;
  metadata.reflection = UpdateCache_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// UpdateCache

// optional string key = 1;
void UpdateCache::clear_key() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& UpdateCache::key() const {
  // @@protoc_insertion_point(field_get:UpdateCache.key)
  return key_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void UpdateCache::set_key(const ::std::string& value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:UpdateCache.key)
}
 void UpdateCache::set_key(const char* value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:UpdateCache.key)
}
 void UpdateCache::set_key(const char* value, size_t size) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:UpdateCache.key)
}
 ::std::string* UpdateCache::mutable_key() {
  
  // @@protoc_insertion_point(field_mutable:UpdateCache.key)
  return key_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* UpdateCache::release_key() {
  
  return key_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void UpdateCache::set_allocated_key(::std::string* key) {
  if (key != NULL) {
    
  } else {
    
  }
  key_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:UpdateCache.key)
}

// optional string value = 2;
void UpdateCache::clear_value() {
  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& UpdateCache::value() const {
  // @@protoc_insertion_point(field_get:UpdateCache.value)
  return value_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void UpdateCache::set_value(const ::std::string& value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:UpdateCache.value)
}
 void UpdateCache::set_value(const char* value) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:UpdateCache.value)
}
 void UpdateCache::set_value(const char* value, size_t size) {
  
  value_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:UpdateCache.value)
}
 ::std::string* UpdateCache::mutable_value() {
  
  // @@protoc_insertion_point(field_mutable:UpdateCache.value)
  return value_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* UpdateCache::release_value() {
  
  return value_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void UpdateCache::set_allocated_value(::std::string* value) {
  if (value != NULL) {
    
  } else {
    
  }
  value_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set_allocated:UpdateCache.value)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)