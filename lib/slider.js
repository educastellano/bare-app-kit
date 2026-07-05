const binding = require('../binding')
const AppKitControl = require('./control')

module.exports = exports = class AppKitSlider extends AppKitControl {
  constructor(opts = {}) {
    super()

    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._handle = binding.sliderInit(x, y, width, height, this, this._onchange)
  }

  get minValue() {
    return binding.sliderMinValue(this._handle)
  }

  set minValue(minValue) {
    binding.sliderMinValue(this._handle, minValue)
  }

  get maxValue() {
    return binding.sliderMaxValue(this._handle)
  }

  set maxValue(maxValue) {
    binding.sliderMaxValue(this._handle, maxValue)
  }

  get altIncrementValue() {
    return binding.sliderAltIncrementValue(this._handle)
  }

  set altIncrementValue(altIncrementValue) {
    binding.sliderAltIncrementValue(this._handle, altIncrementValue)
  }

  get knobThickness() {
    return binding.sliderKnobThickness(this._handle)
  }

  get vertical() {
    return binding.sliderVertical(this._handle)
  }

  set vertical(vertical) {
    binding.sliderVertical(this._handle, vertical)
  }

  get sliderType() {
    return binding.sliderType(this._handle)
  }

  set sliderType(sliderType) {
    binding.sliderType(this._handle, sliderType)
  }

  get numberOfTickMarks() {
    return binding.sliderNumberOfTickMarks(this._handle)
  }

  set numberOfTickMarks(numberOfTickMarks) {
    binding.sliderNumberOfTickMarks(this._handle, numberOfTickMarks)
  }

  get tickMarkPosition() {
    return binding.sliderTickMarkPosition(this._handle)
  }

  set tickMarkPosition(tickMarkPosition) {
    binding.sliderTickMarkPosition(this._handle, tickMarkPosition)
  }

  get allowsTickMarkValuesOnly() {
    return binding.sliderAllowsTickMarkValuesOnly(this._handle)
  }

  set allowsTickMarkValuesOnly(allowsTickMarkValuesOnly) {
    binding.sliderAllowsTickMarkValuesOnly(this._handle, allowsTickMarkValuesOnly)
  }

  tickMarkValueAtIndex(index) {
    return binding.sliderTickMarkValueAtIndex(this._handle, index)
  }

  closestTickMarkValueToValue(value) {
    return binding.sliderClosestTickMarkValueToValue(this._handle, value)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSlider }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports.TYPE = {
  LINEAR: binding.SLIDER_TYPE_LINEAR,
  CIRCULAR: binding.SLIDER_TYPE_CIRCULAR
}

exports.TICK_MARK_POSITION = {
  BELOW: binding.TICK_MARK_POSITION_BELOW,
  ABOVE: binding.TICK_MARK_POSITION_ABOVE,
  LEADING: binding.TICK_MARK_POSITION_LEADING,
  TRAILING: binding.TICK_MARK_POSITION_TRAILING
}
