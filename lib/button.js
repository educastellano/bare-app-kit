const binding = require('../binding')
const AppKitControl = require('./control')

module.exports = exports = class AppKitButton extends AppKitControl {
  constructor(opts = {}) {
    super()

    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._handle = binding.buttonInit(x, y, width, height, this, this._onmousedown, this._onclick)
  }

  get title() {
    return binding.buttonTitle(this._handle)
  }

  set title(title) {
    binding.buttonTitle(this._handle, title)
  }

  get alternateTitle() {
    return binding.buttonAlternateTitle(this._handle)
  }

  set alternateTitle(alternateTitle) {
    binding.buttonAlternateTitle(this._handle, alternateTitle)
  }

  get state() {
    return binding.buttonState(this._handle)
  }

  set state(state) {
    binding.buttonState(this._handle, state)
  }

  get allowsMixedState() {
    return binding.buttonAllowsMixedState(this._handle)
  }

  set allowsMixedState(allowsMixedState) {
    binding.buttonAllowsMixedState(this._handle, allowsMixedState)
  }

  get bezelStyle() {
    return binding.buttonBezelStyle(this._handle)
  }

  set bezelStyle(bezelStyle) {
    binding.buttonBezelStyle(this._handle, bezelStyle)
  }

  get bordered() {
    return binding.buttonBordered(this._handle)
  }

  set bordered(bordered) {
    binding.buttonBordered(this._handle, bordered)
  }

  get transparent() {
    return binding.buttonTransparent(this._handle)
  }

  set transparent(transparent) {
    binding.buttonTransparent(this._handle, transparent)
  }

  get showsBorderOnlyWhileMouseInside() {
    return binding.buttonShowsBorderOnlyWhileMouseInside(this._handle)
  }

  set showsBorderOnlyWhileMouseInside(showsBorderOnlyWhileMouseInside) {
    binding.buttonShowsBorderOnlyWhileMouseInside(this._handle, showsBorderOnlyWhileMouseInside)
  }

  get springLoaded() {
    return binding.buttonSpringLoaded(this._handle)
  }

  set springLoaded(springLoaded) {
    binding.buttonSpringLoaded(this._handle, springLoaded)
  }

  get hasDestructiveAction() {
    return binding.buttonHasDestructiveAction(this._handle)
  }

  set hasDestructiveAction(hasDestructiveAction) {
    binding.buttonHasDestructiveAction(this._handle, hasDestructiveAction)
  }

  get keyEquivalent() {
    return binding.buttonKeyEquivalent(this._handle)
  }

  set keyEquivalent(keyEquivalent) {
    binding.buttonKeyEquivalent(this._handle, keyEquivalent)
  }

  get keyEquivalentModifierMask() {
    return binding.buttonKeyEquivalentModifierMask(this._handle)
  }

  set keyEquivalentModifierMask(keyEquivalentModifierMask) {
    binding.buttonKeyEquivalentModifierMask(this._handle, keyEquivalentModifierMask)
  }

  setButtonType(type) {
    binding.buttonSetButtonType(this._handle, type)
    return this
  }

  setNextState() {
    binding.buttonSetNextState(this._handle)
    return this
  }

  highlight(flag) {
    binding.buttonHighlight(this._handle, flag)
    return this
  }

  setPeriodicDelay(delay, interval) {
    binding.buttonSetPeriodicDelay(this._handle, delay, interval)
    return this
  }

  getPeriodicDelay() {
    return binding.buttonGetPeriodicDelay(this._handle)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitButton }
    }
  }

  _onmousedown() {
    this.emit('mouseDown')
  }

  _onclick() {
    this.emit('click')
  }
}

exports.TYPE = {
  MOMENTARY_LIGHT: binding.BUTTON_TYPE_MOMENTARY_LIGHT,
  PUSH_ON_PUSH_OFF: binding.BUTTON_TYPE_PUSH_ON_PUSH_OFF,
  TOGGLE: binding.BUTTON_TYPE_TOGGLE,
  SWITCH: binding.BUTTON_TYPE_SWITCH,
  RADIO: binding.BUTTON_TYPE_RADIO,
  MOMENTARY_CHANGE: binding.BUTTON_TYPE_MOMENTARY_CHANGE,
  ON_OFF: binding.BUTTON_TYPE_ON_OFF,
  MOMENTARY_PUSH_IN: binding.BUTTON_TYPE_MOMENTARY_PUSH_IN,
  ACCELERATOR: binding.BUTTON_TYPE_ACCELERATOR,
  MULTI_LEVEL_ACCELERATOR: binding.BUTTON_TYPE_MULTI_LEVEL_ACCELERATOR
}

exports.BEZEL_STYLE = {
  PUSH: binding.BUTTON_BEZEL_STYLE_PUSH,
  FLEXIBLE_PUSH: binding.BUTTON_BEZEL_STYLE_FLEXIBLE_PUSH,
  DISCLOSURE: binding.BUTTON_BEZEL_STYLE_DISCLOSURE,
  CIRCULAR: binding.BUTTON_BEZEL_STYLE_CIRCULAR,
  HELP_BUTTON: binding.BUTTON_BEZEL_STYLE_HELP_BUTTON,
  SMALL_SQUARE: binding.BUTTON_BEZEL_STYLE_SMALL_SQUARE,
  TOOLBAR: binding.BUTTON_BEZEL_STYLE_TOOLBAR,
  ACCESSORY_BAR_ACTION: binding.BUTTON_BEZEL_STYLE_ACCESSORY_BAR_ACTION,
  ACCESSORY_BAR: binding.BUTTON_BEZEL_STYLE_ACCESSORY_BAR,
  PUSH_DISCLOSURE: binding.BUTTON_BEZEL_STYLE_PUSH_DISCLOSURE,
  BADGE: binding.BUTTON_BEZEL_STYLE_BADGE
}
