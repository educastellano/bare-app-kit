const binding = require('../binding')
const AppKitControl = require('./control')

module.exports = exports = class AppKitTextField extends AppKitControl {
  constructor(opts = {}) {
    super()

    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._handle = binding.textFieldInit(x, y, width, height)
  }

  get placeholderString() {
    return binding.textFieldPlaceholderString(this._handle)
  }

  set placeholderString(placeholderString) {
    binding.textFieldPlaceholderString(this._handle, placeholderString)
  }

  get bordered() {
    return binding.textFieldBordered(this._handle)
  }

  set bordered(bordered) {
    binding.textFieldBordered(this._handle, bordered)
  }

  get bezeled() {
    return binding.textFieldBezeled(this._handle)
  }

  set bezeled(bezeled) {
    binding.textFieldBezeled(this._handle, bezeled)
  }

  get editable() {
    return binding.textFieldEditable(this._handle)
  }

  set editable(editable) {
    binding.textFieldEditable(this._handle, editable)
  }

  get selectable() {
    return binding.textFieldSelectable(this._handle)
  }

  set selectable(selectable) {
    binding.textFieldSelectable(this._handle, selectable)
  }

  get drawsBackground() {
    return binding.textFieldDrawsBackground(this._handle)
  }

  set drawsBackground(drawsBackground) {
    binding.textFieldDrawsBackground(this._handle, drawsBackground)
  }

  get bezelStyle() {
    return binding.textFieldBezelStyle(this._handle)
  }

  set bezelStyle(bezelStyle) {
    binding.textFieldBezelStyle(this._handle, bezelStyle)
  }

  get maximumNumberOfLines() {
    return binding.textFieldMaximumNumberOfLines(this._handle)
  }

  set maximumNumberOfLines(maximumNumberOfLines) {
    binding.textFieldMaximumNumberOfLines(this._handle, maximumNumberOfLines)
  }

  selectText() {
    binding.textFieldSelectText(this._handle)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTextField }
    }
  }
}

exports.BEZEL_STYLE = {
  SQUARE: binding.TEXT_FIELD_BEZEL_STYLE_SQUARE,
  ROUNDED: binding.TEXT_FIELD_BEZEL_STYLE_ROUNDED
}
