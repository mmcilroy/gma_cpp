// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: XTExecution.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "XTExecution.pb.h"

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

namespace messages {

namespace {

const ::google::protobuf::Descriptor* XTExecution_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  XTExecution_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_XTExecution_2eproto() {
  protobuf_AddDesc_XTExecution_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "XTExecution.proto");
  GOOGLE_CHECK(file != NULL);
  XTExecution_descriptor_ = file->message_type(0);
  static const int XTExecution_offsets_[10] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, clordid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, symbol_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, side_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, ord_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, quantity_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, price_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, ord_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, exec_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, last_qty_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, last_price_),
  };
  XTExecution_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      XTExecution_descriptor_,
      XTExecution::default_instance_,
      XTExecution_offsets_,
      -1,
      -1,
      -1,
      sizeof(XTExecution),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(XTExecution, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_XTExecution_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      XTExecution_descriptor_, &XTExecution::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_XTExecution_2eproto() {
  delete XTExecution::default_instance_;
  delete XTExecution_reflection_;
}

void protobuf_AddDesc_XTExecution_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021XTExecution.proto\022\010messages\"\274\001\n\013XTExec"
    "ution\022\017\n\007clordid\030\001 \001(\t\022\016\n\006symbol\030\002 \001(\t\022\014"
    "\n\004side\030\003 \001(\t\022\020\n\010ord_type\030\004 \001(\t\022\020\n\010quanti"
    "ty\030\005 \001(\r\022\r\n\005price\030\006 \001(\r\022\022\n\nord_status\030\007 "
    "\001(\t\022\021\n\texec_type\030\010 \001(\t\022\020\n\010last_qty\030\t \001(\r"
    "\022\022\n\nlast_price\030\n \001(\rb\006proto3", 228);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "XTExecution.proto", &protobuf_RegisterTypes);
  XTExecution::default_instance_ = new XTExecution();
  XTExecution::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_XTExecution_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_XTExecution_2eproto {
  StaticDescriptorInitializer_XTExecution_2eproto() {
    protobuf_AddDesc_XTExecution_2eproto();
  }
} static_descriptor_initializer_XTExecution_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int XTExecution::kClordidFieldNumber;
const int XTExecution::kSymbolFieldNumber;
const int XTExecution::kSideFieldNumber;
const int XTExecution::kOrdTypeFieldNumber;
const int XTExecution::kQuantityFieldNumber;
const int XTExecution::kPriceFieldNumber;
const int XTExecution::kOrdStatusFieldNumber;
const int XTExecution::kExecTypeFieldNumber;
const int XTExecution::kLastQtyFieldNumber;
const int XTExecution::kLastPriceFieldNumber;
#endif  // !_MSC_VER

XTExecution::XTExecution()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:messages.XTExecution)
}

void XTExecution::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

XTExecution::XTExecution(const XTExecution& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:messages.XTExecution)
}

void XTExecution::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  clordid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  symbol_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  side_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ord_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  quantity_ = 0u;
  price_ = 0u;
  ord_status_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  exec_type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  last_qty_ = 0u;
  last_price_ = 0u;
}

XTExecution::~XTExecution() {
  // @@protoc_insertion_point(destructor:messages.XTExecution)
  SharedDtor();
}

void XTExecution::SharedDtor() {
  clordid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  symbol_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  side_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ord_type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ord_status_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  exec_type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void XTExecution::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* XTExecution::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return XTExecution_descriptor_;
}

const XTExecution& XTExecution::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_XTExecution_2eproto();
  return *default_instance_;
}

XTExecution* XTExecution::default_instance_ = NULL;

XTExecution* XTExecution::New(::google::protobuf::Arena* arena) const {
  XTExecution* n = new XTExecution;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void XTExecution::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<XTExecution*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(quantity_, price_);
  clordid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  symbol_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  side_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ord_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ord_status_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  exec_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ZR_(last_qty_, last_price_);

#undef ZR_HELPER_
#undef ZR_

}

bool XTExecution::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:messages.XTExecution)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string clordid = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_clordid()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->clordid().data(), this->clordid().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "messages.XTExecution.clordid"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_symbol;
        break;
      }

      // optional string symbol = 2;
      case 2: {
        if (tag == 18) {
         parse_symbol:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_symbol()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->symbol().data(), this->symbol().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "messages.XTExecution.symbol"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_side;
        break;
      }

      // optional string side = 3;
      case 3: {
        if (tag == 26) {
         parse_side:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_side()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->side().data(), this->side().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "messages.XTExecution.side"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_ord_type;
        break;
      }

      // optional string ord_type = 4;
      case 4: {
        if (tag == 34) {
         parse_ord_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ord_type()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->ord_type().data(), this->ord_type().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "messages.XTExecution.ord_type"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_quantity;
        break;
      }

      // optional uint32 quantity = 5;
      case 5: {
        if (tag == 40) {
         parse_quantity:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &quantity_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_price;
        break;
      }

      // optional uint32 price = 6;
      case 6: {
        if (tag == 48) {
         parse_price:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &price_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_ord_status;
        break;
      }

      // optional string ord_status = 7;
      case 7: {
        if (tag == 58) {
         parse_ord_status:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ord_status()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->ord_status().data(), this->ord_status().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "messages.XTExecution.ord_status"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_exec_type;
        break;
      }

      // optional string exec_type = 8;
      case 8: {
        if (tag == 66) {
         parse_exec_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_exec_type()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->exec_type().data(), this->exec_type().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "messages.XTExecution.exec_type"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_last_qty;
        break;
      }

      // optional uint32 last_qty = 9;
      case 9: {
        if (tag == 72) {
         parse_last_qty:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &last_qty_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_last_price;
        break;
      }

      // optional uint32 last_price = 10;
      case 10: {
        if (tag == 80) {
         parse_last_price:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &last_price_)));

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
  // @@protoc_insertion_point(parse_success:messages.XTExecution)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:messages.XTExecution)
  return false;
#undef DO_
}

void XTExecution::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:messages.XTExecution)
  // optional string clordid = 1;
  if (this->clordid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->clordid().data(), this->clordid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.clordid");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->clordid(), output);
  }

  // optional string symbol = 2;
  if (this->symbol().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->symbol().data(), this->symbol().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.symbol");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->symbol(), output);
  }

  // optional string side = 3;
  if (this->side().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->side().data(), this->side().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.side");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->side(), output);
  }

  // optional string ord_type = 4;
  if (this->ord_type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ord_type().data(), this->ord_type().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.ord_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->ord_type(), output);
  }

  // optional uint32 quantity = 5;
  if (this->quantity() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->quantity(), output);
  }

  // optional uint32 price = 6;
  if (this->price() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->price(), output);
  }

  // optional string ord_status = 7;
  if (this->ord_status().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ord_status().data(), this->ord_status().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.ord_status");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->ord_status(), output);
  }

  // optional string exec_type = 8;
  if (this->exec_type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->exec_type().data(), this->exec_type().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.exec_type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->exec_type(), output);
  }

  // optional uint32 last_qty = 9;
  if (this->last_qty() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(9, this->last_qty(), output);
  }

  // optional uint32 last_price = 10;
  if (this->last_price() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(10, this->last_price(), output);
  }

  // @@protoc_insertion_point(serialize_end:messages.XTExecution)
}

::google::protobuf::uint8* XTExecution::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:messages.XTExecution)
  // optional string clordid = 1;
  if (this->clordid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->clordid().data(), this->clordid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.clordid");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->clordid(), target);
  }

  // optional string symbol = 2;
  if (this->symbol().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->symbol().data(), this->symbol().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.symbol");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->symbol(), target);
  }

  // optional string side = 3;
  if (this->side().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->side().data(), this->side().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.side");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->side(), target);
  }

  // optional string ord_type = 4;
  if (this->ord_type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ord_type().data(), this->ord_type().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.ord_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->ord_type(), target);
  }

  // optional uint32 quantity = 5;
  if (this->quantity() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->quantity(), target);
  }

  // optional uint32 price = 6;
  if (this->price() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->price(), target);
  }

  // optional string ord_status = 7;
  if (this->ord_status().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->ord_status().data(), this->ord_status().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.ord_status");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->ord_status(), target);
  }

  // optional string exec_type = 8;
  if (this->exec_type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->exec_type().data(), this->exec_type().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "messages.XTExecution.exec_type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->exec_type(), target);
  }

  // optional uint32 last_qty = 9;
  if (this->last_qty() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(9, this->last_qty(), target);
  }

  // optional uint32 last_price = 10;
  if (this->last_price() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(10, this->last_price(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:messages.XTExecution)
  return target;
}

int XTExecution::ByteSize() const {
  int total_size = 0;

  // optional string clordid = 1;
  if (this->clordid().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->clordid());
  }

  // optional string symbol = 2;
  if (this->symbol().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->symbol());
  }

  // optional string side = 3;
  if (this->side().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->side());
  }

  // optional string ord_type = 4;
  if (this->ord_type().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->ord_type());
  }

  // optional uint32 quantity = 5;
  if (this->quantity() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->quantity());
  }

  // optional uint32 price = 6;
  if (this->price() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->price());
  }

  // optional string ord_status = 7;
  if (this->ord_status().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->ord_status());
  }

  // optional string exec_type = 8;
  if (this->exec_type().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->exec_type());
  }

  // optional uint32 last_qty = 9;
  if (this->last_qty() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->last_qty());
  }

  // optional uint32 last_price = 10;
  if (this->last_price() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->last_price());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void XTExecution::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const XTExecution* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const XTExecution>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void XTExecution::MergeFrom(const XTExecution& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.clordid().size() > 0) {

    clordid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.clordid_);
  }
  if (from.symbol().size() > 0) {

    symbol_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.symbol_);
  }
  if (from.side().size() > 0) {

    side_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.side_);
  }
  if (from.ord_type().size() > 0) {

    ord_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ord_type_);
  }
  if (from.quantity() != 0) {
    set_quantity(from.quantity());
  }
  if (from.price() != 0) {
    set_price(from.price());
  }
  if (from.ord_status().size() > 0) {

    ord_status_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.ord_status_);
  }
  if (from.exec_type().size() > 0) {

    exec_type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.exec_type_);
  }
  if (from.last_qty() != 0) {
    set_last_qty(from.last_qty());
  }
  if (from.last_price() != 0) {
    set_last_price(from.last_price());
  }
}

void XTExecution::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void XTExecution::CopyFrom(const XTExecution& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool XTExecution::IsInitialized() const {

  return true;
}

void XTExecution::Swap(XTExecution* other) {
  if (other == this) return;
  InternalSwap(other);
}
void XTExecution::InternalSwap(XTExecution* other) {
  clordid_.Swap(&other->clordid_);
  symbol_.Swap(&other->symbol_);
  side_.Swap(&other->side_);
  ord_type_.Swap(&other->ord_type_);
  std::swap(quantity_, other->quantity_);
  std::swap(price_, other->price_);
  ord_status_.Swap(&other->ord_status_);
  exec_type_.Swap(&other->exec_type_);
  std::swap(last_qty_, other->last_qty_);
  std::swap(last_price_, other->last_price_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata XTExecution::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = XTExecution_descriptor_;
  metadata.reflection = XTExecution_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// XTExecution

// optional string clordid = 1;
void XTExecution::clear_clordid() {
  clordid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& XTExecution::clordid() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.clordid)
  return clordid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_clordid(const ::std::string& value) {
  
  clordid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.XTExecution.clordid)
}
 void XTExecution::set_clordid(const char* value) {
  
  clordid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.XTExecution.clordid)
}
 void XTExecution::set_clordid(const char* value, size_t size) {
  
  clordid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.XTExecution.clordid)
}
 ::std::string* XTExecution::mutable_clordid() {
  
  // @@protoc_insertion_point(field_mutable:messages.XTExecution.clordid)
  return clordid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* XTExecution::release_clordid() {
  
  return clordid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_allocated_clordid(::std::string* clordid) {
  if (clordid != NULL) {
    
  } else {
    
  }
  clordid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), clordid);
  // @@protoc_insertion_point(field_set_allocated:messages.XTExecution.clordid)
}

// optional string symbol = 2;
void XTExecution::clear_symbol() {
  symbol_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& XTExecution::symbol() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.symbol)
  return symbol_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_symbol(const ::std::string& value) {
  
  symbol_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.XTExecution.symbol)
}
 void XTExecution::set_symbol(const char* value) {
  
  symbol_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.XTExecution.symbol)
}
 void XTExecution::set_symbol(const char* value, size_t size) {
  
  symbol_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.XTExecution.symbol)
}
 ::std::string* XTExecution::mutable_symbol() {
  
  // @@protoc_insertion_point(field_mutable:messages.XTExecution.symbol)
  return symbol_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* XTExecution::release_symbol() {
  
  return symbol_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_allocated_symbol(::std::string* symbol) {
  if (symbol != NULL) {
    
  } else {
    
  }
  symbol_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), symbol);
  // @@protoc_insertion_point(field_set_allocated:messages.XTExecution.symbol)
}

// optional string side = 3;
void XTExecution::clear_side() {
  side_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& XTExecution::side() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.side)
  return side_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_side(const ::std::string& value) {
  
  side_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.XTExecution.side)
}
 void XTExecution::set_side(const char* value) {
  
  side_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.XTExecution.side)
}
 void XTExecution::set_side(const char* value, size_t size) {
  
  side_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.XTExecution.side)
}
 ::std::string* XTExecution::mutable_side() {
  
  // @@protoc_insertion_point(field_mutable:messages.XTExecution.side)
  return side_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* XTExecution::release_side() {
  
  return side_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_allocated_side(::std::string* side) {
  if (side != NULL) {
    
  } else {
    
  }
  side_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), side);
  // @@protoc_insertion_point(field_set_allocated:messages.XTExecution.side)
}

// optional string ord_type = 4;
void XTExecution::clear_ord_type() {
  ord_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& XTExecution::ord_type() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.ord_type)
  return ord_type_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_ord_type(const ::std::string& value) {
  
  ord_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.XTExecution.ord_type)
}
 void XTExecution::set_ord_type(const char* value) {
  
  ord_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.XTExecution.ord_type)
}
 void XTExecution::set_ord_type(const char* value, size_t size) {
  
  ord_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.XTExecution.ord_type)
}
 ::std::string* XTExecution::mutable_ord_type() {
  
  // @@protoc_insertion_point(field_mutable:messages.XTExecution.ord_type)
  return ord_type_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* XTExecution::release_ord_type() {
  
  return ord_type_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_allocated_ord_type(::std::string* ord_type) {
  if (ord_type != NULL) {
    
  } else {
    
  }
  ord_type_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ord_type);
  // @@protoc_insertion_point(field_set_allocated:messages.XTExecution.ord_type)
}

// optional uint32 quantity = 5;
void XTExecution::clear_quantity() {
  quantity_ = 0u;
}
 ::google::protobuf::uint32 XTExecution::quantity() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.quantity)
  return quantity_;
}
 void XTExecution::set_quantity(::google::protobuf::uint32 value) {
  
  quantity_ = value;
  // @@protoc_insertion_point(field_set:messages.XTExecution.quantity)
}

// optional uint32 price = 6;
void XTExecution::clear_price() {
  price_ = 0u;
}
 ::google::protobuf::uint32 XTExecution::price() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.price)
  return price_;
}
 void XTExecution::set_price(::google::protobuf::uint32 value) {
  
  price_ = value;
  // @@protoc_insertion_point(field_set:messages.XTExecution.price)
}

// optional string ord_status = 7;
void XTExecution::clear_ord_status() {
  ord_status_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& XTExecution::ord_status() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.ord_status)
  return ord_status_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_ord_status(const ::std::string& value) {
  
  ord_status_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.XTExecution.ord_status)
}
 void XTExecution::set_ord_status(const char* value) {
  
  ord_status_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.XTExecution.ord_status)
}
 void XTExecution::set_ord_status(const char* value, size_t size) {
  
  ord_status_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.XTExecution.ord_status)
}
 ::std::string* XTExecution::mutable_ord_status() {
  
  // @@protoc_insertion_point(field_mutable:messages.XTExecution.ord_status)
  return ord_status_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* XTExecution::release_ord_status() {
  
  return ord_status_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_allocated_ord_status(::std::string* ord_status) {
  if (ord_status != NULL) {
    
  } else {
    
  }
  ord_status_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ord_status);
  // @@protoc_insertion_point(field_set_allocated:messages.XTExecution.ord_status)
}

// optional string exec_type = 8;
void XTExecution::clear_exec_type() {
  exec_type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& XTExecution::exec_type() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.exec_type)
  return exec_type_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_exec_type(const ::std::string& value) {
  
  exec_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:messages.XTExecution.exec_type)
}
 void XTExecution::set_exec_type(const char* value) {
  
  exec_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:messages.XTExecution.exec_type)
}
 void XTExecution::set_exec_type(const char* value, size_t size) {
  
  exec_type_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:messages.XTExecution.exec_type)
}
 ::std::string* XTExecution::mutable_exec_type() {
  
  // @@protoc_insertion_point(field_mutable:messages.XTExecution.exec_type)
  return exec_type_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* XTExecution::release_exec_type() {
  
  return exec_type_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void XTExecution::set_allocated_exec_type(::std::string* exec_type) {
  if (exec_type != NULL) {
    
  } else {
    
  }
  exec_type_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), exec_type);
  // @@protoc_insertion_point(field_set_allocated:messages.XTExecution.exec_type)
}

// optional uint32 last_qty = 9;
void XTExecution::clear_last_qty() {
  last_qty_ = 0u;
}
 ::google::protobuf::uint32 XTExecution::last_qty() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.last_qty)
  return last_qty_;
}
 void XTExecution::set_last_qty(::google::protobuf::uint32 value) {
  
  last_qty_ = value;
  // @@protoc_insertion_point(field_set:messages.XTExecution.last_qty)
}

// optional uint32 last_price = 10;
void XTExecution::clear_last_price() {
  last_price_ = 0u;
}
 ::google::protobuf::uint32 XTExecution::last_price() const {
  // @@protoc_insertion_point(field_get:messages.XTExecution.last_price)
  return last_price_;
}
 void XTExecution::set_last_price(::google::protobuf::uint32 value) {
  
  last_price_ = value;
  // @@protoc_insertion_point(field_set:messages.XTExecution.last_price)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace messages

// @@protoc_insertion_point(global_scope)