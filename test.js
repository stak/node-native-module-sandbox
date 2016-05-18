const assert = require('assert');
const addon = require('bindings')('addAsync');

assert.equal(addon.hello(), "world");
