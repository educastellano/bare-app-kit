const binding = require('../binding')
const AppKitControl = require('./control')

module.exports = exports = class AppKitSwitch extends AppKitControl {
  constructor(opts = {}) {
    super()

    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._handle = binding.switchInit(x, y, width, height, this, this._onchange)
  }

  get state() {
    return binding.switchState(this._handle)
  }

  set state(state) {
    binding.switchState(this._handle, state)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSwitch }
    }
  }

  _onchange() {
    this.emit('change')
  }
}
