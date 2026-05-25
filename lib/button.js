const EventEmitter = require('bare-events')
const binding = require('../binding')

module.exports = exports = class AppKitButton extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._handle = binding.buttonInit(x, y, width, height, this, this._onmousedown, this._onclick)
  }

  get title() {
    return binding.buttonGetTitle(this._handle)
  }

  set title(title) {
    binding.buttonSetTitle(this._handle, title)
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
