const binding = require('../binding')
const AppKitView = require('./view')

module.exports = exports = class AppKitControl extends AppKitView {
  constructor(handle = null) {
    super(handle)

    if (new.target === AppKitControl) {
      throw new TypeError('Control cannot be instantiated directly')
    }
  }

  get enabled() {
    return binding.controlEnabled(this._handle)
  }

  set enabled(enabled) {
    binding.controlEnabled(this._handle, enabled)
  }

  get continuous() {
    return binding.controlContinuous(this._handle)
  }

  set continuous(continuous) {
    binding.controlContinuous(this._handle, continuous)
  }

  get ignoresMultiClick() {
    return binding.controlIgnoresMultiClick(this._handle)
  }

  set ignoresMultiClick(ignoresMultiClick) {
    binding.controlIgnoresMultiClick(this._handle, ignoresMultiClick)
  }

  get highlighted() {
    return binding.controlHighlighted(this._handle)
  }

  set highlighted(highlighted) {
    binding.controlHighlighted(this._handle, highlighted)
  }

  get refusesFirstResponder() {
    return binding.controlRefusesFirstResponder(this._handle)
  }

  set refusesFirstResponder(refusesFirstResponder) {
    binding.controlRefusesFirstResponder(this._handle, refusesFirstResponder)
  }

  get tag() {
    return binding.controlTag(this._handle)
  }

  set tag(tag) {
    binding.controlTag(this._handle, tag)
  }

  get controlSize() {
    return binding.controlSize(this._handle)
  }

  set controlSize(controlSize) {
    binding.controlSize(this._handle, controlSize)
  }

  get stringValue() {
    return binding.controlStringValue(this._handle)
  }

  set stringValue(value) {
    binding.controlStringValue(this._handle, value)
  }

  get intValue() {
    return binding.controlIntValue(this._handle)
  }

  set intValue(value) {
    binding.controlIntValue(this._handle, value)
  }

  get integerValue() {
    return binding.controlIntegerValue(this._handle)
  }

  set integerValue(value) {
    binding.controlIntegerValue(this._handle, value)
  }

  get floatValue() {
    return binding.controlFloatValue(this._handle)
  }

  set floatValue(value) {
    binding.controlFloatValue(this._handle, value)
  }

  get doubleValue() {
    return binding.controlDoubleValue(this._handle)
  }

  set doubleValue(value) {
    binding.controlDoubleValue(this._handle, value)
  }

  sizeToFit() {
    binding.controlSizeToFit(this._handle)
    return this
  }

  performClick() {
    binding.controlPerformClick(this._handle)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitControl }
    }
  }
}

exports.SIZE = {
  REGULAR: binding.CONTROL_SIZE_REGULAR,
  SMALL: binding.CONTROL_SIZE_SMALL,
  MINI: binding.CONTROL_SIZE_MINI,
  LARGE: binding.CONTROL_SIZE_LARGE
}

exports.STATE = {
  MIXED: binding.CONTROL_STATE_MIXED,
  OFF: binding.CONTROL_STATE_OFF,
  ON: binding.CONTROL_STATE_ON
}
