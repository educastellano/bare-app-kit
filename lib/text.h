#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_text_init(js_env_t *env, js_callback_info_t *info) {
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
    NSText *handle = [[NSText alloc]
      initWithFrame:NSMakeRect(x, y, width, height)];

    err = js_create_external(env, (void *) CFBridgingRetain(handle), bare_app_kit__on_bridged_release, NULL, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_text_string(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_create_string_utf8(env, (const utf8_t *) [text.string UTF8String], -1, &result);
      assert(err == 0);
    } else {
      size_t len;
      err = js_get_value_string_utf8(env, argv[1], NULL, 0, &len);
      assert(err == 0);

      len += 1 /* NULL */;

      char *string = malloc(len);

      err = js_get_value_string_utf8(env, argv[1], (utf8_t *) string, len, &len);
      assert(err == 0);

      text.string = [NSString stringWithUTF8String:string];

      free(string);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_editable(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.editable, &result);
      assert(err == 0);
    } else {
      bool editable;
      err = js_get_value_bool(env, argv[1], &editable);
      assert(err == 0);

      text.editable = editable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_selectable(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.selectable, &result);
      assert(err == 0);
    } else {
      bool selectable;
      err = js_get_value_bool(env, argv[1], &selectable);
      assert(err == 0);

      text.selectable = selectable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_rich_text(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.richText, &result);
      assert(err == 0);
    } else {
      bool rich_text;
      err = js_get_value_bool(env, argv[1], &rich_text);
      assert(err == 0);

      text.richText = rich_text;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_imports_graphics(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.importsGraphics, &result);
      assert(err == 0);
    } else {
      bool imports_graphics;
      err = js_get_value_bool(env, argv[1], &imports_graphics);
      assert(err == 0);

      text.importsGraphics = imports_graphics;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_editor(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.fieldEditor, &result);
      assert(err == 0);
    } else {
      bool field_editor;
      err = js_get_value_bool(env, argv[1], &field_editor);
      assert(err == 0);

      text.fieldEditor = field_editor;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_uses_font_panel(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.usesFontPanel, &result);
      assert(err == 0);
    } else {
      bool uses_font_panel;
      err = js_get_value_bool(env, argv[1], &uses_font_panel);
      assert(err == 0);

      text.usesFontPanel = uses_font_panel;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_draws_background(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.drawsBackground, &result);
      assert(err == 0);
    } else {
      bool draws_background;
      err = js_get_value_bool(env, argv[1], &draws_background);
      assert(err == 0);

      text.drawsBackground = draws_background;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_ruler_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    err = js_get_boolean(env, text.rulerVisible, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_text_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_create_int64(env, text.alignment, &result);
      assert(err == 0);
    } else {
      int64_t alignment;
      err = js_get_value_int64(env, argv[1], &alignment);
      assert(err == 0);

      text.alignment = (NSTextAlignment) alignment;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_base_writing_direction(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_create_int64(env, text.baseWritingDirection, &result);
      assert(err == 0);
    } else {
      int64_t base_writing_direction;
      err = js_get_value_int64(env, argv[1], &base_writing_direction);
      assert(err == 0);

      text.baseWritingDirection = (NSWritingDirection) base_writing_direction;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_copy(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    [text copy:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_cut(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    [text cut:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_delete(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    [text delete:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_paste(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    [text paste:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_select_all(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    [text selectAll:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_size_to_fit(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    [text sizeToFit];
  }

  return NULL;
}
