const binding = require('../binding')
const AppKitView = require('./view')

module.exports = exports = class AppKitText extends AppKitView {
  constructor(opts = {}) {
    super()

    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._handle = binding.textInit(x, y, width, height)
  }

  get string() {
    return binding.textString(this._handle)
  }

  set string(string) {
    binding.textString(this._handle, string)
  }

  get editable() {
    return binding.textEditable(this._handle)
  }

  set editable(editable) {
    binding.textEditable(this._handle, editable)
  }

  get selectable() {
    return binding.textSelectable(this._handle)
  }

  set selectable(selectable) {
    binding.textSelectable(this._handle, selectable)
  }

  get richText() {
    return binding.textRichText(this._handle)
  }

  set richText(richText) {
    binding.textRichText(this._handle, richText)
  }

  get importsGraphics() {
    return binding.textImportsGraphics(this._handle)
  }

  set importsGraphics(importsGraphics) {
    binding.textImportsGraphics(this._handle, importsGraphics)
  }

  get fieldEditor() {
    return binding.textFieldEditor(this._handle)
  }

  set fieldEditor(fieldEditor) {
    binding.textFieldEditor(this._handle, fieldEditor)
  }

  get usesFontPanel() {
    return binding.textUsesFontPanel(this._handle)
  }

  set usesFontPanel(usesFontPanel) {
    binding.textUsesFontPanel(this._handle, usesFontPanel)
  }

  get drawsBackground() {
    return binding.textDrawsBackground(this._handle)
  }

  set drawsBackground(drawsBackground) {
    binding.textDrawsBackground(this._handle, drawsBackground)
  }

  get rulerVisible() {
    return binding.textRulerVisible(this._handle)
  }

  get alignment() {
    return binding.textAlignment(this._handle)
  }

  set alignment(alignment) {
    binding.textAlignment(this._handle, alignment)
  }

  get baseWritingDirection() {
    return binding.textBaseWritingDirection(this._handle)
  }

  set baseWritingDirection(baseWritingDirection) {
    binding.textBaseWritingDirection(this._handle, baseWritingDirection)
  }

  sizeToFit() {
    binding.textSizeToFit(this._handle)
    return this
  }

  copy() {
    binding.textCopy(this._handle)
    return this
  }

  cut() {
    binding.textCut(this._handle)
    return this
  }

  paste() {
    binding.textPaste(this._handle)
    return this
  }

  delete() {
    binding.textDelete(this._handle)
    return this
  }

  selectAll() {
    binding.textSelectAll(this._handle)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitText }
    }
  }
}

exports.ALIGNMENT = {
  LEFT: binding.TEXT_ALIGNMENT_LEFT,
  RIGHT: binding.TEXT_ALIGNMENT_RIGHT,
  CENTER: binding.TEXT_ALIGNMENT_CENTER,
  JUSTIFIED: binding.TEXT_ALIGNMENT_JUSTIFIED,
  NATURAL: binding.TEXT_ALIGNMENT_NATURAL
}

exports.WRITING_DIRECTION = {
  NATURAL: binding.WRITING_DIRECTION_NATURAL,
  LEFT_TO_RIGHT: binding.WRITING_DIRECTION_LEFT_TO_RIGHT,
  RIGHT_TO_LEFT: binding.WRITING_DIRECTION_RIGHT_TO_LEFT
}
