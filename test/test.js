const assert = require('assert');
const addon = require('bindings')('addAsync');

assert.equal(addon.add(1, 1), 2);
assert.equal(addon.add(3, 5), 8);
assert.equal(addon.add(-2, -3), -5);
assert.equal(addon.add(0, 0), 0);
