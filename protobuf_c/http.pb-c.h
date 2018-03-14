/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: http.proto */

#ifndef PROTOBUF_C_http_2eproto__INCLUDED
#define PROTOBUF_C_http_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _KismetExternalHttp__HttpAuthToken KismetExternalHttp__HttpAuthToken;
typedef struct _KismetExternalHttp__HttpRegisterUri KismetExternalHttp__HttpRegisterUri;
typedef struct _KismetExternalHttp__HttpRequest KismetExternalHttp__HttpRequest;
typedef struct _KismetExternalHttp__HttpRequest__PostDataEntry KismetExternalHttp__HttpRequest__PostDataEntry;
typedef struct _KismetExternalHttp__HttpResponse KismetExternalHttp__HttpResponse;
typedef struct _KismetExternalHttp__HttpResponse__HeaderContentEntry KismetExternalHttp__HttpResponse__HeaderContentEntry;


/* --- enums --- */


/* --- messages --- */

/*
 * Send a HTTP session auth token to the helper (Kismet->Helper)
 * This lets the helper access administrative functions on the server
 * without having to pass an actual login password
 */
struct  _KismetExternalHttp__HttpAuthToken
{
  ProtobufCMessage base;
  char *token;
};
#define KISMET_EXTERNAL_HTTP__HTTP_AUTH_TOKEN__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external_http__http_auth_token__descriptor) \
    , NULL }


/*
 * Define an endpoint (Helper->Kismet)
 * Registers a HTTP endpoint; requests to this endpoint will be sent to the
 * helper via the HttpRequest message, which will, in turn, expect replies
 * via the HttpResponse message.
 */
struct  _KismetExternalHttp__HttpRegisterUri
{
  ProtobufCMessage base;
  /*
   * Full URI, including file type; Helpers cannot take advantage of the Kismet
   * multi-serialization types so they must define a URI for each type
   */
  char *uri;
  /*
   * Method; ie GET or POST; a URI can only implement a single method and
   * must register multiple URIs for multiple methods.
   */
  char *method;
  /*
   * Authentication - does the URI require authentication?  The proxy can 
   * handle this automatically.
   */
  protobuf_c_boolean auth_required;
};
#define KISMET_EXTERNAL_HTTP__HTTP_REGISTER_URI__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external_http__http_register_uri__descriptor) \
    , NULL, NULL, 0 }


struct  _KismetExternalHttp__HttpRequest__PostDataEntry
{
  ProtobufCMessage base;
  char *key;
  char *value;
};
#define KISMET_EXTERNAL_HTTP__HTTP_REQUEST__POST_DATA_ENTRY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external_http__http_request__post_data_entry__descriptor) \
    , NULL, NULL }


/*
 * Handle an incoming HTTP request (Kismet->Helper)
 */
struct  _KismetExternalHttp__HttpRequest
{
  ProtobufCMessage base;
  /*
   * Unique ID of request, must be returned in the HttpResponse
   */
  uint32_t req_id;
  /*
   * Full URI of request
   */
  char *uri;
  /*
   * Method
   */
  char *method;
  /*
   * If post, a map of post variables
   */
  size_t n_post_data;
  KismetExternalHttp__HttpRequest__PostDataEntry **post_data;
};
#define KISMET_EXTERNAL_HTTP__HTTP_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external_http__http_request__descriptor) \
    , 0, NULL, NULL, 0,NULL }


struct  _KismetExternalHttp__HttpResponse__HeaderContentEntry
{
  ProtobufCMessage base;
  char *key;
  char *value;
};
#define KISMET_EXTERNAL_HTTP__HTTP_RESPONSE__HEADER_CONTENT_ENTRY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external_http__http_response__header_content_entry__descriptor) \
    , NULL, NULL }


/*
 * Respond to HTTP data (Helper->Kismet)
 */
struct  _KismetExternalHttp__HttpResponse
{
  ProtobufCMessage base;
  /*
   * Unique ID of request we're responding to
   */
  uint32_t req_id;
  /*
   * Headers being sent, if any
   */
  size_t n_header_content;
  KismetExternalHttp__HttpResponse__HeaderContentEntry **header_content;
  /*
   * Content being sent, if any
   */
  protobuf_c_boolean has_content;
  ProtobufCBinaryData content;
  /*
   * Result code, if we're concluding this connection
   */
  protobuf_c_boolean has_resultcode;
  uint32_t resultcode;
  /*
   * Is this the end of this connection?
   */
  protobuf_c_boolean has_close_response;
  protobuf_c_boolean close_response;
};
#define KISMET_EXTERNAL_HTTP__HTTP_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external_http__http_response__descriptor) \
    , 0, 0,NULL, 0,{0,NULL}, 0,0, 0,0 }


/* KismetExternalHttp__HttpAuthToken methods */
void   kismet_external_http__http_auth_token__init
                     (KismetExternalHttp__HttpAuthToken         *message);
size_t kismet_external_http__http_auth_token__get_packed_size
                     (const KismetExternalHttp__HttpAuthToken   *message);
size_t kismet_external_http__http_auth_token__pack
                     (const KismetExternalHttp__HttpAuthToken   *message,
                      uint8_t             *out);
size_t kismet_external_http__http_auth_token__pack_to_buffer
                     (const KismetExternalHttp__HttpAuthToken   *message,
                      ProtobufCBuffer     *buffer);
KismetExternalHttp__HttpAuthToken *
       kismet_external_http__http_auth_token__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external_http__http_auth_token__free_unpacked
                     (KismetExternalHttp__HttpAuthToken *message,
                      ProtobufCAllocator *allocator);
/* KismetExternalHttp__HttpRegisterUri methods */
void   kismet_external_http__http_register_uri__init
                     (KismetExternalHttp__HttpRegisterUri         *message);
size_t kismet_external_http__http_register_uri__get_packed_size
                     (const KismetExternalHttp__HttpRegisterUri   *message);
size_t kismet_external_http__http_register_uri__pack
                     (const KismetExternalHttp__HttpRegisterUri   *message,
                      uint8_t             *out);
size_t kismet_external_http__http_register_uri__pack_to_buffer
                     (const KismetExternalHttp__HttpRegisterUri   *message,
                      ProtobufCBuffer     *buffer);
KismetExternalHttp__HttpRegisterUri *
       kismet_external_http__http_register_uri__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external_http__http_register_uri__free_unpacked
                     (KismetExternalHttp__HttpRegisterUri *message,
                      ProtobufCAllocator *allocator);
/* KismetExternalHttp__HttpRequest__PostDataEntry methods */
void   kismet_external_http__http_request__post_data_entry__init
                     (KismetExternalHttp__HttpRequest__PostDataEntry         *message);
/* KismetExternalHttp__HttpRequest methods */
void   kismet_external_http__http_request__init
                     (KismetExternalHttp__HttpRequest         *message);
size_t kismet_external_http__http_request__get_packed_size
                     (const KismetExternalHttp__HttpRequest   *message);
size_t kismet_external_http__http_request__pack
                     (const KismetExternalHttp__HttpRequest   *message,
                      uint8_t             *out);
size_t kismet_external_http__http_request__pack_to_buffer
                     (const KismetExternalHttp__HttpRequest   *message,
                      ProtobufCBuffer     *buffer);
KismetExternalHttp__HttpRequest *
       kismet_external_http__http_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external_http__http_request__free_unpacked
                     (KismetExternalHttp__HttpRequest *message,
                      ProtobufCAllocator *allocator);
/* KismetExternalHttp__HttpResponse__HeaderContentEntry methods */
void   kismet_external_http__http_response__header_content_entry__init
                     (KismetExternalHttp__HttpResponse__HeaderContentEntry         *message);
/* KismetExternalHttp__HttpResponse methods */
void   kismet_external_http__http_response__init
                     (KismetExternalHttp__HttpResponse         *message);
size_t kismet_external_http__http_response__get_packed_size
                     (const KismetExternalHttp__HttpResponse   *message);
size_t kismet_external_http__http_response__pack
                     (const KismetExternalHttp__HttpResponse   *message,
                      uint8_t             *out);
size_t kismet_external_http__http_response__pack_to_buffer
                     (const KismetExternalHttp__HttpResponse   *message,
                      ProtobufCBuffer     *buffer);
KismetExternalHttp__HttpResponse *
       kismet_external_http__http_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external_http__http_response__free_unpacked
                     (KismetExternalHttp__HttpResponse *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*KismetExternalHttp__HttpAuthToken_Closure)
                 (const KismetExternalHttp__HttpAuthToken *message,
                  void *closure_data);
typedef void (*KismetExternalHttp__HttpRegisterUri_Closure)
                 (const KismetExternalHttp__HttpRegisterUri *message,
                  void *closure_data);
typedef void (*KismetExternalHttp__HttpRequest__PostDataEntry_Closure)
                 (const KismetExternalHttp__HttpRequest__PostDataEntry *message,
                  void *closure_data);
typedef void (*KismetExternalHttp__HttpRequest_Closure)
                 (const KismetExternalHttp__HttpRequest *message,
                  void *closure_data);
typedef void (*KismetExternalHttp__HttpResponse__HeaderContentEntry_Closure)
                 (const KismetExternalHttp__HttpResponse__HeaderContentEntry *message,
                  void *closure_data);
typedef void (*KismetExternalHttp__HttpResponse_Closure)
                 (const KismetExternalHttp__HttpResponse *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor kismet_external_http__http_auth_token__descriptor;
extern const ProtobufCMessageDescriptor kismet_external_http__http_register_uri__descriptor;
extern const ProtobufCMessageDescriptor kismet_external_http__http_request__descriptor;
extern const ProtobufCMessageDescriptor kismet_external_http__http_request__post_data_entry__descriptor;
extern const ProtobufCMessageDescriptor kismet_external_http__http_response__descriptor;
extern const ProtobufCMessageDescriptor kismet_external_http__http_response__header_content_entry__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_http_2eproto__INCLUDED */
