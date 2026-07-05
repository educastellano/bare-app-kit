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
  js_ref_t *on_click;
}

@end

@implementation BareButton

- (void)dealloc {
  int err; 

  err = js_delete_reference(env, on_mouse_down);
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

  size_t argc = 7;
  js_value_t *argv[7];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 7);

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

    err = js_create_reference(env, argv[6], 1, &handle->on_click);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onClick:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_button_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      NSString *title = [button title];

      err = js_create_string_utf8(env, (const utf8_t *) [title UTF8String], -1, &result);
      assert(err == 0);
    } else {
      size_t len;
      err = js_get_value_string_utf8(env, argv[1], NULL, 0, &len);
      assert(err == 0);

      len += 1 /* NULL */;

      char *title = malloc(len);

      err = js_get_value_string_utf8(env, argv[1], (utf8_t *) title, len, &len);
      assert(err == 0);

      [button setTitle:[NSString stringWithUTF8String:title]];

      free(title);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_alternate_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      NSString *alternate_title = [button alternateTitle];

      err = js_create_string_utf8(env, (const utf8_t *) [alternate_title UTF8String], -1, &result);
      assert(err == 0);
    } else {
      size_t len;
      err = js_get_value_string_utf8(env, argv[1], NULL, 0, &len);
      assert(err == 0);

      len += 1 /* NULL */;

      char *alternate_title = malloc(len);

      err = js_get_value_string_utf8(env, argv[1], (utf8_t *) alternate_title, len, &len);
      assert(err == 0);

      [button setAlternateTitle:[NSString stringWithUTF8String:alternate_title]];

      free(alternate_title);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_state(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, button.state, &result);
      assert(err == 0);
    } else {
      int32_t state;
      err = js_get_value_int32(env, argv[1], &state);
      assert(err == 0);

      button.state = state;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_allows_mixed_state(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.allowsMixedState, &result);
      assert(err == 0);
    } else {
      bool allows_mixed_state;
      err = js_get_value_bool(env, argv[1], &allows_mixed_state);
      assert(err == 0);

      button.allowsMixedState = allows_mixed_state;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_bezel_style(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, button.bezelStyle, &result);
      assert(err == 0);
    } else {
      int32_t bezel_style;
      err = js_get_value_int32(env, argv[1], &bezel_style);
      assert(err == 0);

      button.bezelStyle = bezel_style;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_bordered(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.bordered, &result);
      assert(err == 0);
    } else {
      bool bordered;
      err = js_get_value_bool(env, argv[1], &bordered);
      assert(err == 0);

      button.bordered = bordered;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_transparent(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.transparent, &result);
      assert(err == 0);
    } else {
      bool transparent;
      err = js_get_value_bool(env, argv[1], &transparent);
      assert(err == 0);

      button.transparent = transparent;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_shows_border_only_while_mouse_inside(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.showsBorderOnlyWhileMouseInside, &result);
      assert(err == 0);
    } else {
      bool shows_border_only_while_mouse_inside;
      err = js_get_value_bool(env, argv[1], &shows_border_only_while_mouse_inside);
      assert(err == 0);

      button.showsBorderOnlyWhileMouseInside = shows_border_only_while_mouse_inside;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_spring_loaded(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.springLoaded, &result);
      assert(err == 0);
    } else {
      bool spring_loaded;
      err = js_get_value_bool(env, argv[1], &spring_loaded);
      assert(err == 0);

      button.springLoaded = spring_loaded;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_has_destructive_action(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.hasDestructiveAction, &result);
      assert(err == 0);
    } else {
      bool has_destructive_action;
      err = js_get_value_bool(env, argv[1], &has_destructive_action);
      assert(err == 0);

      button.hasDestructiveAction = has_destructive_action;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_key_equivalent(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      NSString *key_equivalent = button.keyEquivalent;

      err = js_create_string_utf8(env, (const utf8_t *) [key_equivalent UTF8String], -1, &result);
      assert(err == 0);
    } else {
      size_t len;
      err = js_get_value_string_utf8(env, argv[1], NULL, 0, &len);
      assert(err == 0);

      len += 1 /* NULL */;

      char *key_equivalent = malloc(len);

      err = js_get_value_string_utf8(env, argv[1], (utf8_t *) key_equivalent, len, &len);
      assert(err == 0);

      button.keyEquivalent = [NSString stringWithUTF8String:key_equivalent];

      free(key_equivalent);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_key_equivalent_modifier_mask(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  js_value_t *result = NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_create_int64(env, button.keyEquivalentModifierMask, &result);
      assert(err == 0);
    } else {
      int64_t key_equivalent_modifier_mask;
      err = js_get_value_int64(env, argv[1], &key_equivalent_modifier_mask);
      assert(err == 0);

      button.keyEquivalentModifierMask = key_equivalent_modifier_mask;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_set_button_type(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  int32_t type;
  err = js_get_value_int32(env, argv[1], &type);
  assert(err == 0);

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button setButtonType:type];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_button_set_periodic_delay(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  double delay;
  err = js_get_value_double(env, argv[1], &delay);
  assert(err == 0);

  double interval;
  err = js_get_value_double(env, argv[2], &interval);
  assert(err == 0);

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button setPeriodicDelay:delay interval:interval];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_button_get_periodic_delay(js_env_t *env, js_callback_info_t *info) {
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
  err = js_create_object(env, &result);
  assert(err == 0);

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    float delay;
    float interval;
    [button getPeriodicDelay:&delay interval:&interval];

    js_value_t *value;
    err = js_create_double(env, delay, &value);
    assert(err == 0);

    err = js_set_named_property(env, result, "delay", value);
    assert(err == 0);

    err = js_create_double(env, interval, &value);
    assert(err == 0);

    err = js_set_named_property(env, result, "interval", value);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_button_set_next_state(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button setNextState];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_button_highlight(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  bool flag;
  err = js_get_value_bool(env, argv[1], &flag);
  assert(err == 0);

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button highlight:flag];
  }

  return NULL;
}
