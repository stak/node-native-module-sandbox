const assert = require('assert');
const addon = require('bindings')('test.node');

assert.equal(addon.hello(), "world");
