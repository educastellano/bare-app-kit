#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_text_field_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

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
    NSTextField *handle = [[NSTextField alloc]
      initWithFrame:NSMakeRect(x, y, width, height)];

    err = js_create_external(env, (void *) CFBridgingRetain(handle), bare_app_kit__on_bridged_release, NULL, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_placeholder_string(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      NSString *placeholder_string = text_field.placeholderString;

      if (placeholder_string == nil) {
        err = js_get_null(env, &result);
        assert(err == 0);
      } else {
        err = js_create_string_utf8(env, (const utf8_t *) [placeholder_string UTF8String], -1, &result);
        assert(err == 0);
      }
    } else {
      size_t len;
      err = js_get_value_string_utf8(env, argv[1], NULL, 0, &len);
      assert(err == 0);

      len += 1 /* NULL */;

      char *placeholder_string = malloc(len);

      err = js_get_value_string_utf8(env, argv[1], (utf8_t *) placeholder_string, len, &len);
      assert(err == 0);

      text_field.placeholderString = [NSString stringWithUTF8String:placeholder_string];

      free(placeholder_string);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_bordered(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.bordered, &result);
      assert(err == 0);
    } else {
      bool bordered;
      err = js_get_value_bool(env, argv[1], &bordered);
      assert(err == 0);

      text_field.bordered = bordered;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_bezeled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.bezeled, &result);
      assert(err == 0);
    } else {
      bool bezeled;
      err = js_get_value_bool(env, argv[1], &bezeled);
      assert(err == 0);

      text_field.bezeled = bezeled;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_editable(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.editable, &result);
      assert(err == 0);
    } else {
      bool editable;
      err = js_get_value_bool(env, argv[1], &editable);
      assert(err == 0);

      text_field.editable = editable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_selectable(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.selectable, &result);
      assert(err == 0);
    } else {
      bool selectable;
      err = js_get_value_bool(env, argv[1], &selectable);
      assert(err == 0);

      text_field.selectable = selectable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_draws_background(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.drawsBackground, &result);
      assert(err == 0);
    } else {
      bool draws_background;
      err = js_get_value_bool(env, argv[1], &draws_background);
      assert(err == 0);

      text_field.drawsBackground = draws_background;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_bezel_style(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_create_int64(env, text_field.bezelStyle, &result);
      assert(err == 0);
    } else {
      int64_t bezel_style;
      err = js_get_value_int64(env, argv[1], &bezel_style);
      assert(err == 0);

      text_field.bezelStyle = (NSTextFieldBezelStyle) bezel_style;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_maximum_number_of_lines(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_create_int64(env, text_field.maximumNumberOfLines, &result);
      assert(err == 0);
    } else {
      int64_t maximum_number_of_lines;
      err = js_get_value_int64(env, argv[1], &maximum_number_of_lines);
      assert(err == 0);

      text_field.maximumNumberOfLines = maximum_number_of_lines;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_select_text(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    [text_field selectText:nil];
  }

  return NULL;
}
