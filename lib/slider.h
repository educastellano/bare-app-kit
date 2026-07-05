#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareSlider : NSSlider {
@public
  js_env_t *env;
  js_ref_t *ctx;
  js_ref_t *on_change;
}

@end

@implementation BareSlider

- (void)dealloc {
  int err;

  err = js_delete_reference(env, on_change);
  assert(err == 0);

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (void)onChange:(id)sender {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  js_value_t *callback;
  err = js_get_reference_value(env, on_change, &callback);
  assert(err == 0);

  err = js_call_function(env, receiver, callback, 0, NULL, NULL);
  (void) err;

  err = js_close_handle_scope(env, scope);
  assert(err == 0);
}

@end

static js_value_t *
bare_app_kit_slider_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 6;
  js_value_t *argv[6];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 6);

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
    BareSlider *handle = [[BareSlider alloc]
      initWithFrame:NSMakeRect(x, y, width, height)];

    err = js_create_external(env, (void *) CFBridgingRetain(handle), bare_app_kit__on_bridged_release, NULL, &result);
    assert(err == 0);

    handle->env = env;

    err = js_create_reference(env, argv[4], 1, &handle->ctx);
    assert(err == 0);

    err = js_create_reference(env, argv[5], 1, &handle->on_change);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_min_value(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_double(env, slider.minValue, &result);
      assert(err == 0);
    } else {
      double min_value;
      err = js_get_value_double(env, argv[1], &min_value);
      assert(err == 0);

      slider.minValue = min_value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_max_value(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_double(env, slider.maxValue, &result);
      assert(err == 0);
    } else {
      double max_value;
      err = js_get_value_double(env, argv[1], &max_value);
      assert(err == 0);

      slider.maxValue = max_value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_alt_increment_value(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_double(env, slider.altIncrementValue, &result);
      assert(err == 0);
    } else {
      double alt_increment_value;
      err = js_get_value_double(env, argv[1], &alt_increment_value);
      assert(err == 0);

      slider.altIncrementValue = alt_increment_value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_knob_thickness(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    err = js_create_double(env, slider.knobThickness, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_vertical(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, slider.vertical, &result);
      assert(err == 0);
    } else {
      bool vertical;
      err = js_get_value_bool(env, argv[1], &vertical);
      assert(err == 0);

      slider.vertical = vertical;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_type(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_int32(env, slider.sliderType, &result);
      assert(err == 0);
    } else {
      int32_t slider_type;
      err = js_get_value_int32(env, argv[1], &slider_type);
      assert(err == 0);

      slider.sliderType = slider_type;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_number_of_tick_marks(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_int64(env, slider.numberOfTickMarks, &result);
      assert(err == 0);
    } else {
      int64_t number_of_tick_marks;
      err = js_get_value_int64(env, argv[1], &number_of_tick_marks);
      assert(err == 0);

      slider.numberOfTickMarks = number_of_tick_marks;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_tick_mark_position(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_int32(env, slider.tickMarkPosition, &result);
      assert(err == 0);
    } else {
      int32_t tick_mark_position;
      err = js_get_value_int32(env, argv[1], &tick_mark_position);
      assert(err == 0);

      slider.tickMarkPosition = tick_mark_position;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_allows_tick_mark_values_only(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, slider.allowsTickMarkValuesOnly, &result);
      assert(err == 0);
    } else {
      bool allows_tick_mark_values_only;
      err = js_get_value_bool(env, argv[1], &allows_tick_mark_values_only);
      assert(err == 0);

      slider.allowsTickMarkValuesOnly = allows_tick_mark_values_only;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_tick_mark_value_at_index(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  int64_t index;
  err = js_get_value_int64(env, argv[1], &index);
  assert(err == 0);

  js_value_t *result;

  @autoreleasepool {
    NSSlider *slider = (__bridge NSSlider *) handle;

    err = js_create_double(env, [slider tickMarkValueAtIndex:index], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_closest_tick_mark_value_to_value(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  err = js_get_value_external(env, argv[0], &handle);
  assert(err == 0);

  double value;
  err = js_get_value_double(env, argv[1], &value);
  assert(err == 0);

  js_value_t *result;

  @autoreleasepool {
    NSSlider *slider = (__bridge NSSlider *) handle;

    err = js_create_double(env, [slider closestTickMarkValueToValue:value], &result);
    assert(err == 0);
  }

  return result;
}
