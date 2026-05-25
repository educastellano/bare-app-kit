#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareButton : NSButton {
@public
  js_env_t *env;
  js_ref_t *ctx;
  js_ref_t *on_mouse_down;
  js_ref_t *on_mouse_up;
  js_ref_t *on_click;
}

@end

@implementation BareButton

- (void)dealloc {
  int err; 

  err = js_delete_reference(env, on_mouse_down);
  assert(err == 0);

  err = js_delete_reference(env, on_mouse_up);
  assert(err == 0);

  err = js_delete_reference(env, on_click);
  assert(err == 0);

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (void)mouseDown:(NSEvent *)event {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  js_value_t *callback;
  err = js_get_reference_value(env, on_mouse_down, &callback);
  assert(err == 0);

  err = js_call_function(env, receiver, callback, 0, NULL, NULL);
  (void) err;

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  [super mouseDown:event];

  // NSButton handles the full press/release cycle inside mouseDown,
  // so a mouseUp override is not called. Custom mouse tracking
  // would be needed to expose the original mouseUp event data, and
  // the correct order of events (currently click happens before mouseUp).
  [self mouseUpSynthetic];
}

- (void)mouseUpSynthetic {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  js_value_t *callback;
  err = js_get_reference_value(env, on_mouse_up, &callback);
  assert(err == 0);

  err = js_call_function(env, receiver, callback, 0, NULL, NULL);
  (void) err;

  err = js_close_handle_scope(env, scope);
  assert(err == 0);
}

- (void)onClick:(id)sender {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  js_value_t *callback;
  err = js_get_reference_value(env, on_click, &callback);
  assert(err == 0);

  err = js_call_function(env, receiver, callback, 0, NULL, NULL);
  (void) err;

  err = js_close_handle_scope(env, scope);
  assert(err == 0);
}

@end

static js_value_t *
bare_app_kit_button_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 8;
  js_value_t *argv[8];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 8);

  double x;
  err = js_get_value_double(env, argv[0], &x);
  assert(err == 0);

  double y;
  err = js_get_value_double(env, argv[1], &y);
  assert(err == 0);

  double width;
  err = js_get_value_double(env, argv[2], &width);
  assert(err == 0);

  double height;
  err = js_get_value_double(env, argv[3], &height);
  assert(err == 0);

  js_value_t *result;

  @autoreleasepool {
    BareButton *handle = [[BareButton alloc]
      initWithFrame:NSMakeRect(x, y, width, height)];

    err = js_create_external(env, (void *) CFBridgingRetain(handle), bare_app_kit__on_bridged_release, NULL, &result);
    assert(err == 0);

    handle->env = env;

    err = js_create_reference(env, argv[4], 1, &handle->ctx);
    assert(err == 0);

    err = js_create_reference(env, argv[5], 1, &handle->on_mouse_down);
    assert(err == 0);

    err = js_create_reference(env, argv[6], 1, &handle->on_mouse_up);
    assert(err == 0);

    err = js_create_reference(env, argv[7], 1, &handle->on_click);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onClick:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_button_get_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    NSString *title = [button title];

    err = js_create_string_utf8(env, (const utf8_t *) [title UTF8String], -1, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_button_set_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  size_t len;
  err = js_get_value_string_utf8(env, argv[1], NULL, 0, &len);
  assert(err == 0);

  len += 1 /* NULL */;

  char *title = malloc(len);

  err = js_get_value_string_utf8(env, argv[1], (utf8_t *) title, len, &len);
  assert(err == 0);

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button setTitle:[NSString stringWithUTF8String:title]];
  }

  return NULL;
}
