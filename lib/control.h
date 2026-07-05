#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

static js_value_t *
bare_app_kit_control_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.enabled, &result);
      assert(err == 0);
    } else {
      bool enabled;
      err = js_get_value_bool(env, argv[1], &enabled);
      assert(err == 0);

      control.enabled = enabled;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_continuous(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.continuous, &result);
      assert(err == 0);
    } else {
      bool continuous;
      err = js_get_value_bool(env, argv[1], &continuous);
      assert(err == 0);

      control.continuous = continuous;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_ignores_multi_click(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.ignoresMultiClick, &result);
      assert(err == 0);
    } else {
      bool ignores_multi_click;
      err = js_get_value_bool(env, argv[1], &ignores_multi_click);
      assert(err == 0);

      control.ignoresMultiClick = ignores_multi_click;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_highlighted(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.highlighted, &result);
      assert(err == 0);
    } else {
      bool highlighted;
      err = js_get_value_bool(env, argv[1], &highlighted);
      assert(err == 0);

      control.highlighted = highlighted;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_refuses_first_responder(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.refusesFirstResponder, &result);
      assert(err == 0);
    } else {
      bool refuses_first_responder;
      err = js_get_value_bool(env, argv[1], &refuses_first_responder);
      assert(err == 0);

      control.refusesFirstResponder = refuses_first_responder;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_tag(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int64(env, control.tag, &result);
      assert(err == 0);
    } else {
      int64_t tag;
      err = js_get_value_int64(env, argv[1], &tag);
      assert(err == 0);

      control.tag = tag;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_size(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, control.controlSize, &result);
      assert(err == 0);
    } else {
      int32_t control_size;
      err = js_get_value_int32(env, argv[1], &control_size);
      assert(err == 0);

      control.controlSize = control_size;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_string_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      NSString *value = control.stringValue;

      err = js_create_string_utf8(env, (const utf8_t *) [value UTF8String], -1, &result);
      assert(err == 0);
    } else {
      size_t len;
      err = js_get_value_string_utf8(env, argv[1], NULL, 0, &len);
      assert(err == 0);

      len += 1 /* NULL */;

      char *value = malloc(len);

      err = js_get_value_string_utf8(env, argv[1], (utf8_t *) value, len, &len);
      assert(err == 0);

      control.stringValue = [NSString stringWithUTF8String:value];

      free(value);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_int_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, control.intValue, &result);
      assert(err == 0);
    } else {
      int32_t value;
      err = js_get_value_int32(env, argv[1], &value);
      assert(err == 0);

      control.intValue = value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_integer_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int64(env, control.integerValue, &result);
      assert(err == 0);
    } else {
      int64_t value;
      err = js_get_value_int64(env, argv[1], &value);
      assert(err == 0);

      control.integerValue = value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_float_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_double(env, control.floatValue, &result);
      assert(err == 0);
    } else {
      double value;
      err = js_get_value_double(env, argv[1], &value);
      assert(err == 0);

      control.floatValue = value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_double_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_double(env, control.doubleValue, &result);
      assert(err == 0);
    } else {
      double value;
      err = js_get_value_double(env, argv[1], &value);
      assert(err == 0);

      control.doubleValue = value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_size_to_fit(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    [control sizeToFit];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_control_perform_click(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    [control performClick:nil];
  }

  return NULL;
}
