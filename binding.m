#import <assert.h>
#import <bare.h>
#import <js.h>
#import <utf.h>

#import <AppKit/AppKit.h>

#import "lib/button.h"
#import "lib/control.h"
#import "lib/window.h"

static js_value_t *
bare_app_kit_exports(js_env_t *env, js_value_t *exports) {
  int err;

#define V(name, fn) \
  { \
    js_value_t *val; \
    err = js_create_function(env, name, -1, fn, NULL, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("buttonInit", bare_app_kit_button_init)
  V("buttonGetTitle", bare_app_kit_button_get_title)
  V("buttonSetTitle", bare_app_kit_button_set_title)

  V("controlEnabled", bare_app_kit_control_enabled)
  V("controlContinuous", bare_app_kit_control_continuous)
  V("controlIgnoresMultiClick", bare_app_kit_control_ignores_multi_click)
  V("controlHighlighted", bare_app_kit_control_highlighted)
  V("controlRefusesFirstResponder", bare_app_kit_control_refuses_first_responder)
  V("controlTag", bare_app_kit_control_tag)
  V("controlSize", bare_app_kit_control_size)
  V("controlStringValue", bare_app_kit_control_string_value)
  V("controlIntValue", bare_app_kit_control_int_value)
  V("controlIntegerValue", bare_app_kit_control_integer_value)
  V("controlFloatValue", bare_app_kit_control_float_value)
  V("controlDoubleValue", bare_app_kit_control_double_value)
  V("controlSizeToFit", bare_app_kit_control_size_to_fit)
  V("controlPerformClick", bare_app_kit_control_perform_click)

  V("windowInit", bare_app_kit_window_init)
  V("windowContentView", bare_app_kit_window_content_view)
  V("windowTitlebarAppearsTransparent", bare_app_kit_window_titlebar_appears_transparent)
  V("windowCenter", bare_app_kit_window_center)
  V("windowClose", bare_app_kit_window_close)
  V("windowMakeKeyWindow", bare_app_kit_window_make_key_window)
  V("windowOrderBack", bare_app_kit_window_order_back)
  V("windowOrderFront", bare_app_kit_window_order_front)
#undef V

#define V(name, n) \
  { \
    js_value_t *val; \
    err = js_create_int32(env, n, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("WINDOW_STYLE_MASK_BORDERLESS", NSWindowStyleMaskBorderless)
  V("WINDOW_STYLE_MASK_TITLED", NSWindowStyleMaskTitled)
  V("WINDOW_STYLE_MASK_CLOSABLE", NSWindowStyleMaskClosable)
  V("WINDOW_STYLE_MASK_MINIATURIZABLE", NSWindowStyleMaskMiniaturizable)
  V("WINDOW_STYLE_MASK_RESIZABLE", NSWindowStyleMaskResizable)
  V("WINDOW_STYLE_MASK_FULL_SCREEN", NSWindowStyleMaskFullScreen)
  V("WINDOW_STYLE_MASK_FULL_SIZE_CONTENT_VIEW", NSWindowStyleMaskFullSizeContentView)

  V("CONTROL_SIZE_REGULAR", NSControlSizeRegular)
  V("CONTROL_SIZE_SMALL", NSControlSizeSmall)
  V("CONTROL_SIZE_MINI", NSControlSizeMini)
  V("CONTROL_SIZE_LARGE", NSControlSizeLarge)
#undef V

  return exports;
}

BARE_MODULE(bare_app_kit, bare_app_kit_exports)
